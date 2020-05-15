#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// An example of a deque with its const iterator
template <typename T>
void print(const deque<T> &d) {
    cout << "The number of items in the deque:" << d.size() << endl;

    for (auto iter = d.begin(); iter != d.end(); ++iter)
        cout << *iter << " ";

    cout << endl << endl;
}

int main() {
    deque<int> aDeck;
    aDeck.push_back(3);
    aDeck.push_front(1);
    aDeck.insert(aDeck.begin() + 1, 2);
    aDeck[2] = 0;
    print(aDeck);
    return 0;
}


