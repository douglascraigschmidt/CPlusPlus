#ifndef _POINT_H
#define _POINT_H

/**
 * The concept of a pair is essential for understanding how
 * associative containers work. A pair binds a key (known as the first
 * element) with an associated value (known as the second element).
 * In the library <utility> and included in other standard libraries
 * such as <map> there is a class called pair that implements the
 * mathematical idea of a Cartesian point. A pair is used to construct
 * maps and other associative data structures.
 *
 * Here we create a point class that wraps a pair.
 */
template<typename T1, typename T2>
class point {
public:
  /**
   * Pair constructor.
   */
  point(T1 x, T2 y);

  /**
   * x coordinate.
   */
  T1 &x;

  /**
   * y coordinate.
   */
  T2 &y;

private:
  // Represent the point as an STL pair.
  std::pair<T1, T2> pair_;
};

#include "point.cpp"

#endif /* _POINT_H */
