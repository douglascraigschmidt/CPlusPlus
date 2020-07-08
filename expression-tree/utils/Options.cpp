#ifndef _OPTIONS_CPP_
#define _OPTIONS_CPP_

#include <iostream>
#include <cstdio>

#include "utils/getopt.h"
#include "Options.h"

// Initialize the singleton.
Options *
Options::instance_ = nullptr;

Options*
Options::instance () {
  // Create the options implementation if it hasn't already been done
  if (instance_ == nullptr)
    instance_ = new Options;

  return instance_;
}

// Ctor
Options::Options ()
  : verbose_ (false) {
}

// Dtor
Options::~Options () = default;

// Return exe name.
std::string
Options::exe () const {
  return exe_;
}

// Return path name.
std::string
Options::path () const {
  return path_;
}

bool
Options::verbose () const {
  return verbose_;
}

// Parse the command line arguments.
bool
Options::parse_args (int argc, char *argv[]) {
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
Options::print_usage () {
  std::cout << "\nHelp Invoked on " << path_ + exe_ << "\n\n";
  std::cout << "Usage: " << exe_ << " [-h|-v]\n\n" << 
    "  -h: invoke help\n" <<
    "  -v: enter verbose mode\n" <<
    "\n";
}

#endif /* _OPTIONS_CPP_ */
