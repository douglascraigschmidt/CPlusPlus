// -std=c++0x
#include <iostream>
#include <initializer_list>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main () 
{
  // Note initializer list.
  std::vector<std::string> word_list ({"now", "is", "the", "time", 
                                       "for", "all", "good", "people",
                                       "to", "come", "to", "the", 
                                       "aid", "of", "their", "party"});
  // typedef std::unordered_map<std::string, int> WORD_MAP;
  typedef std::map<std::string, int> WORD_MAP;
  WORD_MAP word_map; // Map of words and their frequencies.

#if 0
  for (WORD_MAP::iterator word_iter = word_list.begin ();
       word_iter != word_list.end ();
       ++word_iter)
    ++word_map[*word_iter];

  // Count the number of times each word appears in the word_list.
  // Note auto type deduction.
  for (auto const &word_iter = word_list.begin ();
       word_iter != word_list.end ();
       ++word_iter)
    ++word_map[*word_iter];
#endif

  // Use range-based for loop to count the number of times each word
  // appears in the word_list.  Note auto type deduction.
  for (auto const &word : word_list)
    ++word_map[word];

  // Print out the word_map.  Note auto type deduction.
  for (auto const &i : word_map)
    std::cout << i.second << " " << i.first << std::endl; 

#if 0
  std::vector<std::pair <std::string, int>> v;

  for (auto const &i : word_map)
    v.push_back (i);

  // std::copy (word_map.begin (), word_map.end (), std::back_inserter (v));

  std::sort (v.begin (), v.end (), std::greater<std::pair <std::string, int>> ());

  std::cout << std::endl;

  // Print out the sorted vector.  Note auto type deduction.

  for (auto const &i : v) 
    std::cout << i.second << " " << i.first << std::endl; 
#endif

  // Note auto type deduction.
  auto total = 0;

#if 0
  struct total_it {
    total_it (int i): i_ (i) {}

    void operator()(const WORD_MAP::value_type &p) {
      i_ += p.second;
    }

    int i_; 
  };

  // Count the total number of words in the map.  Note use of
  // std::for_each() with lamba expressions.
  total_it it = for_each (word_map.begin(),
                          word_map.end(), 
                          total_it (total));
  total = it.i_;
#endif

  // Count the total number of words in the map.  Note use of
  // std::for_each() with lamba expressions.
  for_each (word_map.begin(),
            word_map.end(),
            [&total] (const WORD_MAP::value_type &p) { 
              total += p.second;
            }
            );

  std::cout << "total number of words = " << total << std::endl;
  return 0;
}
