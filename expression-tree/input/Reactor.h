/* -*- C++ -*- */
#ifndef _REACTOR_H
#define _REACTOR_H

#include <vector>
#include <memory>

// Forward declarations.
class Event_Handler;

/**
 * @class Reactor
 *
 * @brief An object-oriented event demultiplexor and dispatcher of
 *        event handler callback methods in response to input events.
 *
 *        This class plays the role of the "reactor" in the Reactor
 *        pattern.  It is access as a singleton and uses the Iterator
 *        pattern to dispatch the various event handlers.
 */
class Reactor {
public:
  /// Singleton access point.
  static Reactor *instance ();

  /// Dtor.
  ~Reactor ();

  /// Run the reactor's event loop.
  void run_event_loop ();

  /// End the reactor's event loop.
  void end_event_loop ();

  /// Register @a event_handler for input events.
  void register_input_handler (std::unique_ptr<Event_Handler> event_handler);

  /// Remove @a event_handler for input events.
  void remove_input_handler (std::unique_ptr<Event_Handler> event_handler);
        
private:
  /// Constructor is private to ensure use as a singleton.
  Reactor ();

  /// Pointer to the singleton instance of the @a Reactor.
  static Reactor *instance_;

  /// Vector of unique_ptrs to @a Event_Handler objects used to
  /// dispatch callbacks.
  std::vector <std::unique_ptr<Event_Handler>> dispatch_table_;

  /// Keeps track of whether we're running the event loop or not.
  bool run_event_loop_;
};

#endif /* _REACTOR_H */
