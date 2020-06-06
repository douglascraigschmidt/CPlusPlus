#include <type_traits>

/**
 * Here is an example using two function templates, one that has two
 * parameters of a given datatype and the other that has three of a
 * given datatype.
 */
template <typename T>
T min (T p1, T p2) {
  if (p1 < p2)
    return p1;
  else
    return p2;
  // Could also use
  // return p1 < p2 ? p1 : p2;
}

template <typename T>
T min (T p1, T p2, T p3) {
  if (min (p1, p2) < p3) // notice this calls the function
    return min (p1, p2); // so does this line
  else
    return p3;
}

/**
 * A generic function that finds minimum of two values and whose return
 * type is type of variable that has the higher precision.
 */
template <typename A, typename B>
auto min_ex(A a, B b) -> 
  typename std::remove_reference<decltype(a < b ? a : b)>::type {
  return a < b ? a : b; 
}
