#ifndef _MEMBLOCK_CPP
#define _MEMBLOCK_CPP

template<typename T, int N> void
memblock<T, N>::setmem(int x, T value) {
  memblock[x] = value;
}

template<typename T, int N> T
memblock<T, N>::getmem(int x) {
  return memblock[x];
}

#endif /* _MEMBLOCK_CPP */
