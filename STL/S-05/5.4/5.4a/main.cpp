#include <list>
#include <iostream>
using namespace std;
int main()   {
    list<int> aList (1, 1);
    aList.push_back (2);

    list<int>::iterator first = aList.begin();
    auto last = aList.end();

    while (last != first) {
        --last;
        cout << *last << " "; // Could write this as cout << *--last << “”
    }

    return 0;
}

