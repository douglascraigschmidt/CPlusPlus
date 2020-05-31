#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>

using namespace std;

/**
 * A multimap is an ordered associative container that associates key
 * objects with value objects.  It is called a pair associative
 * container because its value type is actually implemented as
 * pair<const Key, Value>.
 *
 * For a multimap keys don't have to be unique. Nor do the keys have
 * to be integers, so maps are multimaps are more general than a
 * sequential container such as vector, deque, or list.
 * 
 * template <typename Key,
 *           typename Value, 
 *           typename Compare = less<Key>,
 *           typename Allocator = allocator <pair<const Key, Value>>
 * class multimap;
 */

#include <string>
#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

typedef multimap <string, string> names_type;
typedef names_type::value_type value_type;

/**
 * Functor.
 */
struct print {
  explicit print(ostream& out) : os (out) {}

  void operator() (const names_type::value_type &p) {
    os << p.first << " belongs to the " << p.second << " family\n";
  }

  ostream& os;
};

/**
 * Insertion operator prints out contents of a multimap.
 */
ostream& operator<<(ostream& out, const names_type &l) {
  for_each (l.begin (), l.end (), print (out));

  return out;
}

/**
 * Insertion operator prints out contents of a pair.
 */
ostream &operator << (ostream &out, 
                      const pair<names_type::iterator,
                                 names_type::iterator> &p) {
  for_each (p.first, p.second, print (out));

  return out;
}

int main(int argc, char* argv[]) {
  names_type names;  // create a multimap of names

  // Put the names in the multimap
  names.insert(value_type("Kim", "Smith"));
  names.insert(value_type("Jane", "Smith"));
  names.insert(value_type("Kay", "Smith"));

  auto iter = names.end();
  names.insert(iter, value_type("Kurt", "Jones"));
  names.insert(iter, value_type("John", "Jones"));
  names.insert(iter, value_type("Kim", "Jones"));

  vector<value_type> mackay_names{ value_type("Sophie", "Mackay"),
                                   value_type("Steve", "Mackay"),
                                   value_type("Kim", "Mackay") };

  names.insert(mackay_names.begin(), mackay_names.end());

  // print out the names
  cout << "All the names:" << endl << names << endl;

  // Find the people named Kim
  pair<names_type::iterator,names_type::iterator> p =
    names.equal_range ("Kim");

  // print them out 
  cout << names.count("Kim") << " People called Kim:"
       << endl << p << endl;

  // Erase all people called Sue.
  names.erase(p.first, p.second);

  // print out the names
  cout << "All the names:" << endl << names << endl;

  iter = names.find("Kurt");

  if (iter == names.end())
    cout << "Kurt not found" << endl;
  else
    cout << "Kurt's last name is " << iter->second << endl;

  return 0; 
}
