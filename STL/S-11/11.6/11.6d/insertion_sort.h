#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H

/**
 * This sorting method works on random-access iterators.
 */
template<typename RandomAccessIterator, typename Compare>
void insertion_sort(RandomAccessIterator begin,
                    RandomAccessIterator end,
                    Compare comp);

#include "insertion_sort.cpp"
#endif /* _INSERTION_SORT_H */
