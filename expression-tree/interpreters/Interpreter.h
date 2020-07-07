/* -*- C++ -*- */
#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include "trees/Expression_Tree.h"

// Forward declaration.
class Expr;
class Interpreter_Impl;

/**
 * @class Interpreter
 *
 * @brief Parses incoming expression strings into a parse tree and
 *        generates an expression tree from the parse tree.
 *
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor" that
 *        performs the interpreter operations.
 */
class Interpreter {
public:
  /// Constructor.
  explicit Interpreter (Interpreter_Impl *impl);

  /// destructor
  virtual ~Interpreter ();

  /// Converts a string into a parse tree and builds an expression
  /// tree out of the parse tree.
  Expression_Tree interpret (const std::string &input);

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management.
  Refcounter<Interpreter_Impl> interpreter_;
};

#endif /* _INTERPRETER_H */

