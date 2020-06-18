#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

#include <algorithm>

/**
 * This sorting method works on random-access iterators.
 */
template<typename RandomAccessIterator, typename Compare>
void heap_sort(RandomAccessIterator first,
               RandomAccessIterator last,
               Compare comp) {
  make_heap(first, last, comp);
  sort_heap(first, last, comp);
}

#endif /* _HEAP_SORT_H */
