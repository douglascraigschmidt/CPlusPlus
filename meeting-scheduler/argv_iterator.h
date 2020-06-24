#ifndef _ARGV_ITERATOR_H
#define _ARGV_ITERATOR_H

#include <iterator>

/**
 * An adapter class that converts argc/argv into instances of the
 * template parameter T that can be used as a forward iterator.
 */
template <typename T>
class argv_iterator : public std::iterator <std::forward_iterator_tag, T> {
public:
  /**
   * Default constructor.
   */
  argv_iterator ()
    : argc_ (0),
      argv_ (nullptr),
      base_argv_ (nullptr),
      increment_ (0) {}

  /**
   * This constructor stores the argc and argv parameters, together
   * with the number of argv parameters to convert into an instance
   * of type parameter T.
   */
  argv_iterator (int argc, char **argv, int increment)
    : argc_ (argc),
      argv_ (argv),
      base_argv_ (argv),
      increment_ (increment) {}

  /**
   * This method returns true as long as the iterator hasn't consumed
   * all the arguments from the input.
   */
  bool operator != (const argv_iterator &) {
    return argv_ != (base_argv_ + argc_);
  }

  /**
   * This overloaded dereference operator creates an instance of
   * parameterized type T by calling its constructor with the current
   * value of argv_.  Parameterized type T must have a constructor
   * that converts argv_ into the appropriate concrete types.
   */
  T operator *() { 
    return T (argv_);
  }

  /**
   * This overloaded operator skips forward over the argv parameters
   * by the increment designated in the constructor.
   */
  void operator++ () { 
    argv_ += increment_; 
  }

private:
  /**
   * The number of argv elements to process.
   */
  int argc_;

  /**
   * The argv elements themselves.
   */
  char **argv_;

  /**
   * The original starting point for argv.
   */
  char **base_argv_;

  /**
   * The number of argv elements to skip on each call to operator++.
   */
  int increment_;
};

#endif /* _ARGV_ITERATOR_H */

