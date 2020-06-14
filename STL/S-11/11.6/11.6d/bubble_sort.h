#ifndef _BUBBLE_SORT_H 
#define _BUBBLE_SORT_H 

/**
 * This sorting method works on bidirectional iterators.
 */
template<typename BiDirectionalIterator,
         typename Compare>
void bubble_sort(BiDirectionalIterator begin,
                 BiDirectionalIterator end,
                 Compare comp);
                 
#include "bubble_sort.cpp"
#endif /* _BUBBLE_SORT_H */                 
