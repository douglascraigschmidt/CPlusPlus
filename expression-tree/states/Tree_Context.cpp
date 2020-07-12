#include <cstdlib>

#include "Tree_Context.h"

Tree_Context::Tree_Context (void)
  : state_ (new Uninitialized_State), formatted_(false)
{
}

void
Tree_Context::format (const std::string &new_format)
{
  state_->format (*this, new_format);

  // we only reach here if the format was successful, and once
  // this is set, we will always have at least one valid format
  // because we store the last valid command (which would have
  // a valid format, if this format function has ever been successfully ran
  formatted_ = true;
}

void
Tree_Context::expr (const std::string &expression)
{
    state_->expr(*this, expression);
}

void
Tree_Context::print (const std::string &format)
{
  state_->print (*this, format);
}

void
Tree_Context::evaluate (const std::string &format)
{
  state_->evaluate (*this, format);
}

void
Tree_Context::set (const std::string &key_value_pair) {
  // We'll just go ahead and parse all of this now.
  std::string input = key_value_pair;

  // Used to keep track of characters found.
  std::string::size_type pos;

  // Get rid of all whitespaces
  while ((pos = input.find (' ')) != std::string::npos)
    input.erase(pos, 1);

  // input should be key=value
  if ((pos = input.find ('=')) != std::string::npos) {
    // if the position is not the first char (eg '=value') and
    // position is not the last char (eg 'key=') then split the string
    // and set the interpreter context accordingly
    if (pos != 0 && pos < input.length() - 1) {
      std::string key = input.substr(0,pos);
      std::string value = input.substr(pos+1);

      interpreter_context_.set (key, ::atoi (value.c_str ()));
    } else
      throw std::domain_error("Must be in the form key=value");
  }
  else throw std::domain_error("Must have = sign present");
}

State *
Tree_Context::state () const
{
  return state_.get ();
}

void
Tree_Context::state (State *state)
{
  state_.reset (state);
}

Expression_Tree &
Tree_Context::tree ()
{
  return tree_;
}

void
Tree_Context::tree (const Expression_Tree &t)
{
  tree_ = t;
}
