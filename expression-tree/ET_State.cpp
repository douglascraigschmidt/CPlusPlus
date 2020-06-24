#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "ET_Context.h"
#include "ET_Iterator.h"
#include "Print_Visitor.h"
#include "Evaluation_Visitor.h"
#include "Expression_Tree.h"

/**
 * @class Accept_Visitor_Adapter
 * @brief This functor implements the Adapter pattern so the @a
 *        Component_Node's @a accept() method can be called with the
 *        appropriate visitor in the context of the @a std:for_each()
 *        algorithm.
 */
template <typename VISITOR>
class Accept_Visitor_Adapter
{
public:
  /// Constructor.
  explicit Accept_Visitor_Adapter (VISITOR &visitor): visitor_ (visitor)
  {
  }

  /// Accept the @a visitor_ to visit the @a node.
  void operator () (const Expression_Tree &t)
  {
    t.accept (visitor_);
  }

private:
  VISITOR &visitor_;
};

/// this method traverses the tree in with a given traversal strategy
void 
Expression_Tree_State::print_tree (const Expression_Tree &tree,
                                   const std::string &traversal_order,
                                   std::ostream &os)
{
  os << "traverse tree using strategy '" << traversal_order
     << "':" << std::endl;
  
  // create a print visitor
  Print_Visitor print_visitor;

  // std::for_each() is a short-hand for writing the following loop:
  for (auto iter = tree.begin (traversal_order);
       iter != tree.end (traversal_order);
       ++iter)
    (*iter).accept (print_visitor);

#if 0
  std::for_each (tree.begin (traversal_order),
                 tree.end (traversal_order),
                 [&print_visitor] (auto tree)
                 {
                   tree.accept (print_visitor);
                 });

                 // Accept_Visitor_Adapter<Print_Visitor> (print_visitor));
#endif

  os << std::endl;
}

void 
Expression_Tree_State::evaluate_tree (const Expression_Tree &tree, 
                                      const std::string &traversal_order,
                                      std::ostream &os)
{
  // os << "Evaluating tree using strategy '" << traversal_order
  // << "':" << std::endl;

  Evaluation_Visitor evaluation_visitor;
  
  std::for_each (tree.begin (traversal_order),
                  tree.end (traversal_order),
                  Accept_Visitor_Adapter<Evaluation_Visitor> (evaluation_visitor));

#if 0
  // std::for_each() is a short-hand for writing the following loop:
  for (auto iter = tree.begin (traversal_order);
       iter != tree.end (traversal_order);
       ++iter)
    iter->accept (evaluation_visitor);
#endif
  std::cout << evaluation_visitor.total() << std::endl;
}

void 
Expression_Tree_State::format (Tree_Context &,
                               const std::string &)
{
  throw Expression_Tree_State::Invalid_State (
    "Expression_Tree_State::format called in invalid state");
}           

void 
Expression_Tree_State::make_tree (Tree_Context &,
                                  const std::string &)
{
  throw Expression_Tree_State::Invalid_State (
    "Expression_Tree_State::expr called in invalid state");
}                

void 
Expression_Tree_State::print (Tree_Context &,
                              const std::string &)
{
  throw Expression_Tree_State::Invalid_State (
    "Expression_Tree_State::print called in invalid state");
}

void 
Expression_Tree_State::evaluate (Tree_Context &,
                                 const std::string &)
{
  throw Expression_Tree_State::Invalid_State (
    "Expression_Tree_State::evaluate called in invalid state");
}

// Static data member definitions.
Uninitialized_State::Uninitialized_State_Factory::UNINITIALIZED_STATE_MAP 
Uninitialized_State::Uninitialized_State_Factory::uninitialized_state_map_;

Uninitialized_State::Uninitialized_State_Factory 
Uninitialized_State::uninitialized_state_factory;

Uninitialized_State::Uninitialized_State_Factory::Uninitialized_State_Factory (void)
{
  uninitialized_state_map_["in-order"] 
    = &Uninitialized_State::Uninitialized_State_Factory::make_in_order_uninitialized_state;
  uninitialized_state_map_["pre-order"] 
    = &Uninitialized_State::Uninitialized_State_Factory::make_pre_order_uninitialized_state;
  uninitialized_state_map_["post-order"] 
    = &Uninitialized_State::Uninitialized_State_Factory::make_post_order_uninitialized_state;
  uninitialized_state_map_["level-order"] 
    = &Uninitialized_State::Uninitialized_State_Factory::make_level_order_uninitialized_state;
}

Expression_Tree_State *
Uninitialized_State::Uninitialized_State_Factory::make_level_order_uninitialized_state (void)
{ 
  return new Level_Order_Uninitialized_State ();
}

Expression_Tree_State *
Uninitialized_State::Uninitialized_State_Factory::make_in_order_uninitialized_state (void)
{ 
  return new In_Order_Uninitialized_State ();
}

Expression_Tree_State *
Uninitialized_State::Uninitialized_State_Factory::make_pre_order_uninitialized_state (void)
{ 
  return new Pre_Order_Uninitialized_State ();
}

Expression_Tree_State *
Uninitialized_State::Uninitialized_State_Factory::make_post_order_uninitialized_state (void)
{ 
  return new Post_Order_Uninitialized_State ();
}

Expression_Tree_State *
Uninitialized_State::Uninitialized_State_Factory::make_uninitialized_state (const std::string &format)
{
  auto iter = uninitialized_state_map_.find (format);

  if (iter == uninitialized_state_map_.end ())
    {
      // We don't understand the type. Convert the type to a string
      // and pass it back via an exception

      throw Expression_Tree::Invalid_Iterator (format);
    }
  else
    {
      Uninitialized_State::Uninitialized_State_Factory::UNINITIALIZED_STATE_PTF ptf
        = iter->second;
      return (*ptf) ();
    }
}           

void 
Uninitialized_State::format (Tree_Context &context,
                             const std::string &new_format)
{
  // Call factory method to initialize the context state.
  context.state (Uninitialized_State_Factory::make_uninitialized_state 
	  (new_format));
}           

void 
Pre_Order_Uninitialized_State::make_tree (Tree_Context &tree_context,
                                          const std::string &expr)
{
}                

void 
Pre_Order_Initialized_State::print (Tree_Context &context,
                                    const std::string &format)
{
  Expression_Tree_State::print_tree (context.tree (), format, std::cout);
}

void 
Pre_Order_Initialized_State::evaluate (Tree_Context &context,
                                       const std::string &param)
{
  Expression_Tree_State::evaluate_tree (context.tree (), param, std::cout);
}

void 
Post_Order_Uninitialized_State::make_tree (Tree_Context &tree_context,
                                           const std::string &expr)
{
}                

void 
Post_Order_Initialized_State::print (Tree_Context &context,
                                     const std::string &format)
{
  Expression_Tree_State::print_tree (context.tree (), format, std::cout);
}

void 
Post_Order_Initialized_State::evaluate (Tree_Context &context,
                                        const std::string &param)
{
  Expression_Tree_State::evaluate_tree (context.tree (), "param", std::cout);
}

void 
Level_Order_Uninitialized_State::make_tree (Tree_Context &tree_context,
                                            const std::string &expr)
{
}                

void 
Level_Order_Initialized_State::print (Tree_Context &context,
                                      const std::string &format)
{
  Expression_Tree_State::print_tree (context.tree (), format, std::cout);
  
}

void 
Level_Order_Initialized_State::evaluate (Tree_Context &context,
                                         const std::string &param)
{
  Expression_Tree_State::evaluate_tree (context.tree (), param, std::cout);
}

void 
In_Order_Uninitialized_State::make_tree (Tree_Context &tree_context,
                                         const std::string &expr)
{
  Interpreter_Context context;
  Interpreter interpreter;

  tree_context.tree (interpreter.interpret (context, expr));

  context.print ();

  tree_context.state (new In_Order_Initialized_State);
}                

void 
In_Order_Initialized_State::print (Tree_Context &context,
                                   const std::string &format)
{
  print_tree (context.tree (), format, std::cout);
  
}

void 
In_Order_Initialized_State::evaluate (Tree_Context &context,
                                      const std::string &param)
{
  Expression_Tree_State::evaluate_tree (context.tree (), param, std::cout);
}

