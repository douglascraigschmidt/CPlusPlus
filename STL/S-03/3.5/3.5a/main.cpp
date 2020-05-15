#include <deque>
#include <iostream>
using namespace std;

int main( ) {
    deque <float> myDeck;

    // can also use the push_back( )
    for (size_t i=0; i < 7; i++)
        myDeck.push_front(i * 1.1);

    for (size_t i=0; i < myDeck.size(); i++)
        cout <<  myDeck[i] << ' ' ;

    cout << endl;
    return 0;
}


