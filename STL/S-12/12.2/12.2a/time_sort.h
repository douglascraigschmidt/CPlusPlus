#ifndef _TIME_SORT_H
#define _TIME_SORT_H

#include <vector>
#include <functional>
#include <string>
#include <chrono>
#include <iostream>
#include <cassert>

template<typename T,
         template <typename ...> typename Container = std::vector,
         typename Compare = std::less<T>>
static void
time_sort(const std::string& sort_name,
          Container<T> data,
          void (*sort_func)(typename Container<T>::iterator,
                            typename Container<T>::iterator,
                            Compare) = std::sort,
          Compare comp = std::less<T>()) {

  auto start = std::chrono::high_resolution_clock::now();
  (*sort_func)(data.begin(), data.end(), comp);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>
                  (stop - start);

  assert(is_sorted(data.begin(), data.end()));
  std::cout << sort_name << " results for size = "
            << data.size() << " = "
            << duration.count() << " microseconds" << std::endl;
}

#endif /* _TIME_SORT_H */
