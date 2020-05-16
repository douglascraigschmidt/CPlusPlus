#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main () {
    vector<int> v;
    copy (istream_iterator<int> (cin), istream_iterator<int>(),
          back_inserter(v));

    copy (v.begin (), v.end (),
          ostream_iterator<int> (cout, "\n"));

    /*
    for (vector<int>::iterator i = v.begin ();
         i != v.end ();
         ++i)
        cout << *i << endl;

    for (int & i : v)
        cout << i << endl; */
}
