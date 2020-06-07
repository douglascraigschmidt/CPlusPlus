#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstring>
using namespace std;

int main() {
  vector<const char *> aVect {"One", "Two", "Three", "Four", "Five"};

  cout << "Sequence contains: ";
  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<const char *> (cout, " "));
  cout << endl
       << "Searching for \"Three\".\n";

  // use a pointer-to-function adaptor
  auto itr = find_if(aVect.begin(),
                     aVect.end(),
                     not1(bind2nd(ptr_fun(strcmp), "Three")));

  if (itr != aVect.end()) {
    cout << "Found it, so here is the rest of the story: ";
    copy (itr,
          aVect.end (),
          ostream_iterator<const char *> (cout, " "));
    cout << endl;
  }
  return 0;
}
