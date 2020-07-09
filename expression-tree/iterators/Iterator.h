/* -*- C++ -*- */
#ifndef _ITERATOR_H
#define _ITERATOR_H

#include <string>

#include "utils/Refcounter.h"
#include "Iterator_Impl.h"

// Forward declarations.
class User_Command_Factory;
class Component_Node;

/**
 * @class Expression_Tree_Iterator
 *
 * @brief Interface for the Iterator pattern that is used traverse
 *        through all the nodes in the expression tree in a non-const
 *        manner. 
 * 
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor" that
 *        performs the appropriate expression tree iterator
 *        operations.
 *
 * @see   Expression_Tree_Level_Order_Iterator_Impl,
 *        Expression_Tree_In_Order_Iterator_Impl,
 *        Expression_Tree_Pre_Order_Iterator_Impl, and
 *        Expression_Tree_Post_Order_Iterator_Impl.
 */
class Expression_Tree_Iterator {
public:
  /// Copy ctor - needed for reference counting.
  Expression_Tree_Iterator (const Expression_Tree_Iterator &ts);
  
  /// Copy ctor for impl *.
  explicit Expression_Tree_Iterator (Iterator_Impl *impl);

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  Expression_Tree operator* ();

  /// Returns a const reference to the item contained at the current
  /// position
  const Expression_Tree operator* () const;

  /// Preincrement operator
  Expression_Tree_Iterator &operator++ ();

  /// Postincrement operator. 
  Expression_Tree_Iterator operator++ (int);

  /// Delegation operator
  Expression_Tree *operator-> ();

  /// Delegation operator
  const Expression_Tree *operator-> () const;

  /// Equality operator
  bool operator== (const Expression_Tree_Iterator &rhs);

  /// In-equality operator
  bool operator!= (const Expression_Tree_Iterator &rhs);

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  Refcounter<Iterator_Impl> impl_;
};

/**
 * @class Expression_Tree_Const_Iterator
 *
 * @brief Interface for the Iterator pattern that is used traverse
 *        through all the nodes in the expression tree in a const
 *        manner.
 * 
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementation"
 *        that performs the appropriate expression tree iterator
 *        operations.
 *
 * @see   Expression_Tree_Level_Order_Iterator_Impl,
 *        Expression_Tree_In_Order_Iterator_Impl,
 *        Expression_Tree_Pre_Order_Iterator_Impl, and
 *        Expression_Tree_Post_Order_Iterator_Impl.
 */
class Expression_Tree_Const_Iterator
{
public:
  /// Copy ctor - needed for reference counting.
  Expression_Tree_Const_Iterator (const Expression_Tree_Const_Iterator &ts);
  
  /// Copy ctor for impl *.
  explicit Expression_Tree_Const_Iterator (Iterator_Impl *impl);
  
  /// Returns a const reference to the item contained at the current
  /// position
  const Expression_Tree operator* () const;

  /// Preincrement operator
  Expression_Tree_Const_Iterator &operator++ ();

  /// Postincrement operator. 
  Expression_Tree_Const_Iterator operator++ (int);

  /// Delegation operator
  const Expression_Tree *operator-> () const;

  /// Equality operator
  bool operator== (const Expression_Tree_Const_Iterator &rhs);

  /// Nonequality operator
  bool operator!= (const Expression_Tree_Const_Iterator &rhs);

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management. 
  Refcounter <Iterator_Impl> impl_;
};

#endif /* _ITERATOR_H */
