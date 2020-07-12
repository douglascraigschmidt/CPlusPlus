#include <iostream>
#include <memory>
#include <cctype>
#include <stack>

#include "interpreters/Interpreter_Impl.h"

// constructor
Interpreter_Context::Interpreter_Context () = default;

// destructor
Interpreter_Context::~Interpreter_Context () = default;

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

  if (parse_tree != nullptr) {
    optimize_parse_tree(parse_tree.get());
    return build_expression_tree(parse_tree.get());
  } else 
    return Expression_Tree(nullptr);
}

void
Interpreter_Impl::optimize_parse_tree(Expr *parse_tree) {
}

// converts a string into a parse tree, and builds an expression tree
// out of the parse tree.
Expression_Tree 
Interpreter_Impl::build_expression_tree (Expr *parse_tree) {
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

// constructor
In_Order_Interpreter::In_Order_Interpreter (const Interpreter_Context &context)
  : Interpreter_Impl (context) {
}

// destructor
In_Order_Interpreter::~In_Order_Interpreter () = default;

Expr *
In_Order_Interpreter::build_parse_tree(const std::string &input) {
  Expr *root = nullptr;

  // This stack handles "reductions".
  std::stack<Expr *> handle_stack;

  // This stack keeps track of operator precedence.
  std::stack<Expr *> operator_stack;

  // The operator stack always starts with a Delimiter symbol.
  operator_stack.push(new Delimiter);

  std::string terminated_input = input;
  terminated_input.push_back('$');
  // Create an iterator for the input and iterate
  // through all the symbols.
  for (auto iter = begin(terminated_input);
       iter != end();
       ++iter) {
    // Get the next expr from the user's input expression.
    auto expr = *iter;

    // Determine the type of expr.
    int expr_type = expr->get_type();

    // Numbers are pushed directly onto the handle stack.
    if (expr_type == Component_Node::NUMBER) {
        handle_stack.push(expr);
    }

    // If the operator on top of the stack is lower precedence than
    // the current operator expr then push the expr on the stack.
    else if (Component_Node::top_of_stack_precedence_[operator_stack.top()->get_type()]
             < Component_Node::current_token_precedence_[expr_type]) {
        operator_stack.push(expr);
    } else {
      // As long as the operator on top of the stack is higher
      // precedence than the current operator expr perform reductions.
      while (Component_Node::top_of_stack_precedence_[operator_stack.top()->get_type()]
             > Component_Node::current_token_precedence_[expr_type]) {
        // Get the top operator on the stack.
        auto temp = operator_stack.top();
        // Pop the top operator off the stack.
        operator_stack.pop();

        // A Negate operator expr triggers unary reduction.
        if (temp->get_type() == Component_Node::NEGATION) {
            // Push the reduction onto the handle stack.
          handle_stack.push(make_unary_expr(handle_stack, temp));
        }
        // Other exprs trigger a binary reduction.
        else {
          // Push the reduction onto the handle stack.
          handle_stack.push(make_binary_expr(handle_stack, temp));
        }
      }

      // Get the type that's on top of the operator stack.
      int top_expr_type = operator_stack.top()->get_type();

      // If all we have are matching Delimiters we are done.
      if (top_expr_type == Component_Node::DELIMITER
          && expr_type == Component_Node::DELIMITER) {
        root = handle_stack.top();
        handle_stack.pop();
      }
      // Remove a left-paren when its matching right-paren
      // is reached.
      else if (top_expr_type == Component_Node::LPAREN
               && expr_type == Component_Node::RPAREN) {
        operator_stack.pop();
      } else
        // Push the expr onto the top of the operator stack.
        operator_stack.push(expr);
    }            
  }

  return root;
}

Expr *
In_Order_Interpreter::make_unary_expr(std::stack<Expr *> &handle_stack,
                                      Expr *expr) {
  auto ne = dynamic_cast<Negate_Expr *>(expr);
  ne->right_expr_ = handle_stack.top();
  handle_stack.pop();
  return ne;
}

Expr *
In_Order_Interpreter::make_binary_expr(std::stack<Expr *> &handle_stack,
                                       Expr *expr) {
  auto be = dynamic_cast<Binary_Expr *>(expr);
  // Pop the top two items off the stack.
  be->right_expr_ = handle_stack.top();
  handle_stack.pop();
  be->left_expr_ = handle_stack.top();
  handle_stack.pop();

  return be;
}

In_Order_Interpreter::In_Order_Iterator::In_Order_Iterator ()
  : index_ (0),
    input_ (nullptr),
    prior_expr_ (nullptr) {
}

In_Order_Interpreter::In_Order_Iterator::In_Order_Iterator
    (const std::string &input)
  : index_ (0),
    input_ (&input),
    prior_expr_ (nullptr) {
}

bool 
In_Order_Interpreter::In_Order_Iterator::operator !=
  (const In_Order_Iterator &rhs) {
  return index_ < input_->length();
}

void
In_Order_Interpreter::In_Order_Iterator::operator++() {
  ++index_;
}

Expr *
In_Order_Interpreter::In_Order_Iterator::operator *() {
  // Get a character for the current input expression.
  char c = (*input_)[index_];

  // Skip over whitespace.
  while (isspace(c)) 
    c = (*input_)[++index_];

  Expr *latest_expr;

  // Handle a variable or number.
  // Make a terminal expression if the character is a number or name.
  if (isalnum(c)) {
    latest_expr = make_number();
  } else {
    switch (c) {
    case '+':
      // Addition operation.
      latest_expr = new Add_Expr;
      break;
    case '-':
      if (prior_expr_ != nullptr
          && (prior_expr_->get_type() == Component_Node::NUMBER
              || prior_expr_->get_type() == Component_Node::RPAREN))
        // Subtraction operation.
        latest_expr = new Subtract_Expr;
      else
        // Negate operation.
        latest_expr = new Negate_Expr;
      break;
    case '*':
      // Multiplication operation.
      latest_expr = new Multiply_Expr;
      break;
    case '/':
      // Division Operation.
      latest_expr = new Divide_Expr;
      break;
    case '(':
      // LParen.
      latest_expr = new Left_Paren;
      break;
    case ')':
      // RParen
      latest_expr = new Right_Paren;
      break;
    case '$':
      latest_expr = new Delimiter;
      break;
    default:
      std::string message = "invalid expr = ";
      message.push_back(c);
      throw std::invalid_argument(message);
    }
  }

  prior_expr_ = latest_expr;
  return latest_expr;
}

Expr *
In_Order_Interpreter::In_Order_Iterator::make_number() {
  // Create a number from the user's input expression.

  int j = 1;
  for (; index_ + j < input_->length () && isalnum ((*input_)[index_ + j]); ++j)
    continue;

  auto expr = new Number_Expr ((*input_).substr (index_, j));

  index_ += j - 1;

  return expr;
}

In_Order_Interpreter::In_Order_Iterator
In_Order_Interpreter::begin(const std::string &input) {
  return In_Order_Interpreter::In_Order_Iterator(input);
}

In_Order_Interpreter::In_Order_Iterator
In_Order_Interpreter::end() {
  return In_Order_Interpreter::In_Order_Iterator();
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
      return make_expr<Add_Expr>(right_expr);
    case '-':
      return make_expr<Subtract_Expr>(right_expr);
    case '~':
      return new Negate_Expr(right_expr);
    case '*':
      return make_expr<Multiply_Expr>(right_expr);
    case '/':
      return make_expr<Divide_Expr>(right_expr);
    default:
        std::string message = "invalid expr = ";
        message.push_back(c);
        throw std::invalid_argument(message);
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
Post_Order_Interpreter::Post_Order_Iterator::make_expr(Expr *right_expr) {
  auto top = stack_->top();
  stack_->pop();
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
    

