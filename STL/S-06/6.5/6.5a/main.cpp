#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>

int main (void) {
  list<string> my_list;
  copy(istream_iterator<string>(cin),
       istream_iterator<string>(),
       // Essentially front_inserter()
       inserter(my_list, my_list.begin())); 

  copy(my_list.begin(),
       my_list.end(),
       ostream_iterator<string>(cout, "\n"));

  return 0;
}
