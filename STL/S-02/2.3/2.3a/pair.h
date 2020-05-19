#ifndef _PAIR_H
#define _PAIR_H

/**
 * Create a namespace so we can reuse the name "pair", which also
 * appears in the std namespace.
 */
namespace my_pair {
  /**
   * If a set of functions or classes have the same functionality for
   * different data types, this becomes a good class template. The class
   * can also hold state data about itself. A class template can be
   * implemented in C++ as either a class or a struct. A struct behaves
   * much like a class does, except that its data/methods are public by
   * default, whereas data/methods for a class are private by default.
   * This template class stores two elements of any valid datatype.
   */
  template<typename T>
  class pair {
  public:
#if PASS_BY_VALUE == 0
    pair(const T &f, const T &s);
#else
    pair (T f, T s);
#endif /* PASS_BY_VALUE */

    T max();

    T first;
    T second;
  };
}

#include "pair.cpp"

#endif /* _PAIR_H */
