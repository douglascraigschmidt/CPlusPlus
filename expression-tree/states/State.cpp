#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "Tree_Context.h"
#include "iterators/Iterator.h"
#include "visitors/Print_Visitor.h"
#include "visitors/Evaluation_Visitor.h"
#include "trees/Expression_Tree.h"

/// this method traverses the tree in with a given traversal strategy
void 
State::print_tree (const Expression_Tree &tree,
                   const std::string &traversal_order,
                   std::ostream &os) {
  os << "traverse tree using strategy '" << traversal_order
     << "':" << std::endl;
  
  // create a print visitor
  Print_Visitor print_visitor;

  // std::for_each() is a short-hand for writing the following loop:
  for (auto iter = tree.begin (traversal_order);
       iter != tree.end (traversal_order);
       ++iter)
    iter->accept (print_visitor);

#if 0
  std::for_each (tree.begin (traversal_order),
                 tree.end (traversal_order),
                 [&print_visitor] (auto tree)
                 {
                   tree.accept (print_visitor);
                 });
#endif

  os << std::endl;
}

void 
State::evaluate_tree (const Expression_Tree &tree,
                      const std::string &traversal_order,
                      std::ostream &os) {
  // os << "Evaluating tree using strategy '" << traversal_order
  // << "':" << std::endl;

  Evaluation_Visitor evaluation_visitor;
  // Visitor visitor = Visitor_Factory.make_visitor("Evaluation_Visitor");
  
  std::for_each (tree.begin (traversal_order),
                 tree.end (traversal_order),
                 [&evaluation_visitor](const Expression_Tree &t) {
                   t.accept(evaluation_visitor);
                 });

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
State::format (Tree_Context &,
               const std::string &) {
  throw State::Invalid_State ("State::format called in invalid state");
}           

void 
State::expr (Tree_Context &,
             const std::string &) {
  throw State::Invalid_State ("State::expr called in invalid state");
}                

void 
State::print (Tree_Context &,
              const std::string &) {
  throw State::Invalid_State ("State::print called in invalid state");
}

void 
State::evaluate (Tree_Context &,
                 const std::string &) {
  throw State::Invalid_State ("State::evaluate called in invalid state");
}

// Static data member definitions.
Uninitialized_State::Uninitialized_State_Factory::UNINITIALIZED_STATE_MAP 
Uninitialized_State::Uninitialized_State_Factory::uninit_state_map_;

Uninitialized_State::Uninitialized_State_Factory 
Uninitialized_State::uninitialized_state_factory;

Uninitialized_State::Uninitialized_State_Factory::Uninitialized_State_Factory () {
  uninit_state_map_["in-order"]
    = &Uninitialized_State::Uninitialized_State_Factory::make_in_order_uninitialized_state;
  uninit_state_map_["pre-order"]
    = &Uninitialized_State::Uninitialized_State_Factory::make_pre_order_uninitialized_state;
  uninit_state_map_["post-order"]
    = &Uninitialized_State::Uninitialized_State_Factory::make_post_order_uninitialized_state;
  uninit_state_map_["level-order"]
    = &Uninitialized_State::Uninitialized_State_Factory::make_level_order_uninitialized_state;
}

State *
Uninitialized_State::Uninitialized_State_Factory::make_level_order_uninitialized_state () { 
  return new Level_Order_Uninitialized_State ();
}

State *
Uninitialized_State::Uninitialized_State_Factory::make_in_order_uninitialized_state () { 
  return new In_Order_Uninitialized_State ();
}

State *
Uninitialized_State::Uninitialized_State_Factory::make_pre_order_uninitialized_state () { 
  return new Pre_Order_Uninitialized_State ();
}

State *
Uninitialized_State::Uninitialized_State_Factory::make_post_order_uninitialized_state () { 
  return new Post_Order_Uninitialized_State ();
}

State *
Uninitialized_State::Uninitialized_State_Factory::make_uninitialized_state (const std::string &format) {
  auto iter = uninit_state_map_.find (format);

  if (iter == uninit_state_map_.end ())
    // We don't understand the type. Convert the type to a string and
    // pass it back via an exception
    throw Expression_Tree::Invalid_Iterator (format);
  else
    return (*iter->second) ();
}           

void 
Uninitialized_State::format (Tree_Context &context,
                             const std::string &new_format) {
  // Call factory method to initialize the context state.
  context.state (Uninitialized_State_Factory::make_uninitialized_state 
                 (new_format));
}

void 
Post_Order_Uninitialized_State::expr (Tree_Context &tree_context,
                                      const std::string &expr) {
  Interpreter interpreter
    (new Post_Order_Interpreter
     (tree_context.interpreter_context_));

  tree_context.tree (interpreter.interpret (expr));

  tree_context.state (new Post_Order_Initialized_State);
}                

void 
Post_Order_Initialized_State::print (Tree_Context &context,
                                     const std::string &format) {
  State::print_tree (context.tree (), format, std::cout);
}

void 
Post_Order_Initialized_State::evaluate (Tree_Context &context,
                                        const std::string &param) {
  State::evaluate_tree (context.tree (), param, std::cout);
}

void 
In_Order_Uninitialized_State::expr (Tree_Context &tree_context,
                                    const std::string &expr) {
  Interpreter interpreter
    (new In_Order_Interpreter
       (tree_context.interpreter_context_));

  tree_context.tree (interpreter.interpret (expr));

  tree_context.state (new In_Order_Initialized_State);
}                

void 
In_Order_Initialized_State::print (Tree_Context &context,
                                   const std::string &format) {
  State::print_tree (context.tree (), format, std::cout);
  
}

void 
In_Order_Initialized_State::evaluate (Tree_Context &context,
                                      const std::string &param) {
  State::evaluate_tree (context.tree (), param, std::cout);
}


void
Pre_Order_Uninitialized_State::expr (Tree_Context &context,
                                     const std::string &expression) {
}

void
Pre_Order_Initialized_State::print (Tree_Context &context,
                                    const std::string &format) {
    State::print_tree (context.tree (), format, std::cout);
}

void
Pre_Order_Initialized_State::evaluate (Tree_Context &context,
                                       const std::string &param) {
    State::evaluate_tree (context.tree (), param, std::cout);
}


void
Level_Order_Uninitialized_State::expr (Tree_Context &tree_context,
                                       const std::string &expr) {
}

void
Level_Order_Initialized_State::print (Tree_Context &context,
                                      const std::string &format) {
    State::print_tree (context.tree (), format, std::cout);
}

void
Level_Order_Initialized_State::evaluate (Tree_Context &context,
                                         const std::string &param) {
    State::evaluate_tree (context.tree (), param, std::cout);
}