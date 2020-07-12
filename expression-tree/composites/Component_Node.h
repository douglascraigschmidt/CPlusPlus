/* -*- C++ -*- */
#ifndef _COMPONENT_NODE_H
#define _COMPONENT_NODE_H

#include <string>
#include <memory>
#include <stdexcept>

// Forward declaration.
class Visitor;

/**
 * @class Component_Node
 *
 * @brief An abstract base class defines a simple abstract
 *        implementation of an expression tree node.
 *
 *        This class plays the role of the "Component" in the
 *        Composite pattern.  The methods in this class are not
 *        defined as pure virtual so that subclasses in the Composite
 *        pattern don't have to implement methods they don't care
 *        about.  All the methods (exception the destructor) throw the
 *        @a Invalid_Function_Call exception if called, however.
 *        
 * @see   See Composite_Unary_Node and Composite_Binary_Node for nodes
 *        with right only and left and right children, respectively.
 */
class Component_Node {
public:
  /// Exception classes for Component_Node exceptions
  class Invalid_Function_Call : public std::domain_error
  {
  public:
    explicit Invalid_Function_Call (const std::string &message)
      : std::domain_error(message) {}
  }; 

  /*
   * The following constants uniquely identify the type of each
   * terminal symbol.
   */
  static const int MULTIPLICATION = 0;
  static const int DIVISION = 1;
  static const int ADDITION = 2;
  static const int SUBTRACTION = 3;
  static const int NEGATION = 4;
  static const int LPAREN = 5;
  static const int RPAREN = 6;
  static const int ID = 7;
  static const int NUMBER = 8;
  static const int DELIMITER = 9;

  /**
   * The relative precedence of each terminal symbol above when it
   * appears at the top of the stack.
   */
  constexpr static const int top_of_stack_precedence_[] = {
    12, 11, 7, 6, 10, 2, 3, 15, 14, 1
  };

  /**
   * The relative precedence of each terminal symbol above when it
   * appears as the current token.
   */
   constexpr static const int current_token_precedence_[] = {
     9, 8, 5, 4, 13, 18, 2, 17, 16, 1
   };

  /// Dtor
  virtual ~Component_Node () = 0;

  /// Returns the type of the component node (used by the
  /// In_Order_Interpreter's operator-precedence parsing algorithm).
  [[nodiscard]] int get_type() const;

  /// Return the item stored in the node (throws std::domain_error if
  /// called directly).
  [[nodiscard]] virtual int item () const;

  /// Return the left child (returns 0 if called directly).
  [[nodiscard]] virtual Component_Node *left () const;

  /// Return the right child (returns 0 if called directly).
  [[nodiscard]] virtual Component_Node *right () const;

  /// Accept a visitor to perform some action on the node's item
  /// completely arbitrary visitor template (throws std::domain_error
  /// if called directly).
  virtual void accept (Visitor &visitor) const;

private:
  /// Stores the type of the component node (used by the
  /// In_Order_Interpreter's operator-precedence parsing algorithm).
  int type_;
};

#endif /* _COMPONENT_NODE_H */
