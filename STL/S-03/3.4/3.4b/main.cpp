#include <iostream>
#include <deque>
using namespace std;

int main()  {
    deque<char> aDeck;

    for(size_t i = 0; i <5; i++)
        aDeck.push_back(i + 'A');

    cout << "Original sequence: ";
    for(char i : aDeck)
        cout << i << " ";
    cout << endl;

    deque<char>::iterator It1 = aDeck.begin() + 2; // Note random access
    auto It2 = aDeck.begin() + 3; // iterators here
    cout << "*It1: " << *It1 << ", ";
    cout << "*It2: " << *It2 << endl;
    cout << endl;

    aDeck.insert(It1, 'X');

    cout << "Sequence after insert: ";
    for(char i : aDeck)
        cout << i << " ";
    cout << endl;

    // These iterator dereferences may cause the program to crash since STL
    // does not implement “robust iterators”..
    cout << "*It1: " << *It1 << ", ";
    cout << "*It2: " << *It2 << endl;

    return 0;
}

