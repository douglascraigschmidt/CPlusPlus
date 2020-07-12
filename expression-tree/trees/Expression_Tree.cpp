/* -*- C++ -*- */
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

#include "Expression_Tree.h"
#include "composites/Component_Node.h"
#include "iterators/Iterator.h"
#include "iterators/Iterator_Impl.h"

/**
 * @class Iterator_Factory
 *
 * @brief Implementation of a factory pattern that dynamically
 *        allocates the appropriate @a Iterator_Impl object.
 * 
 *        This is a variant of the Abstract Factory pattern that has a
 *        set of related factory methods but which doesn't use
 *        inheritance.
 *
 * @see Level_Order_Iterator_Impl, In_Order_Iterator_Impl,
 *        Pre_Order_Iterator_Impl, and Post_Order_Iterator_Impl.
 */
class Iterator_Factory {
public:
  /// Constructor.
  Iterator_Factory ();

  /// Dynamically allocate a new @a Iterator_Impl object based on the
  /// designated @a traversal_order and @a end_iter.
  Iterator_Impl *make_iterator (Expression_Tree &tree,
                                const std::string &traversal_order,
                                bool end_iter);

private:
  /// Dynamically allocate a new @a Level_Order_Iterator_Impl object
  /// based on the designated @a end_iter.
  static Iterator_Impl *make_in_order_tree_iterator (Expression_Tree &tree,
                                                     bool end_iter);

  /// Dynamically allocate a new @a Pre_Order_Iterator_Impl object
  /// based on the designated @a end_iter.
  static Iterator_Impl *make_pre_order_tree_iterator (Expression_Tree &tree,
                                                      bool end_iter);

  /// Dynamically allocate a new @a Post_Order_Iterator_Impl object
  /// based on the designated @a end_iter.
  static Iterator_Impl *make_post_order_tree_iterator (Expression_Tree &tree,
                                                       bool end_iter);

  /// Dynamically allocate a new @a Level_Order_Iterator_Impl object
  /// based on the designated @a end_iter.
  static Iterator_Impl *make_level_order_tree_iterator (Expression_Tree &tree,
                                                        bool end_iter);

  typedef Iterator_Impl *(*TRAVERSAL_PTMF) (Expression_Tree &tree, bool end_iter);
  typedef std::map <std::string, TRAVERSAL_PTMF> TRAVERSAL_MAP;

  TRAVERSAL_MAP traversal_map_;
};

Iterator_Factory::Iterator_Factory () {
  traversal_map_["in-order"] = &Iterator_Factory::make_in_order_tree_iterator;
  traversal_map_["pre-order"] = &Iterator_Factory::make_pre_order_tree_iterator;
  traversal_map_["post-order"] = &Iterator_Factory::make_post_order_tree_iterator;
  traversal_map_["level-order"] = &Iterator_Factory::make_level_order_tree_iterator;
}

Iterator_Impl *
Iterator_Factory::make_level_order_tree_iterator (Expression_Tree &tree,
                                                  bool end_iter) { 
  return new Level_Order_Iter_Impl (tree, end_iter);
}

Iterator_Impl *
Iterator_Factory::make_in_order_tree_iterator (Expression_Tree &tree,
                                               bool end_iter) { 
  return new In_Order_Iterator_Impl (tree, end_iter);
}

Iterator_Impl *
Iterator_Factory::make_pre_order_tree_iterator (Expression_Tree &tree,
                                                bool end_iter) { 
  return new Pre_Order_Iterator_Impl (tree, end_iter);
}

Iterator_Impl *
Iterator_Factory::make_post_order_tree_iterator (Expression_Tree &tree,
                                                 bool end_iter) { 
  return new Post_Order_Iterator_Impl (tree, end_iter);
}

Iterator_Impl *
Iterator_Factory::make_iterator (Expression_Tree &tree,
                                 const std::string &traversal_order,
                                 bool end_iter) {  
  auto iter = traversal_map_.find (traversal_order);
  if (iter == traversal_map_.end ())
    // We don't understand the type. Convert the type to a string
    // and pass it back via an exception

    throw Expression_Tree::Invalid_Iterator (traversal_order);
  else
    return (*iter->second) (tree, end_iter);
}

// Define a single instance of a factory that's local to this class.
static Iterator_Factory tree_iterator_factory;

// Default ctor

Expression_Tree::Expression_Tree ()
  : root_ (nullptr) {    
}

// Ctor take an underlying NODE*.

Expression_Tree::Expression_Tree (Component_Node *root, bool increase_count)
  : root_ (root, increase_count) {    
}

// Copy ctor

Expression_Tree::Expression_Tree (const Expression_Tree &t) = default;

// Assignment operator

Expression_Tree &
Expression_Tree::operator= (const Expression_Tree &t) {
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
Expression_Tree::is_null () const {
  return root_.get_ptr () == nullptr;
}

// return root pointer

Component_Node *
Expression_Tree::get_root () const {
  return root_.get_ptr ();
}

// Return the stored item.

int 
Expression_Tree::item () const {
  return root_->item ();
}

// Return the left branch.

Expression_Tree
Expression_Tree::left () {
  return Expression_Tree (root_->left (), true);
}

// Return the right branch.

Expression_Tree
Expression_Tree::right () {
  return Expression_Tree (root_->right (), true);
}

// Return a begin iterator of a specified type.

Expression_Tree::iterator
Expression_Tree::begin (const std::string &traversal_order) {
  return Expression_Tree::iterator 
    (tree_iterator_factory.make_iterator(*this,
                                         traversal_order,
                                         false));
}

// Return an end iterator of a specified type.

Expression_Tree::iterator
Expression_Tree::end (const std::string &traversal_order) {
  return Expression_Tree::iterator 
    (tree_iterator_factory.make_iterator(*this,
                                         traversal_order,
                                         true));
}

// Return a begin iterator of a specified type.

Expression_Tree::const_iterator
Expression_Tree::begin (const std::string &traversal_order) const {
  auto *non_const_this = const_cast <Expression_Tree *> (this);
  return Expression_Tree::const_iterator (tree_iterator_factory.make_iterator(*non_const_this,
                                                                              traversal_order,
                                                                              false));
}

// Return an end iterator of a specified type.

Expression_Tree::const_iterator
Expression_Tree::end (const std::string &traversal_order) const {
  auto *non_const_this = const_cast <Expression_Tree *> (this);
  return Expression_Tree::const_iterator (tree_iterator_factory.make_iterator(*non_const_this,
                                                                              traversal_order,
                                                                              true));
}

/// Accept a visitor to perform some action on the Expression_Tree.
void
Expression_Tree::accept (Visitor &visitor) const {
  root_->accept (visitor);
}
