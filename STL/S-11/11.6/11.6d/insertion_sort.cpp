/**
 * This sort() method is specialized for vectors of int.
 */
template<typename RandomAccessIterator,
         typename Compare>
void insertion_sort(RandomAccessIterator begin,
                    RandomAccessIterator end,
                    Compare comp) {
  for (auto sorted = end - 1;
       sorted != begin; 
       --sorted) {
    auto next = sorted - 1;
    int value = *next;
    for (auto itr = sorted;
         itr != end; 
         ++itr, ++next) {
      if (comp(value, *itr))
        break;

      *next = *itr;
    }
    *next = value;
  } 
}

