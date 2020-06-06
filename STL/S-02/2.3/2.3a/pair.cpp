#ifndef _PAIR_CPP
#define _PAIR_CPP

namespace my_pair {

#if PASS_BY_VALUE == 0
template<typename T>
pair<T>::pair(const T &f, const T &s)
  // Always use initialization semantics.
  : first(f),
    second(s) {
  /*
    // Avoid assignment semantics.
    first = f;
    second = s;
  */
}
#else
template<typename T>
pair<T>::pair (T f, T s)
  : first(MOVE(f)),
    second(MOVE(s)) {
}
#endif /* PASS_BY_VALUE */

template<typename T> T
pair<T>::max() {
  return first < second ? second : first;
}

}

#endif /* _TYPE_WRAPPER_H */
