/* -*- C++ -*- */
#ifndef _EXPRESSION_TREE_CPP_
#define _EXPRESSION_TREE_CPP_

#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

#include "composites/Component_Node.h"
#include "iterators/ET_Iterator.h"
#include "iterators/ET_Iterator_Impl.h"
#include "Expression_Tree.h"

/**
 * @class ET_Iterator_Factory
 * @brief Implementation of a factory pattern that dynamically allocates
 *        the appropriate @a ET_Iter_Impl object.
 * 
 *        This is a variant of the Abstract Factory pattern that
 *        has a set of related factory methods but which doesn't use
 *        inheritance. 
 *
 * @see   Expression_Tree_Level_Order_Iterator_Impl,
 *        Expression_Tree_In_Order_Iterator_Impl, 
 *        Expression_Tree_Pre_Order_Iterator_Impl, and
 *        Expression_Tree_Post_Order_Iterator_Impl.
 */
class ET_Iterator_Factory
{
public:
  /// Constructor.
  ET_Iterator_Factory ();

  /// Dynamically allocate a new @a ET_Iter_Impl
  /// object based on the designated @a traversal_order and @a end_iter.
  ET_Iter_Impl *make_iterator (Expression_Tree &tree,
                               const std::string &traversal_order,
                               bool end_iter);

private:
  /// Dynamically allocate a new @a Expression_Tree_Level_Order_Iterator_Impl
  /// object based on the designated @a end_iter.
  static ET_Iter_Impl *make_in_order_tree_iterator (Expression_Tree &tree,
                                                    bool end_iter);

  /// Dynamically allocate a new @a Expression_Tree_Pre_Order_Iterator_Impl
  /// object based on the designated @a end_iter.
  static ET_Iter_Impl *make_pre_order_tree_iterator (Expression_Tree &tree,
                                                     bool end_iter);

  /// Dynamically allocate a new @a Expression_Tree_Post_Order_Iterator_Impl
  /// object based on the designated @a end_iter.
  static ET_Iter_Impl *make_post_order_tree_iterator (Expression_Tree &tree,
                                                      bool end_iter);

  /// Dynamically allocate a new @a Expression_Tree_Level_Order_Iterator_Impl
  /// object based on the designated @a end_iter.
  static ET_Iter_Impl *make_level_order_tree_iterator (Expression_Tree &tree,
                                                       bool end_iter);

  typedef ET_Iter_Impl *(*TRAVERSAL_PTMF) (Expression_Tree &tree, bool end_iter);
  typedef std::map <std::string, TRAVERSAL_PTMF> TRAVERSAL_MAP;

  TRAVERSAL_MAP traversal_map_;
};

ET_Iterator_Factory::ET_Iterator_Factory ()
{
  traversal_map_["in-order"] = &ET_Iterator_Factory::make_in_order_tree_iterator;
  traversal_map_["pre-order"] = &ET_Iterator_Factory::make_pre_order_tree_iterator;
  traversal_map_["post-order"] = &ET_Iterator_Factory::make_post_order_tree_iterator;
  traversal_map_["level-order"] = &ET_Iterator_Factory::make_level_order_tree_iterator;
}

ET_Iter_Impl *
ET_Iterator_Factory::make_level_order_tree_iterator (Expression_Tree &tree,
                                                     bool end_iter)
{ 
  return new Level_Order_ET_Iter_Impl (tree, end_iter);
}

ET_Iter_Impl *
ET_Iterator_Factory::make_in_order_tree_iterator (Expression_Tree &tree,
                                                  bool end_iter)
{ 
  return new In_Order_ET_Iter_Impl (tree, end_iter);
}

ET_Iter_Impl *
ET_Iterator_Factory::make_pre_order_tree_iterator (Expression_Tree &tree,
                                                   bool end_iter)
{ 
  return new Pre_Order_ET_Iter_Impl (tree, end_iter);
}

ET_Iter_Impl *
ET_Iterator_Factory::make_post_order_tree_iterator (Expression_Tree &tree,
                                                    bool end_iter)
{ 
  return new Post_Order_ET_Iter_Impl (tree, end_iter);
}

ET_Iter_Impl *
ET_Iterator_Factory::make_iterator (Expression_Tree &tree,
                                    const std::string &traversal_order,
                                    bool end_iter)
{  
  auto iter = traversal_map_.find (traversal_order);
  if (iter == traversal_map_.end ())
      // We don't understand the type. Convert the type to a string
      // and pass it back via an exception

      throw Expression_Tree::Invalid_Iterator (traversal_order);
  else
      return (*iter->second) (tree, end_iter);
}

// Define a single instance of a factory that's local to this class.
static ET_Iterator_Factory tree_iterator_factory;

// Default ctor

Expression_Tree::Expression_Tree ()
  : root_ (nullptr)
{    
}

// Ctor take an underlying NODE*.

Expression_Tree::Expression_Tree (Component_Node *root, bool increase_count)
  : root_ (root, increase_count)
{    
}

// Copy ctor

Expression_Tree::Expression_Tree (const Expression_Tree &t)
= default;

// Assignment operator

Expression_Tree &
Expression_Tree::operator= (const Expression_Tree &t)
{
  // Refcounter class takes care of the internal decrements and
  // increments.
  if (this != &t)
    root_ = t.root_;

  return *this;
}

// Dtor

Expression_Tree::~Expression_Tree () = default;

// Check if the tree is empty.

bool
Expression_Tree::is_null () const
{
  return root_.get_ptr () == nullptr;
}

// return root pointer

Component_Node *
Expression_Tree::get_root () const {
  return root_.get_ptr ();
}

// Return the stored item.

int 
Expression_Tree::item () const
{
  return root_->item ();
}

// Return the left branch.

Expression_Tree
Expression_Tree::left ()
{
  return Expression_Tree (root_->left (), true);
}

// Return the right branch.

Expression_Tree
Expression_Tree::right ()
{
  return Expression_Tree (root_->right (), true);
}

// Return a begin iterator of a specified type.

Expression_Tree::iterator
Expression_Tree::begin (const std::string &traversal_order)
{
  return Expression_Tree::iterator 
    (tree_iterator_factory.make_iterator(*this,
                                         traversal_order,
                                         false));
}

// Return an end iterator of a specified type.

Expression_Tree::iterator
Expression_Tree::end (const std::string &traversal_order)
{
  return Expression_Tree::iterator 
    (tree_iterator_factory.make_iterator(*this,
                                         traversal_order,
                                         true));
}

// Return a begin iterator of a specified type.

Expression_Tree_Const_Iterator
Expression_Tree::begin (const std::string &traversal_order) const
{
  auto *non_const_this = const_cast <Expression_Tree *> (this);
  return Expression_Tree::const_iterator (tree_iterator_factory.make_iterator(*non_const_this,
                                                                              traversal_order,
                                                                              false));
}

// Return an end iterator of a specified type.

Expression_Tree_Const_Iterator
Expression_Tree::end (const std::string &traversal_order) const
{
  auto *non_const_this = const_cast <Expression_Tree *> (this);
  return Expression_Tree::const_iterator (tree_iterator_factory.make_iterator(*non_const_this,
                                                                              traversal_order,
                                                                              true));
}

/// Accept a visitor to perform some action on the Expression_Tree.
void
Expression_Tree::accept (Visitor &visitor) const
{
  root_->accept (visitor);
}

#endif /* _EXPRESSION_TREE_CPP_ */
