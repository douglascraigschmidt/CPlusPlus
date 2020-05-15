#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    list<int> myList;

    myList.push_back(0);               // Insert a new element at the end
    myList.push_front(0);              // Insert a new element at the start
    myList.insert(++myList.begin(),2); // Insert "2" after first element
    myList.push_back(5);
    myList.push_back(6);

    for (auto i : myList)
      cout << i << ' ';

    cout << endl;   return 0;
}


