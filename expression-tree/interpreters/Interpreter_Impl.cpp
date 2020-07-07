#include <iostream>
#include <memory>
#include <cctype>
#include <stack>

#include "interpreters/Interpreter_Impl.h"

// constructor
Interpreter_Context::Interpreter_Context ()
= default;

// destructor
Interpreter_Context::~Interpreter_Context ()
= default;

// return the value of a variable
int
Interpreter_Context::get (const std::string& variable) const {
  return map_.find(variable)->second;
}

// set the value of a variable
void
Interpreter_Context::set (const std::string& variable, int value) {
  map_[variable] = value;
}

// print all variables and their values
void
Interpreter_Context::print () const
{
  for (auto & i : map_)
    std::cout << i.first << "=" << i.second << "\n";
}

// clear all variables and their values
void
Interpreter_Context::reset ()
{
  map_.clear ();
}

Interpreter_Impl::Interpreter_Impl(const Interpreter_Context &context)
  : context_(context) {
}

Interpreter_Impl::~Interpreter_Impl() = default;

Expression_Tree 
Interpreter_Impl::interpret (const std::string &input) {
  context_.print ();

  std::unique_ptr<Expr> parse_tree (build_parse_tree(input));

  if (parse_tree.get() != nullptr) {
    optimize_parse_tree(parse_tree.get());
    return build_expression_tree(parse_tree.get());
  } else 
    return Expression_Tree(nullptr);
}

void
Interpreter_Impl::optimize_parse_tree(Expr *parse_tree) {
}

// constructor
In_Order_Interpreter::In_Order_Interpreter (const Interpreter_Context &context)
  : Interpreter_Impl (context) {
}

// destructor
In_Order_Interpreter::~In_Order_Interpreter ()
= default;

// method for checking if a character is a number
bool
In_Order_Interpreter::is_number (char input)
{
  return input >= '0' && input <= '9';
}

// method for checking if a character is a candidate
// for a part of a variable name
bool
In_Order_Interpreter::is_alphanumeric (char input)
{
  return (input >= 'a' && input <= 'z') 
    || (input >= 'A' && input <= 'Z') 
    || (input == '_') 
    || (input >= '0' && input <= '9');
}

// inserts a terminal into the parse tree
void
In_Order_Interpreter::terminal_insert (Expr *terminal,
                                       std::list<Expr *>& list) {
  if (!list.empty ()) {
    // Something exists in the list, so make this number the rightmost child

    Expr *symbol = list.back ();

    if (symbol) {
      // while there is a right child, continue down
      for (; symbol->right_; symbol = symbol->right_)
        continue;

      // symbol right will be this terminal and that's all we have
      // to do.
      symbol->right_ = terminal;
    }
  } else
    // a number appeared first
    list.push_back (terminal);
}

// inserts a variable (leaf node / number) into the parse tree
void
In_Order_Interpreter::variable_insert (const std::string &input,
                                       std::string::size_type &i,
                                       int & accumulated_precedence,
                                       std::list<Expr *>& list,
                                       Expr *& lastValidInput) {
  // merge all consecutive number chars into a single
  // Number_Expr symbol, eg '123' = int (123). Scope of j needs
  // to be outside of the for loop.

  std::string::size_type j = 1;

  for (; i + j <= input.length () && is_alphanumeric (input[i + j]); ++j)
    continue;

  // lookup the variable in the context

  int value = context_.get (input.substr (i,j));

  // make a Number_Expr out of the integer

  auto *number = new Number_Expr (value);
  number->add_precedence (accumulated_precedence);

  lastValidInput = number;

  // update i to the last character that was a number. the ++i will
  // update the i at the end of the loop to the next check.

  i += j - 1;

  precedence_insert (number, list);
}

// inserts a leaf node / number into the parse tree
void
In_Order_Interpreter::number_insert (const std::string &input,
                                     std::string::size_type &i,
                                     int & accumulated_precedence,
                                     std::list<Expr *>& list,
                                     Expr *& lastValidInput) {
  // merge all consecutive number chars into a single Number_Expr symbol,
  // eg '123' = int (123). Scope of j needs to be outside of the for
  // loop.

  std::string::size_type j = 1;

  for (; i + j <= input.length () && is_number (input[i + j]); ++j)
    continue;

  auto *number = new Number_Expr (input.substr (i, j));
  number->add_precedence (accumulated_precedence);

  lastValidInput = number;

  // update i to the last character that was a number. the ++i will
  // update the i at the end of the loop to the next check.

  i += j - 1;

  precedence_insert (number, list);
}

// inserts a multiplication or division into the parse tree
void 
In_Order_Interpreter::precedence_insert (Expr *op,
                                         std::list<Expr *>& list) {
  if (!list.empty ()) {
    // if last element was a number, then make that our left_

    Expr *parent = list.back ();
    Expr *child = parent->right_;

    if (child) {
      // while there is a child of parent, keep going down the right side
      for (; 
           child && child->precedence () < op->precedence ();
           child = child->right_)
        parent = child;
    }

    if (parent->precedence () < op->precedence ()) {

      // op left will be the old child. new parent child will be
      // the op. To allow infinite negations, we have to check for unary_operator.

      // **************** This is the culprit

      if (!op->left_)
        op->left_ = child;

      parent->right_ = op;
    } else {
      // this can be one of two things, either we are the same
      // precedence or we are less precedence than the parent.
      // this also means different things for unary ops. The
      // most recent unary op (negate) has a higher precedence

      if (dynamic_cast <Unary_Expr *> (op)) {
        for (; 
             child && child->precedence () == op->precedence ();
             child = child->right_)
          parent = child;

        // I can't think of a valid reason that parent->right_ would
        // be possible !0

        parent->right_ = op;
      } else {
        // everything else is evaluated the same. For instance, if
        // this is 5 * 4 / 2, and we currently have Mult (5,4) in the
        // list, we need to make parent our left child.

        op->left_ = parent;
        list.pop_back ();
        list.push_back (op);
      }
    }
  } else 
    list.push_back (op);
}

void
In_Order_Interpreter::main_loop (const std::string &input,
                                 std::string::size_type &i,
                                 Expr *& lastValidInput,
                                 bool & handled,
                                 int & accumulated_precedence,
                                 std::list<Expr *>& list) {
  handled = false;
  if (is_number (input[i])) {
    handled = true;
    // leaf node
    number_insert (input, i, accumulated_precedence, 
                   list, lastValidInput);
  } else if (is_alphanumeric (input[i])) {
    handled = true;
    // variable leaf node
    variable_insert (input, i, accumulated_precedence,
                     list, lastValidInput);
  } else if (input[i] == '+') {
    handled = true;
    // addition operation
    auto *op = new Add_Expr ();
    op->add_precedence (accumulated_precedence);

    lastValidInput = nullptr;

    // insert the op according to left-to-right relationships
    precedence_insert (op, list);
  } else if (input[i] == '-') {
    handled = true;

    Expr *op;
    // subtraction operation

      if (!lastValidInput) {
      // Negate_Expr
      op = new Negate_Expr ();
      op->add_precedence (accumulated_precedence);
    } else {
      // Subtract_Expr
      op = new Subtract_Expr ();
      op->add_precedence (accumulated_precedence);
    }
          
    lastValidInput = nullptr;

    // insert the op according to left-to-right relationships
    precedence_insert (op, list);

  } else if (input[i] == '*') {
    handled = true;
    // multiplication operation
    auto *op = new Multiply_Expr ();
    op->add_precedence (accumulated_precedence);
 
    lastValidInput = nullptr;

    // insert the op according to precedence relationships
    precedence_insert (op, list);
    //associative_insert (op);
  } else if (input[i] == '/') {
    handled = true;
    // division operation
    auto *op = new Divide_Expr ();
    op->add_precedence (accumulated_precedence);
 
    lastValidInput = nullptr;

    // insert the op according to precedence relationships
    precedence_insert (op, list);
  } else if (input[i] == '(') {
    handled = true;
    handle_parenthesis (input, i, lastValidInput, 
                        handled, accumulated_precedence, list);
  } else if (input[i] == ' ' || input[i] == '\n') {
    handled = true;
    // skip whitespace
  }
}

void 
In_Order_Interpreter::handle_parenthesis (const std::string &input,
                                          std::string::size_type &i,
                                          Expr *& lastValidInput,
                                          bool & handled,
                                          int & accumulated_precedence,
                                          std::list<Expr *>& master_list) {
  /* handle parenthesis is a lot like handling a new interpret.
     the difference is that we have to worry about how the calling
     function has its list setup */

  //std::cerr << "Handling an opening parenthesis.\n";

  accumulated_precedence += 5;

  std::list<Expr *> list;

  handled = false;
  for (++i; i < input.length (); ++i) {
    main_loop (input, i, lastValidInput, 
               handled, accumulated_precedence, list);

    if (input[i] == ')') {
      //std::cerr << "Handling a closing parenthesis.\n";

      handled = true;
      //++i;
      accumulated_precedence -= 5;
      break;
    }
  }

  if (!master_list.empty() && !list.empty()) {
    Expr * lastSymbol = master_list.back ();
    auto * op = dynamic_cast <Binary_Expr *> (lastSymbol);
    auto * unary = dynamic_cast <Unary_Expr *> (lastSymbol);


    // is it a node with 2 children?
    if (op)
      precedence_insert (list.back (), master_list);
    // is it a unary node (like negate)
    else if (unary)
      precedence_insert (list.back (), master_list);
    else {
      // is it a terminal node (Number_Expr)
      // error
    }
  } else if (!list.empty())
    master_list = list;

  list.clear ();
}

Expr *
In_Order_Interpreter::build_parse_tree(const std::string &input) {
  std::list<Expr *> list;
  Expr * lastValidInput = nullptr;
  bool handled = false;
  int accumulated_precedence = 0;

  for (std::string::size_type i = 0;
       i < input.length (); 
       ++i) {
    main_loop (input, i, lastValidInput, 
               handled, accumulated_precedence, list);

    // store last valid input symbol. this is useful to the '-' operator
    // and will help us determine if '-' is a subtraction or a negation
    //if (input[i] != ' ' && input[i] != '\n')
    // lastValidInput = input[i];
  }

  return list.back();
}
    
// converts a string into a parse tree, and builds an expression tree
// out of the parse tree.
Expression_Tree 
In_Order_Interpreter::build_expression_tree (Expr *parse_tree) {
  // If the stack has a valid parse tree then return the top item.
  if (parse_tree != nullptr) 
    // Invoke a recursive Expression_Tree build starting with the root
    // symbol. This is an example of the builder pattern. See pg 97 in
    // GoF book.
    return Expression_Tree (parse_tree->build ());
  else
    // If we reach this, we didn't have any symbols in the input expression.
    return Expression_Tree (nullptr);
}

// ----------------------------------------
// constructor
Post_Order_Interpreter::Post_Order_Interpreter (const Interpreter_Context &context)
  : Interpreter_Impl (context) {
}

// destructor
Post_Order_Interpreter::~Post_Order_Interpreter () = default;

Post_Order_Interpreter::Post_Order_Iterator::Post_Order_Iterator ()
  : index_ (0),
    input_ (nullptr),
    stack_(nullptr) {
}

Post_Order_Interpreter::Post_Order_Iterator::Post_Order_Iterator
    (const std::string &input,
     std::stack<Expr *> &stack)
  : index_(0),
    input_(&input),
    stack_(&stack) {
}

bool 
Post_Order_Interpreter::Post_Order_Iterator::operator !=
  (const Post_Order_Iterator &rhs) {
  return index_ < input_->length();
}

Expr *
Post_Order_Interpreter::Post_Order_Iterator::operator *() {
  // Get a character for the current input expression.
  char c = (*input_)[index_];

  // Skip over whitespace.
  while (isspace(c)) 
    c = (*input_)[++index_];

  // Make a terminal expression if the character is a number or name.
  if (isalnum(c)) {
    return make_number();
  } else {
    // Process the operators.
    auto right_expr = stack_->top();
    stack_->pop();
    switch (c) {
    case '+':
      return make_expr<Add_Expr>(stack_, right_expr);
    case '-':
      return make_expr<Subtract_Expr>(stack_, right_expr);
    case '~':
      return new Negate_Expr(right_expr);
    case '*':
      return make_expr<Multiply_Expr>(stack_, right_expr);
    case '/':
      return make_expr<Divide_Expr>(stack_, right_expr);
    default:
      throw std::invalid_argument("invalid symbol");
    }
  }
}

void 
Post_Order_Interpreter::Post_Order_Iterator::operator++ () {
  // Advanced the iterator by one.
  ++index_;
}

Expr *
Post_Order_Interpreter::Post_Order_Iterator::make_number() {
  // Create a number from the user's input expression.
  int j = 1;
  for (; index_ + j < input_->length () && isalnum ((*input_)[index_ + j]); ++j)
    continue;

  auto expr = new Number_Expr ((*input_).substr (index_, j));

  index_ += j - 1;

  return expr;
}

template <typename T> Expr *
Post_Order_Interpreter::Post_Order_Iterator::make_expr(std::stack<Expr *> *stack,
                                                       Expr *right_expr) {
  auto top = stack->top();
  stack->pop();
  return new T(top, right_expr);
}

Post_Order_Interpreter::Post_Order_Iterator
Post_Order_Interpreter::begin(const std::string &input, 
                              std::stack<Expr *> &stack) {
  return Post_Order_Interpreter::Post_Order_Iterator(input, stack);
}

Post_Order_Interpreter::Post_Order_Iterator
Post_Order_Interpreter::end() {
  return Post_Order_Interpreter::Post_Order_Iterator();
}

Expr *
Post_Order_Interpreter::build_parse_tree(const std::string &input) {
  // The post-order interpreter uses a stack of Expr *'s to keep track
  // of the parse tree as it's being built incrementally.
  std::stack<Expr *> stack;

  // Iterate through the user input expression and convert it into a
  // parse tree.
  for (auto iter = begin(input, stack);
       iter != end();
       ++iter)
    stack.push(*iter);

  if (stack.empty())
    return nullptr;
  else
    // Return the Expr * at the top of the stack, which is the root of
    // the parse tree.
    return stack.top();
}
    
// converts a string into a parse tree, and builds an expression tree
// out of the parse tree.
Expression_Tree 
Post_Order_Interpreter::build_expression_tree (Expr *parse_tree) {
  // if the list has an element in it, then return the back of the list.
  // if (!list.empty ()) {

  // Invoke a recursive Expression_Tree build starting with the root
  // symbol. This is an example of the builder pattern. See pg 97 in
  // GoF book.

  return Expression_Tree (parse_tree->build ());

  // If we reach this, we didn't have any symbols.
  // return Expression_Tree ();
}

