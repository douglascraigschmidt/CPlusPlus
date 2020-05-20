#ifndef _OPTIONS_CPP_
#define _OPTIONS_CPP_

#include <iostream>
#include <stdio.h>

#include "getopt.h"
#include "Options.h"
#include "LQueue.h"
#include "LStack.h"
#include "Typedefs.h"

// Initialize the singleton.
Options *
Options::instance_ = 0;

Options*
Options::instance ()
{
  // Create the options implementation if it hasn't already been done

  if (instance_ == 0)
    instance_ = new Options;

  return instance_;
}

// Ctor
Options::Options (void)
  : verbose_ (false)
{
}

// Dtor
Options::~Options (void)
{
  // call free_list_release to clean up our preallocated LQueue_Nodes
  LQueue_Node<Component_Node *>::free_list_release ();
  LQueue_Node<int>::free_list_release ();
  LStack_Node<Component_Node *>::free_list_release ();  
  LStack_Node<int>::free_list_release ();  
}

// Return exe name.
std::string
Options::exe (void) const
{
  return exe_;
}

// Return path name.
std::string
Options::path (void) const
{
  return path_;
}

bool
Options::verbose (void) const
{
  return verbose_;
}

// Parse the command line arguments.
bool
Options::parse_args (int argc, char *argv[])
{
  // set exe_ to the first arg.
  exe_ = parsing::getfilename (argv[0]);
  path_ = parsing::getpath (argv[0]);
  char opts[] = "h?v";

  for (int c;
       (c = parsing::getopt (argc, argv, opts)) != EOF;
       )
    switch (c)
      {
        // check to see if the user asked for help
      case 'v':
        verbose_ = true;
        break;
      case 'h':
      case '?':
        print_usage ();
        return false;
        break;
      default:
        break;
      }

  return true;
};

// Parse the command line arguments.
void
Options::print_usage (void)
{
  std::cout << "\nHelp Invoked on " << path_ + exe_ << "\n\n";
  std::cout << "Usage: " << exe_ << " [-h|-v]\n\n" << 
    "  -h: invoke help\n" <<
    "  -v: enter verbose mode\n" <<
    "\n";
}

#endif /* _OPTIONS_CPP_ */
