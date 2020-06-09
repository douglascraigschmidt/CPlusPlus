#ifndef _ARGV_ITERATOR_H
#define _ARGV_ITERATOR_H

#include <iterator>

template <typename T>
class argv_iterator 
  : public std::iterator <std::forward_iterator_tag, T> {
public:
  argv_iterator () = default;

  argv_iterator (int argc, char **argv, int increment)
    : argc_ (argc),
      argv_ (argv),
      base_argv_ (argv),
      increment_ (increment) {}

  bool operator != (const argv_iterator &) {
    return argv_ != (base_argv_ + argc_);
  }

  T operator *() { 
    return T (argv_);
  }

  void operator++ () { 
    argv_ += increment_; 
  }

private:
  int argc_{};
  char **argv_{};
  char **base_argv_{};
  int increment_{};
};

#endif /* _ARGV_ITERATOR_H */
