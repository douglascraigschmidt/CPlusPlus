#include <string>
#include "interpreters/Interpreter.h"
#include "interpreters/Interpreter_Impl.h"

Interpreter::Interpreter(Interpreter_Impl *impl)
  : interpreter_(impl) {
}

Interpreter::~Interpreter() = default;

Expression_Tree
Interpreter::interpret (const std::string &input) {
  return interpreter_->interpret(input);
}
