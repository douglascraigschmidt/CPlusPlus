#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main ()
{
    vector<int> v;
    
    for (istream_iterator<int> i (cin);
         i != istream_iterator<int> ();
         ++i)
        v.push_back (*i);

    /*
    copy (istream_iterator<int> (cin),
          istream_iterator<int>(),
          back_inserter(v));
          */
}





