#ifndef _MEMBLOCK_H
#define _MEMBLOCK_H

/**
 * In memblock below, int N is a non-typed template parameter.
 */
template <typename T, int N>  // typed param T, non-type param N
class memblock {
public:
  void setmem (int x, T value);
  T getmem (int x);
 
private:
  // set all the elements in memblock to 0.
  T memblock[N] = {0};
};

#include "memblock.cpp"

#endif /* _MEMBLOCK_H */
