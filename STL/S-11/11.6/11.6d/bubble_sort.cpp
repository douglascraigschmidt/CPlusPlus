/**
 * This sorting method works on bidirectional iterators.
 */
template<typename BiDirectionalIterator,
         typename Compare>
void bubble_sort(BiDirectionalIterator first,
                 BiDirectionalIterator last,
                 Compare comp) {
  BiDirectionalIterator leftElement = first, rightElement = first;
  rightElement++;
  while (first != last) {
    while (rightElement != last) {
      if (comp(*rightElement, *leftElement)) 
        iter_swap (leftElement, rightElement);
      rightElement++;
      leftElement++;
    }
    last--;
    leftElement = first, rightElement = first;
    rightElement++;
  }
}

