#include <iostream>
#include <valarray>
#include <cmath>
using namespace std;

/**
 * The valarray template class is a vector-like container that is
 * optimized for efficient numeric computation. It doesn't provide
 * iterators.
 *
 * Although one can instantiate a valarray with nonnumeric types,
 * because it mainly has mathematical functions that are intended to
 * operate directly on the numeric data elements, this might not be
 * the most efficient container for non-numeric data.  Most of
 * valarray functions and operators appear to operate on a valarray as
 * a whole, but they actually do their work element-by-element.
 *
 * Useful Functions  
 *
 * The valarray class provides a constructor that takes an array of
 * the target type and the count of elements in the array to
 * initialize the new valarray.
 *
 * The shift() member function shifts each valarray element one
 * position to the left (or to the right, if its argument is negative)
 * and fills in holes with the default value for the type (zero in
 * this case). There is also a cshift() member function that does a
 * circular shift (or rotate). This is for bitwise arithmetic
 * operations that often occur in electronics applications.
 *
 * All mathematical operators and functions are overloaded to operate
 * on valarrays; in other words, a valarray¡¦s elements can have all of
 * these operations performed on them. Binary operators, such as
 * addition, subtraction, multiplication, division and the modulus
 * operation all require valarrays of the same type and size.
 * 
 * The apply() member function of valarrays, like the STL transform()
 * algorithm, applies a function to each element, but the result is
 * collected into a result valarray.
 * 
 * Useful Operators
 *
 * The relational operators (equal, not equal, greater than, less
 * than, etc), return suitably-sized instances of valarray<bool> that
 * indicate the result of element-by-element comparisons.
 * 
 * Most operations return a new result array, but a few, such as
 * min(), max(), and sum(), return a single scalar value.
 *
 * Here is an example of using an STL valarray.
 */
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




