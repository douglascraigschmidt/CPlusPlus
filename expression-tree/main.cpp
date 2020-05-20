#include <iostream>
#include <functional>
#include <algorithm>
#include <memory>

#include "Options.h"
#include "Reactor.h"
#include "Expression_Tree_Event_Handler.h"

int 
main (int argc, char *argv[])
{
  // Create Options singleton to parse command line options.
  std::auto_ptr<Options> options (Options::instance ());

  // Parse the command-line options. 
  if (!options->parse_args (argc, argv))
    return 0;

  // Create Reactor singleton to run application event loop.
  std::auto_ptr<Reactor> reactor (Reactor::instance ());

  // Dynamically allocate the appropriate event handler based on the
  // command-line options.
  Expression_Tree_Event_Handler *tree_event_handler = 
    Expression_Tree_Event_Handler::make_handler (options->verbose ());

  // Register the event handler with the reactor.  The reactor is
  // responsible for triggering the deletion of the event handler
  reactor->register_input_handler (tree_event_handler);

  // Run the reactor's event loop, which drives all the processing via
  // callbacks to registered event handlers.
  reactor->run_event_loop ();

  // The std::auto_ptr destructors automatically destroy the
  // singletons.
  return 0;
}
