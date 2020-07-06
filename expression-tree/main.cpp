#include <iostream>
#include <functional>
#include <algorithm>
#include <memory>

#include "utils/Options.h"
#include "input/Reactor.h"
#include "input/Event_Handler.h"

int 
main (int argc, char *argv[])
{
  // Create Options singleton to parse command line options.
  std::unique_ptr<Options> options (Options::instance ());

  // Parse the command-line options. 
  if (!options->parse_args (argc, argv))
    return 0;

  // Create Reactor singleton to run application event loop.
  std::unique_ptr<Reactor> reactor (Reactor::instance ());

  // Dynamically allocate the appropriate event handler based on the
  // command-line options and register this event handler with the
  // reactor, which is responsible for triggering the deletion of
  // the event handler.
  reactor->register_input_handler
    (Event_Handler::make_handler (options->verbose ()));

  // Run the reactor's event loop, which drives all the processing via
  // callbacks to registered event handlers.
  reactor->run_event_loop ();

  // The std::unique_ptr destructors automatically destroy the
  // singletons.
  return 0;
}
