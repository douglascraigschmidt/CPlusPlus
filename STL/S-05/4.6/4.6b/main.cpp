#include <vector>
#include <iostream>
using namespace std;
int main ()   {
    vector<int> myVector;
    int total_even = 0;

    for( int i=0; i < 10; i++ )
        myVector.push_back(i);

    for (auto  myVectorIter = myVector.begin();
         myVectorIter != myVector.end();
         myVectorIter += 2)
    {
        total_even += * myVectorIter;
    }

    cout << "Total even = " << total_even << endl;
    return 0;
}



