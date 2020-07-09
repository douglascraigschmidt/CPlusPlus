/* -*- C++ -*- */

#ifndef _EXPRESSION_TREE_H
#define _EXPRESSION_TREE_H

#include <string>
#include <stdexcept>
#include "utils/Refcounter.h"

#include "composites/Component_Node.h"

// Forward declarations.
class Expression_Tree_Iterator;
class Expression_Tree_Const_Iterator;

/**
 * @class Expression_Tree
 *
 * @brief Interface for the Composite pattern that is used to contain
 *        all the operator and operand nodes in the expression tree.
 * 
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor" that
 *        performs the expression tree operations.  Also defines the
 *        STL factory methods that create the desired begin and end
 *        iterators.
 */
class Expression_Tree {
public:
  /// Exception class for Invalid States exceptions
  class Invalid_Iterator : public std::domain_error {
  public:
    explicit Invalid_Iterator(const std::string &message) 
      : std::domain_error(message) {}
  }; 

  // Define a "trait"
  typedef int value_type;
  typedef Expression_Tree_Iterator iterator;
  typedef Expression_Tree_Const_Iterator const_iterator;

  /// Default ctor
  Expression_Tree ();

  /// Ctor that takes a @a Node * that contains all the nodes in the
  /// expression tree.
  explicit Expression_Tree (Component_Node *root,
                            bool increase_count = false);

  // Copy ctor
  Expression_Tree (const Expression_Tree &t);

  /// Gain access to the underlying root pointer functions are useful
  /// to the iterators.
  [[nodiscard]] Component_Node *get_root () const;

  /// Assignment operator.
  Expression_Tree &operator= (const Expression_Tree &t);

  /// Dtor
  ~Expression_Tree ();

  /// Check if tree is null tree.
  [[nodiscard]] bool is_null () const;

  /// Return the item in the tree.
  [[nodiscard]] int item () const;

  /// Return the left child.
  [[nodiscard]] Expression_Tree left ();

  /// Return the right child.
  [[nodiscard]] Expression_Tree right ();

  /// Get an iterator pointing to the "beginning" of the expression
  /// tree relative to the requested @a traversal_order.
  [[nodiscard]] iterator begin (const std::string &traversal_order);

  /// Get an iterator pointing to the "end" of the expression tree
  /// relative to the requested @a traversal_order.
  [[nodiscard]] iterator end (const std::string &traversal_order);

  /// Get a const iterator pointing to the "beginning" of the
  /// expression tree relative to the requested @a traversal_order.
  [[nodiscard]] const_iterator begin (const std::string &traversal_order) const;

  /// Get a const iterator pointing to the "end" of the expression
  /// tree relative to the requested @a traversal_order.
  [[nodiscard]] const_iterator end (const std::string &traversal_order) const;

  /// Accept a visitor to perform some action on the Expression_Tree.
  void accept (Visitor &visitor) const;

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management. 
  Refcounter <Component_Node> root_;
};

#endif /* _EXPRESSION_TREE_H */
