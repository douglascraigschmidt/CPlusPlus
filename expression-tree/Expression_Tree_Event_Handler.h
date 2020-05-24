#ifndef _EXPRESSION_TREE_EVENT_HANDLER_H_
#define _EXPRESSION_TREE_EVENT_HANDLER_H_

#include "Event_Handler.h"
#include "Expression_Tree_Context.h"
#include "Expression_Tree_Command_Factory.h"

/**
 * @class Expression_Tree_Event_Handler
 * @brief Provides an abstract interface for handling input events
 *        and commands associated with the expression tree application. 
 *
 *        This class plays the role of "event handler" in the Reactor
 *        pattern and defines methods for use in the Template Method
 *        pattern that is used to process user input commands. 
 *
 * @see   Verbose_Expression_Tree_Event_Handler and
 *        Macro_Command_Expression_Tree_Event_Handler.
 */
class Expression_Tree_Event_Handler : public Event_Handler
{
public:
  /// Constructor.
  Expression_Tree_Event_Handler (void);

  /// Dtor.
  virtual ~Expression_Tree_Event_Handler (void) = 0;

  /// Factory that creates the appropriate subclass of @a
  /// Expression_Tree_Event_Handler, i.e., @a
  /// Verbose_Expression_Tree_Event_Handler or @a
  /// Macro_Command_Expression_Tree_Event_Handler.
  static Expression_Tree_Event_Handler *make_handler (bool verbose);

  /// This method is called back by the reactor when input is
  /// available.  It is a template method that performs the sequence
  /// of steps associated with processing expression tree application
  /// commands.
  virtual void handle_input (void);

protected:
  /// This hook method is a placeholder for prompting the user for
  /// input.
  virtual void prompt_user (void) = 0;

  /// This hook method gets user input.
  virtual bool get_input (std::string &user_input);

  /// This hook method is a placeholder for making a command based on
  /// the user input.
  virtual Expression_Tree_Command make_command (const std::string &user_input) = 0;

  /// This hook method executes a command.
  virtual bool execute_command (Expression_Tree_Command &command);

  /// The context where the expression tree state resides.
  Expression_Tree_Context tree_context_;

  /// A factory for creating a command.
  Expression_Tree_Command_Factory command_factory_;
  
  /// Handle to last valid command that was executed.
  Expression_Tree_Command last_valid_command_;
};

/**
 * @class Verbose_Expression_Tree_Event_Handler
 * @brief Provides a concrete interface for verbosely handling input
 *        events associated with the expression tree application. 
 *
 *        This class plays the role of "concrete event handler" in the Reactor
 *        pattern and overrides several hook methods for use in the
 *        Template Method pattern. 
 */
class Verbose_Expression_Tree_Event_Handler 
  : public Expression_Tree_Event_Handler
{
public:
  /// Constructor.
  Verbose_Expression_Tree_Event_Handler (void);

  /// Dtor.
  virtual ~Verbose_Expression_Tree_Event_Handler (void);

protected:
  /// This hook method verbosely prompts the user for input.
  virtual void prompt_user (void);

  /// This hook method makes the appropriate command based on the user
  /// input.
  virtual Expression_Tree_Command make_command (const std::string &user_input);

private:
  /// Keeps track of whether we've prompted the user already.
  bool prompted_;
};

/**
 * @class Macro_Command_Expression_Tree_Event_Handler
 * @brief Provides a concrete interface for less verbosely handling input
 *        events associated with the expression tree application. 
 *
 *        This class plays the role of "concrete event handler" in the Reactor
 *        pattern and overrides several hook methods for use in the
 *        Template Method pattern. 
 */
class Macro_Command_Expression_Tree_Event_Handler 
  : public Expression_Tree_Event_Handler
{
public:
  /// Constructor.
  Macro_Command_Expression_Tree_Event_Handler (void);

  /// Dtor.
  virtual ~Macro_Command_Expression_Tree_Event_Handler (void);

protected:
  /// This hook method less verbosely prompts the user for input.
  virtual void prompt_user (void);

  /// This hook method makes the appropriate set of macro commands
  /// based on the user input.
  virtual Expression_Tree_Command make_command (const std::string &user_input);
};

#endif /* _EXPRESSION_TREE_EVENT_HANDLER_H_ */
