/* -*- C++ -*- */
#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

#include <memory>

#include "commands/User_Command.h"
#include "commands/User_Command_Factory.h"

/**
 * @class Event_Handler
 *
 * @brief Provides an abstract interface for handling input events and
 *        commands associated with the expression tree application.
 *
 *        This class plays the role of "event handler" in the Reactor
 *        pattern and defines methods for use in the Template Method
 *        pattern that is used to process user input commands.
 *
 * @see Verbose_Mode_Event_Handler and Succinct_Mode_Event_Handler.
 */
class Event_Handler {
public:
  /// Constructor.
  Event_Handler ();

  /// Dtor.
  virtual ~Event_Handler ();

  /// Factory that creates the appropriate subclass of @a
  /// ET_Event_Handler, i.e., @a Verbose_Mode_ET_Event_Handler or @a
  /// Succinct_Mode_ET_Event_Handler.
  static std::unique_ptr<Event_Handler> make_handler (bool verbose);

  /// This method is called back by the reactor when input is
  /// available.  It is a template method that performs the sequence
  /// of steps associated with processing expression tree application
  /// commands.
  virtual void handle_input ();

protected:
  /// This hook method is a placeholder for prompting the user for
  /// input.
  virtual void prompt_user () = 0;

  /// This hook method gets user input.
  virtual bool get_input (std::string &user_input);

  /// This hook method is a placeholder for making a command based on
  /// the user input.
  virtual User_Command make_command (const std::string &user_input) = 0;

  /// This hook method executes a command.
  virtual bool execute_command (User_Command &command);

  /// The context where the expression tree state resides.
  Tree_Context tree_context_;

  /// A factory for creating a command.
  User_Command_Factory command_factory_;
  
  /// Handle to last valid command that was executed.
  User_Command last_valid_command_;
};

/**
 * @class Verbose_Mode_Event_Handler
 *
 * @brief Provides a concrete interface for verbosely handling input
 *        events associated with the expression tree application.
 *
 *        This class plays the role of "concrete event handler" in the
 *        Reactor pattern and overrides several hook methods for use
 *        in the Template Method pattern.
 */
class Verbose_Mode_Event_Handler
  : public Event_Handler {
public:
  /// Constructor.
  Verbose_Mode_Event_Handler ();

  /// Dtor.
  ~Verbose_Mode_Event_Handler () override;

protected:
  /// This hook method verbosely prompts the user for input.
  void prompt_user () override;

  /// This hook method makes the appropriate command based on the user
  /// input.
  User_Command make_command (const std::string &user_input) override;

private:
  /// Keeps track of whether we've prompted the user already.
  bool prompted_;
};

/**
 * @class Succinct_Mode_Event_Handler
 *
 * @brief Provides a concrete interface for less verbosely handling
 *        input events associated with the expression tree
 *        application.
 *
 *        This class plays the role of "concrete event handler" in the
 *        Reactor pattern and overrides several hook methods for use
 *        in the Template Method pattern.
 */
class Succinct_Mode_Event_Handler
  : public Event_Handler {
public:
  /// Constructor.
  Succinct_Mode_Event_Handler ();

  /// Dtor.
  ~Succinct_Mode_Event_Handler () override;

protected:
  /// This hook method less verbosely prompts the user for input.
  void prompt_user () override;

  /// This hook method makes the appropriate set of macro commands
  /// based on the user input.
  User_Command make_command (const std::string &user_input) override;
};

// Forward declaration.
class Reactor;

#endif /* _EVENT_HANDLER_H */
