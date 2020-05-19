#ifndef _CONTAINER_CPP
#define _CONTAINER_CPP

template <typename T> 
container<T>::container (const T &arg)
  : element (arg) {}

template <typename T> T
container<T>::increase () { 
  return ++element; 
}

#endif /* _CONTAINER_CPP */
