#ifndef _GENERATE_DATA_H
#define _GENERATE_DATA_H

#include <vector>

template <typename T,
          template <typename ...> typename Container = std::vector>
static Container<T>
generate_data(int size, int biggest) {
  Container<T> data;
  generate_n(back_inserter(data),
             size,
             [biggest]() { return rand() % biggest; });
  return data;
}

#endif /* GENERATE_DATA_H */
