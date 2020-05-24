/* -*- C++ -*- */
#ifndef _PRINT_VISITOR_H_
#define _PRINT_VISITOR_H_

#include "Visitor.h"

/**
 * @class Print_Visitor
 * @brief This class serves as a visitor for printing the contents of
 *        nodes to @a std::cout.
 */

class Print_Visitor : public Visitor
{
public:
  /// Visits a @a Leaf_Node and prints it contents to @a std::cout.
  virtual void visit (const Leaf_Node &node);

  /// Visit a @a Composite_Negate_Node and prints its contents to @a std::cout.
  virtual void visit (const Composite_Negate_Node &node);
  
  /// Visit a @a Composite_Add_Node and prints its contents to @a std::cout.
  virtual void visit (const Composite_Add_Node &node);
  
  /// Visit a @a Composite_Subtract_Node and prints its contents to @a std::cout.
  virtual void visit (const Composite_Subtract_Node &node);
  
  /// Visit a @a Composite_Divide_Node and prints its contents to @a std::cout.
  virtual void visit (const Composite_Divide_Node &node);
  
  /// visit function - prints Composite_Multiply_Node contents to std::cout
  virtual void visit (const Composite_Multiply_Node &node);
};  

#endif /* _PRINT_VISITOR_H_ */
