#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

/**
 * An unordered_map is a unordered associative container that
 * associates key objects with value objects.  It is called a pair
 * associative container because its value_type is actually
 * implemented as pair<const Key, Value>.  For an unordered_map, keys
 * must be unique. The keys don’t have to be integers, so an
 * unordered_map is more general than a sequential container such as
 * vector, deque, or list.
 *
 * template <typename Key,
 *           typename Value,
 *           class Hash = hash<Key>,
 *           class Pred = std::equal_to<Key>,
 *           typename Allocator = allocator <pair<const Key, Value>> >
 * class unordered_map { ... };
 * 
 * Characteristics of unordered_map
 * . Inserting a new element into an unordered_map does not invalidate
 *   iterators that point to existing elements.
 *
 * . Erasing an element from an unordered_map also does not invalidate
 *   any iterators, except those iterators that actually point to the
 *   element that is being erased. 
 * 
 * To use an unordered_map you must supply a key type and data type.
 * You can also choose to provide a unary function object that acts as
 * a hash function for a key, which takes a single object of type key
 * and returns a value of type std::size_t.  You can also optionally
 * provide a binary function object that implements an equivalent
 * relation on values of type key, which takes two arguments of type
 * key and returns a value of type bool:
 * 
 * map <key_type, data_type [, hash_function_object], [predicate_function_object]>
 */
int main () {
  // Note initializer list.
  std::vector<std::string> word_list {"now", "is", "the", "time", 
                                      "for", "all", "good", "people",
                                      "to", "come", "to", "the", 
                                      "aid", "of", "their", "party"};

  typedef std::unordered_map<std::string, int> WORD_MAP;
  WORD_MAP word_map; // Map of words and their frequencies.

  // Use range-based for loop to count the number of times each word
  // appears in the word_list.
  for (auto const &word : word_list)
    ++word_map[word];

  // Print out the word_map.  Note auto type deduction.
  for (auto const &i : word_map)
    std::cout << i.second << " " << i.first << std::endl; 

  std::vector<std::pair <std::string, int>> v (word_map.begin(),
                                               word_map.end());

  // for (auto const &i : word_map) v.emplace_back(i);

  // std::copy (word_map.begin (), word_map.end (), std::back_inserter (v));

  std::sort (v.begin (),
             v.end (),
             std::greater<> ());

  std::cout << std::endl;

  // Print out the sorted vector.  Note auto type deduction.

  for (auto const &i : v) 
    std::cout << i.second << " " << i.first << std::endl; 

  auto total = 0;

  // Count the total number of words in the map.
  for_each (word_map.begin(),
            word_map.end(),
            [&total] (const WORD_MAP::value_type &p) { 
              total += p.second;
            });

  std::cout << "total number of words = " << total << std::endl;
  return 0;
}
