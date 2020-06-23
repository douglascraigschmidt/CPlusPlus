#ifndef _TREE_CONTEXT_H_
#define _TREE_CONTEXT_H_

#include <string>
#include <memory>

#include "Expression_Tree.h"
#include "Expression_Tree_State.h"
#include "Interpreter.h"

/**
 * @class Expression_Tree_Context
 * @brief Interface for the State pattern that is used to ensure that  
 *        commands are invoked according to the correct protocol. 
 * 
 *        Plays the role of the "context" class in the State pattern
 *        and delegates to the appropriate "state" subclass that
 *        performs the commands. 
 */
class Expression_Tree_Context
{
public:
  /// Constructor.
  Expression_Tree_Context ();

  /// Set the desired format to the designated @a new_format.
  void format (const std::string &new_format);

  /// Make an expression tree based on the designated @a expression
  /// using the previously designated format.
  void make_tree (const std::string &expression);

  /// Print the most recently created expression tree using the
  /// designated @a format.  
  void print (const std::string &format);

  /// Evaluate the "yield" of the most recently created expression
  /// tree using the designated @a format.  
  void evaluate (const std::string &format);

  /// Sets the variable to its corresponding value.
  void set (const std::string &key_value_pair);

  /// Return a pointer to the current @a Expression_Tree_State.
  [[nodiscard]] Expression_Tree_State *state () const;

  /// Set the current @a Expression_Tree_State to the designated @a
  /// new_state pointer.
  void state (Expression_Tree_State *new_state);

  /// Return a reference to the current @a Expression_Tree.
  Expression_Tree &tree ();

  /// Set the current @a Expression_Tree to the @a new_tree.
  void tree (const Expression_Tree &new_tree);

  /// Returns whether or not a successful format call has been called
  bool formatted() const { return formatted_; }

  /// Persistent interpreter context for variables. Our interpreter
  /// will change values inside of this, so I just stuck the variable
  /// in the public section. 
  Interpreter_Context int_context;

private:
  /// Keep track of the current state that we're in.  We use an @a
  /// std::auto_ptr to simplify memory management and avoid memory leaks.
  std::unique_ptr <Expression_Tree_State> state_;
  
  /// Current expression tree.
  Expression_Tree tree_;

  bool formatted_;
};

#endif /* _TREE_CONTEXT_ */
