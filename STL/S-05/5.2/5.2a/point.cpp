#ifndef _POINT_CPP
#define _POINT_CPP

/**
 * Pair constructor.
 */
template<typename T1, typename T2>
point<T1, T2>::point(T1 x, T2 y)
  : pair_(MOVE(x), MOVE(y)),
    x(pair_.first),
    y(pair_.second) {
}

#endif /* _POINT_CPP */
