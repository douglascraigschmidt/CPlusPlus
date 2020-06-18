#include <iostream>
#include <map>

#include "simple_string.h"

using namespace std;

typedef multimap <simple_string, simple_string> names_type;
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

int main(int argc, char* argv[]) {
  names_type names;  // create a multimap of names

  cout << "starting insert(&&)" << endl;
  // Put the names in the multimap
  names.insert(value_type("Kim", "Smith"));
  names.insert(value_type("Jane", "Smith"));
  names.insert(value_type("Kay", "Smith"));
  cout << "ending insert(&&)" << endl;

  cout << "starting emplace()" << endl;
  names.emplace("Kurt", "Jones");
  names.emplace("Kim", "Jones");
  names.emplace("John", "Jones");
  cout << "ending emplace()" << endl;

  cout << "starting emplace_hint()" << endl;
  auto iter = names.end();
  names.emplace_hint(iter, "Sophie", "Mackay");
  names.emplace_hint(iter, "Steve", "Mackay");
  names.emplace_hint(iter, "Kim", "Mackay");
  cout << "ending emplace_hint()" << endl;

  // print out the names
  cout << "All the names:" << endl << names << endl;

  return 0; 
}
