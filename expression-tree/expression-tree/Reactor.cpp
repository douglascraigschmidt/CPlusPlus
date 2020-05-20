#ifndef _REACTOR_CPP
#define _REACTOR_CPP

#include <algorithm>
#include <functional>

#include "Reactor.h"
#include "Event_Handler.h"

Reactor *
Reactor::instance_ = 0;

Reactor::Reactor (void)
  : run_event_loop_ (true)
{
}

/**
 * @class Remove_Handler_Adapter
 * @brief This functor implements the Adapter pattern so an @a
 *        Reactor's @a remove_input_handler() method can be called
 *        with the appropriate @a Event_Handler in the context of the
 *        @a std:for_each() algorithm.
 */
struct Remove_Handler_Adapter
{
  /// Remote @a event_handler from the singleton @a Reactor.
  bool operator () (Event_Handler *event_handler)
  {
    Reactor::instance ()->remove_input_handler (event_handler);
    return true;
  }
};

Reactor::~Reactor (void)
{
  std::for_each (dispatch_table_.begin (),
                 dispatch_table_.end (),
                 Remove_Handler_Adapter ());
}

Reactor *
Reactor::instance (void)
{
  if (Reactor::instance_ == 0)
    Reactor::instance_ = new Reactor;

  return Reactor::instance_;
}

void
Reactor::register_input_handler (Event_Handler *eh)
{
  dispatch_table_.push_back (eh);
}

void
Reactor::remove_input_handler (Event_Handler *eh)
{
  std::remove (dispatch_table_.begin (),
	       dispatch_table_.end (),
	       eh);
  eh->delete_this ();
}

void 
Reactor::run_event_loop (void)
{
  while (run_event_loop_)
    std::for_each (dispatch_table_.begin (),
                   dispatch_table_.end (),
                   std::mem_fun (&Event_Handler::handle_input));
}

void
Reactor::end_event_loop (void)
{
  run_event_loop_ = false;
}

#endif /* _REACTOR_CPP */
