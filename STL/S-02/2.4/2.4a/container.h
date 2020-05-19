#ifndef _CONTAINER_H
#define _CONTAINER_H

template <typename T> 
class container { // class template
public:
  explicit container (const T &arg);
  T increase ();

private:
  T element;
};

#include "container.cpp"

#endif /* _CONTAINER_H */
