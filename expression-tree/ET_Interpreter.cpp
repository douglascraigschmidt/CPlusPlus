#ifndef _INTERPRETER_CPP_
#define _INTERPRETER_CPP_

#include <iostream>
#include <memory>
#include <cstdlib>

#include "Component_Node.h"
#include "Leaf_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Add_Node.h"
#include "Composite_Subtract_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "ET_Interpreter.h"

/**
 * @class Expr
 * @brief Abstract base class of all parse tree nodes.
 */
class Expr
{
public:
  /// constructor
  Expr (Expr *left, Expr *right, int precedence_ = 0);

  /// destructor
  virtual ~Expr ();

  /// abstract method for returning precedence level (higher
  /// value means higher precedence
  virtual int precedence () {
    return precedence_;
  }

  virtual int add_precedence (int accumulated_precedence) = 0;

  /// abstract method for building an Expression Expression_Tree Node

  virtual Component_Node *build () = 0;

  /// left and right pointers

  Expr *left_;
  Expr *right_;
  int precedence_;
};

/**
 * @class Binary_Expr
 * @brief Abstract base class for all parse tree node operators
 * @see   Add_Expr, Subtract_Expr, Multiply_Expr, Divide_Expr
 */
class Binary_Expr : public Expr
{
public:
  /// constructor
  Binary_Expr (Expr *left, Expr *right, int precedence_ = 1);

  /// destructor
  ~Binary_Expr () override;
};

/**
 * @class Unary_Expr
 * @brief Abstract base class for all parse tree node operators
 * @see   Add_Expr, Subtract_Expr, Multiply_Expr, Divide_Expr
 */
class Unary_Expr : public Expr
{
public:
  /// constructor
  explicit Unary_Expr (Expr *right, int precedence_ = 1);

  /// destructor
  ~Unary_Expr () override;
};

/**
 * @class Number_Expr
 * @brief Leaf node of parse tree
 */

class Number_Expr : public Expr
{
public:
  /// constructors
  explicit Number_Expr (const std::string& input);
  explicit Number_Expr (int input);

  /// destructor
  ~Number_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
private:
  /// contains the value of the leaf node
  int number_;
};

/**
 * @class Subtract_Expr
 * @brief Subtraction node of the parse tree
 */

class Subtract_Expr : public Binary_Expr
{
public:
  /// constructor
  Subtract_Expr ();

  /// destructor
  ~Subtract_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Add_Expr
 * @brief Addition node of the parse tree
 */

class Add_Expr : public Binary_Expr
{
public:
  /// constructor
  Add_Expr ();

  /// destructor
  ~Add_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Negate_Expr
 * @brief Negate_Expr node of the parse tree
 */

class Negate_Expr : public Unary_Expr
{
public:
  /// constructor
  Negate_Expr ();

  /// destructor
  ~Negate_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Multiply_Expr
 * @brief Multiplication node of the parse tree
 */

class Multiply_Expr : public Binary_Expr
{
public:
  /// constructor
  Multiply_Expr ();

  /// destructor
  ~Multiply_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Divide_Expr
 * @brief Division node of the parse tree
 */

class Divide_Expr : public Binary_Expr
{
public:
  /// constructor
  Divide_Expr ();

  /// destructor
  ~Divide_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

// constructor
ET_Interpreter_Context::ET_Interpreter_Context ()
= default;

// destructor
ET_Interpreter_Context::~ET_Interpreter_Context ()
= default;

// return the value of a variable
int
ET_Interpreter_Context::get (const std::string& variable)
{
  return map_[variable];
}

// set the value of a variable
void
ET_Interpreter_Context::set (const std::string& variable, int value)
{
  map_[variable] = value;
}

// print all variables and their values
void
ET_Interpreter_Context::print ()
{
  for (auto & i : map_)
    std::cout << i.first << "=" << i.second << "\n";
}

// clear all variables and their values
void
ET_Interpreter_Context::reset ()
{
  map_.clear ();
}

// constructor
Expr::Expr (Expr *left, Expr *right, int precedence)
  : left_ (left), right_ (right), precedence_ (precedence)
{
}

// destructor
Expr::~Expr ()
{
  delete left_;
  delete right_;
}

// constructor
Binary_Expr::Binary_Expr (Expr *left, Expr *right, int precedence)
  : Expr (left, right, precedence)
{
}

// destructor
Binary_Expr::~Binary_Expr ()
= default;

// constructor
Unary_Expr::Unary_Expr (Expr *right, int precedence)
  : Expr (nullptr, right, precedence)
{
}

// destructor
Unary_Expr::~Unary_Expr ()
= default;

// constructor
Number_Expr::Number_Expr (const std::string& input)
  : Expr (nullptr, nullptr, 4)
{
  number_ = ::atoi (input.c_str ());
}

// constructor
Number_Expr::Number_Expr (int input)
  : Expr (nullptr, nullptr, 4),
    number_ (input)
{
}

// destructor
Number_Expr::~Number_Expr ()
= default;

// returns the precedence level
int 
Number_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 4 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Number_Expr::build ()
{
  return new Leaf_Node (number_);
}

// constructor
Negate_Expr::Negate_Expr ()
  : Unary_Expr (nullptr, 3)
{
}

// destructor
Negate_Expr::~Negate_Expr ()
= default;

// returns the precedence level
int 
Negate_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 3 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Negate_Expr::build ()
{
  return new Composite_Negate_Node (right_->build ());
}

// constructor
Add_Expr::Add_Expr ()
  : Binary_Expr (nullptr, nullptr, 1)
{
}

// destructor
Add_Expr::~Add_Expr ()
= default;

// returns the precedence level
int 
Add_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 1 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Add_Expr::build ()
{
  return new Composite_Add_Node (left_->build (), right_->build ());
}

// constructor
Subtract_Expr::Subtract_Expr ()
  : Binary_Expr (nullptr, nullptr, 1)
{
}

// destructor
Subtract_Expr::~Subtract_Expr ()
= default;

// returns the precedence level
int 
Subtract_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 1 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Subtract_Expr::build ()
{
  return new Composite_Subtract_Node (left_->build (), right_->build ());
}

// constructor
Multiply_Expr::Multiply_Expr ()
  : Binary_Expr (nullptr, nullptr, 2)
{
}

// destructor
Multiply_Expr::~Multiply_Expr ()
= default;

// returns the precedence level
int 
Multiply_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 2 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Multiply_Expr::build ()
{
  return new Composite_Multiply_Node (left_->build (), right_->build ());
}

// constructor
Divide_Expr::Divide_Expr ()
  : Binary_Expr (nullptr, nullptr, 2)
{
}

// destructor
Divide_Expr::~Divide_Expr ()
= default;

// returns the precedence level
int 
Divide_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 2 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Divide_Expr::build ()
{
  return new Composite_Divide_Node (left_->build (), right_->build ());
}

ET_Interpreter::ET_Interpreter(ET_Interpreter_Impl *impl)
        : interpreter_(impl) {

}

ET_Interpreter::~ET_Interpreter() = default;

Expression_Tree
ET_Interpreter::interpret (const std::string &input) {
    return interpreter_->interpret(input);
}

Expression_Tree 
ET_Interpreter_Impl::interpret (const std::string &input) {
  std::unique_ptr<Expr> parse_tree (build_parse_tree(input));

  // if (!parse_tree) {
    optimize_parse_tree(parse_tree.get());
    auto tree = build_expression_tree(parse_tree.get());
    context_.print ();
    return tree;
  // } else
  //  return Expression_Tree(nullptr);
}

void
ET_Interpreter_Impl::optimize_parse_tree(Expr *parse_tree) {
}

ET_Interpreter_Impl::~ET_Interpreter_Impl() = default;

// constructor
ET_In_Order_Interpreter::ET_In_Order_Interpreter ()
= default;

// destructor
ET_In_Order_Interpreter::~ET_In_Order_Interpreter ()
= default;

// method for checking if a character is a valid operator
bool
ET_In_Order_Interpreter::is_operator (char input)
{
  return input == '+' 
    || input == '-' 
    || input == '*' 
    || input == '/';
}

// method for checking if a character is a number
bool
ET_In_Order_Interpreter::is_number (char input)
{
  return input >= '0' && input <= '9';
}

// method for checking if a character is a candidate
// for a part of a variable name
bool
ET_In_Order_Interpreter::is_alphanumeric (char input)
{
  return (input >= 'a' && input <= 'z') 
    || (input >= 'A' && input <= 'Z') 
    || (input == '_') 
    || (input >= '0' && input <= '9');
}

// inserts a terminal into the parse tree
void
ET_In_Order_Interpreter::terminal_insert (Expr *terminal,
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
ET_In_Order_Interpreter::variable_insert (const std::string &input,
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
ET_In_Order_Interpreter::number_insert (const std::string &input,
                               std::string::size_type &i,
                               int & accumulated_precedence,
                               std::list<Expr *>& list,
                               Expr *& lastValidInput)
{
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
ET_In_Order_Interpreter::precedence_insert (Expr *op,
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

      if (dynamic_cast <Unary_Expr *> (op))
        {
          for (; 
               child && child->precedence () == op->precedence ();
               child = child->right_)
            parent = child;

          // I can't think of a valid reason that parent->right_ would
          // be possible !0

          parent->right_ = op;
        }
      else {
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
ET_In_Order_Interpreter::main_loop (const std::string &input,
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
ET_In_Order_Interpreter::handle_parenthesis (const std::string &input,
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
ET_In_Order_Interpreter::build_parse_tree(const std::string &input) {
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
ET_In_Order_Interpreter::build_expression_tree (Expr *parse_tree) {
  // if the list has an element in it, then return the back of the list.
  // if (!list.empty ()) {

  // Invoke a recursive Expression_Tree build starting with the root
  // symbol. This is an example of the builder pattern. See pg 97 in
  // GoF book.

  return Expression_Tree (parse_tree->build ());

  // If we reach this, we didn't have any symbols.
  // return Expression_Tree ();
}

#endif // _INTERPRETER_CPP_

