#include <vector>
#include <iostream>

using namespace std;

/**
 * Forward declarations.
 */
void demonstrate_pointer_arithmetic();
void demonstrate_random_access_iterator();

/**
 * Here is another example of accessing the contents of a built-in C++
 * array and a vector using random access iterators.
 */
int main () {
    demonstrate_pointer_arithmetic();
    demonstrate_random_access_iterator();

    return 0;
}

/**
 * Demonstrates pointer arithmetic on a built-in C/C++ array.
 */
void
demonstrate_pointer_arithmetic() {
    int a[] = {1, 2, 3, 4};

    // now create 2 pointers that are random access pointers.
    auto i = begin(a);
    auto j = i + 2;
    cout << *j << " ";

    // Perform some "pointer arithmetic".
    i += 3;
    cout << *i << " ";

    j = i - 1;
    cout << *j << " ";
    j -= 2;

    cout << *j << " ";
    cout << a[1] << endl;

    j < i ? cout << "j < i" : cout << "not (j < i)"; cout << endl;
    j > i ? cout << "j > i" : cout << "not (j > i)"; cout << endl;

    i = j;
    i <= j && j <= i ? cout << "i and j equal" : cout << "i and j not equal";
    cout << endl;
}

/**
 * Demonstrate random access iterators on STL vector.
 */
void
demonstrate_random_access_iterator() {
    vector<int> v {1, 2, 3, 4};

    // now create 2 iterators that are random access iterators
    auto i = begin(v);
    auto j = i + 2; cout << *j << " ";

    // Perform some "pointer arithmetic".
    i += 3;
    cout << *i << " ";

    j = i - 1;
    cout << *j << " ";
    j -= 2;

    cout << *j << " ";
    cout << v[1] << endl;

    j < i ? cout << "j < i" : cout << "not (j < i)"; cout << endl;
    j > i ? cout << "j > i" : cout << "not (j > i)"; cout << endl;

    i = j;
    i <= j && j <= i ? cout << "i and j equal" : cout << "i and j not equal";
    cout << endl;
}





