#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> aList;
    for(int i = 0; i <10; i++)
        aList.push_back('A'+i);

    cout << "Size = " << aList.size() << endl;
    cout << "Contents: ";

    while (!aList.empty ()) {
        auto p = aList.begin();
        cout << *p;
        aList.pop_front();
    }
    return 0;
}



