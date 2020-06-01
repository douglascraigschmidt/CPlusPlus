#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * A back_inserter() causes the container's push_back() operator to be
 * invoked in place of the assignment operator. This is the preferred
 * inserter for vectors. The argument passed to back_inserter is the
 * container itself.
*/

int main()    {
  vector <int> aVect;
  back_insert_iterator<vector <int>>  n (aVect);

  for (int i; cin >> i; *n++ = i)
    continue;

  // copy (istream_iterator<int>(cin), istream_iterator<int>(),
  //           back_inserter (aVect));

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<int> (cout, "\n"));
  return 0;
}
