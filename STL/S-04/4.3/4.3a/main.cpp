#include <iostream>
#include <valarray>
#include <cmath>
using namespace std;

int main()  {
    valarray<int> aValuesArray(10);
    int i;

    for(i = 0; i < 10; i++)
        aValuesArray[i] = i;

    cout << "Original contents: ";
    for(i = 0; i < 10; i++)
        cout << aValuesArray[i] << " ";
    cout << endl;

    aValuesArray = aValuesArray.cshift(3);
    cout << "Shifted contents: ";
    for(i = 0; i < 10; i++)
        cout << aValuesArray[i] << " ";
    cout << endl;

    valarray<bool> aValuesArray2 = aValuesArray < 5;
    cout << "Those elements less than 5: ";
    for(i = 0; i < 10; i++)
        cout << aValuesArray2[i] << " ";
    cout  << endl;

    valarray<double> aValuesArray3(5);
    for(i = 0; i < 5; i++)
        aValuesArray3[i] = (double) i;

    cout << "Original contents: ";
    for(i = 0; i < 5; i++)
        cout << aValuesArray3[i] << " ";
    cout << endl;

    aValuesArray3 = sqrt(aValuesArray3);
    cout << "Square roots: ";
    for(i = 0; i < 5; i++)
        cout << aValuesArray3[i] << " ";
    cout << endl;

    aValuesArray3 = aValuesArray3 + aValuesArray3;
    cout << "Double the square roots: ";
    for(i = 0; i < 5; i++)
        cout << aValuesArray3[i] << " ";
    cout << endl;

    aValuesArray3 = aValuesArray3 - 10.0;
    cout << "After subtracting 10 from each element:\n";
    for(i = 0; i < 5; i++)
        cout << aValuesArray3[i] << " ";
    cout << endl;
    return 0;
}




