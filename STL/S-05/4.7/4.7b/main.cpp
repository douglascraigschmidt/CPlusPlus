#include <vector>
#include <iostream>
using namespace std;
int main ()    {
    vector<int> v (1, 1);	//created a vector with one element: 1
    v.push_back (2);
    v.push_back (3);
    v.push_back (4); 			// vector v: 1 2 3 4

    // now create 2 iterators, they are random access iterators
    auto i = v.begin();
    auto j = i + 2; cout << *j << " ";

    i += 3; cout << *i << " ";
    j = i - 1; cout << *j << " ";
    j -= 2;
    cout << *j << " ";
    cout << v[1] << endl;

    (j < i) ? cout << "j < i" : cout << "not (j < i)"; cout << endl;
    (j > i) ? cout << "j > i" : cout << "not (j > i)"; cout << endl;

    i = j;
    i <= j && j <= i ? cout << "i and j equal" : cout << "i and j not equal";
    cout << endl;

    return 0;
}




