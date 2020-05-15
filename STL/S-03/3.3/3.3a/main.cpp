#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int  main()
{
    vector<int> v(3);
    v[0] = 7;
    v[1] = v[0] + 3;
    v[2] = v[0] + v[1];                  // v[0] == 7, v[1] == 10, v[2] == 17

    // print elements separated by a space
    for (int i=0; i< v.size() ; ++i)
        cout << v[i] << ' ';

    cout << endl;

    v.resize(0);

    // append elements with values 0-6
    for (int i=0; i < 7; ++i)
        v.push_back(i);

    // Another way to print elements separated by a space
    for (int i : v)
        cout << i << ' ';

    cout << endl;
    return 0;
}

