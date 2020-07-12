#include <stdlib.h>
#include <algorithm>
#include <sstream>

#include "utils/Refcounter.h"
#include "trees/Expression_Tree.h"
#include "iterators/Iterator.h"

/// Copy ctor - needed for reference counting.

Expression_Tree_Iterator::Expression_Tree_Iterator (const Expression_Tree_Iterator &ts)
  : impl_ (ts.impl_) {
}
  
/// Copy ctor for impl *.

Expression_Tree_Iterator::Expression_Tree_Iterator (Iterator_Impl *impl)
  : impl_ (impl) {
}

/// Dereference operator returns a reference to the item contained at
/// the current position.
Expression_Tree 
Expression_Tree_Iterator::operator* () {
  // return impl_->operator* ();
  return *(*impl_);
}

/// Returns a const reference to the item contained at the current position
const Expression_Tree 
Expression_Tree_Iterator::operator* () const {
  // return impl_->operator* ();
  return *(*impl_);
}

/// Pre-increment operator

Expression_Tree_Iterator &
Expression_Tree_Iterator::operator++ () {
  // return impl_->operator++ ();
  ++(*impl_);
  return *this;
}

/// Delegation operator
Expression_Tree *
Expression_Tree_Iterator::operator-> () {
  return impl_->operator->();
}

/// Delegation operator
const Expression_Tree *
Expression_Tree_Iterator::operator-> () const {
  return impl_->operator->();
}

/// Post-increment operator
Expression_Tree_Iterator 
Expression_Tree_Iterator::operator++ (int) {
  Expression_Tree_Iterator temp (impl_->clone ());
  // return impl_->operator++ ();
  ++(*impl_);
  return temp;
}

/// Equality operator
bool 
Expression_Tree_Iterator::operator== (const Expression_Tree_Iterator &rhs) {
  // return impl_->operator () == rhs.impl_->operator ();
  return *impl_ == *rhs.impl_;
}

/// Nonequality operator
bool 
Expression_Tree_Iterator::operator!= (const Expression_Tree_Iterator &rhs) {
  return !(*this == rhs);
}

/// Copy ctor - needed for reference counting.
Expression_Tree_Const_Iterator::Expression_Tree_Const_Iterator (const Expression_Tree_Const_Iterator &ts) = default;
  
/// Copy ctor for impl *.
Expression_Tree_Const_Iterator::Expression_Tree_Const_Iterator (Iterator_Impl * impl)
  : impl_ (impl) {
}

/// Returns a const reference to the item contained at the current position
const Expression_Tree 
Expression_Tree_Const_Iterator::operator* () const {
  return *(*impl_);
}

/// Preincrement operator
Expression_Tree_Const_Iterator &
Expression_Tree_Const_Iterator::operator++ () {
  ++(*impl_);
  return *this;
}

/// Preincrement operator
Expression_Tree_Const_Iterator 
Expression_Tree_Const_Iterator::operator++ (int) {
  Expression_Tree_Const_Iterator temp (impl_.get_ptr ()->clone ());
  ++(*impl_);
  return *this;
}

/// Delegation operator
const Expression_Tree *
Expression_Tree_Const_Iterator::operator-> () const {
  return impl_->operator->();
}

/// Equality operator
bool 
Expression_Tree_Const_Iterator::operator== (const Expression_Tree_Const_Iterator &rhs) {
  return impl_->operator == (*rhs.impl_);
}

/// Nonequality operator
bool 
Expression_Tree_Const_Iterator::operator!= (const Expression_Tree_Const_Iterator &rhs) {
  return !(*this == rhs);
}
