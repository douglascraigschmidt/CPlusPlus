/* -*- C++ -*- */
#ifndef _OPTIONS_H_
#define _OPTIONS_H_

// This header defines "size_t"
#include <stdlib.h>

#include <stdexcept>

/**
 * @class Options
 * @brief Defines a singleton class to handle command-line option
 *        processing. 
 *
 *        This class implements the Singleton pattern since there's a
 *        need for just one set of command-line options. 
 */
class Options
{
public:
  /// Method to return the one and only instance.
  static Options *instance (void);

  /// Destructor
  ~Options (void);

  /// This returns the queue type specified on the command line.

  /// This returns the exe name, passed in through the command line.
  std::string exe (void) const;

  /// This returns the path, passed in through the command line.
  std::string path (void) const;

  /// Run the program in verbose mode.
  bool verbose (void) const;

  /// Parse command-line arguments and set the appropriate values as
  /// follows:
  /// 't' - Traversal strategy, i.e., 'P' for pre-order, 'O' for
  /// post-order, 'I' for in-order, and 'L' for level-order.
  /// 'q' - Type of queue, i.e., either 'L' for LQeuue or 'A' for AQueue.
  bool parse_args (int argc, char *argv[]);

  /// Print out usage and default values.
  void print_usage (void);

private:
  /// Make the constructor private for a singleton.
  Options (void);

  /// Values for parameters passed in on the command line.
  std::string exe_;
  std::string path_;

  /// Are we running in verbose mode or not?
  bool verbose_;

  /// Pointer to the singleton @a Options instance.
  static Options *instance_;
};

#endif /* _OPTIONS_H_ */
