#include <vector>
#include <iterator>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    vector<int> aVector;

    for( int i=0; i < 10; ++i)			// put some values in vector
        aVector.push_back(i);

    int total = 0;
    for (auto anIterator = aVector.begin();  // set iterator at start
         anIterator != aVector.end();
         ++anIterator)  	// process vector  using iterator
        total += *anIterator;			// add up values stored

    cout << "Total=" << total << endl;	// display the total of values

    cout << "Total=" << std::accumulate(aVector.begin(), aVector.end(), 0)
         << endl;

    return 0;
}

