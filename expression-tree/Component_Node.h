/* -*- C++ -*- */
#ifndef _COMPONENT_NODE_H_
#define _COMPONENT_NODE_H_

#include <string>
#include <memory>
#include <stdexcept>

// Forward declaration.
class Visitor;

/**
 * @class Component_Node
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
class Component_Node
{
public:
  /// Exception classes for Component_Node exceptions
  class Invalid_Function_Call : public std::domain_error
  {
  public:
    Invalid_Function_Call (const std::string &message): std::domain_error(message) {}
  }; 

  /// Dtor
  virtual ~Component_Node (void) = 0;

  /// Return the item stored in the node (throws std::domain_error if
  /// called directly).
  virtual int item (void) const;

  /// Return the left child (returns 0 if called directly).
  virtual Component_Node *left (void) const;

  /// Return the right child (returns 0 if called directly).
  virtual Component_Node *right (void) const;

  /// Accept a visitor to perform some action on the node's item
  /// completely arbitrary visitor template (throws std::domain_error
  /// if called directly).
  virtual void accept (Visitor &visitor) const;
};

#endif /* _COMPONENT_NODE_H_ */
