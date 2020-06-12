#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

const int MAX_STACK = 10;

/**
 * This example demonstrates the use of C++ exceptions to report
 * errors with our stack ADT.
 */
int main() {
    try {
        stack<int> s1(MAX_STACK);
        auto item = 0;

        try {
            for (;;)
                s1.push(item++);
        } catch (stack<int>::overflow &ex) {
           cout << "inner: " << ex.what() << endl;
        }

        try {
            for (;;) {
                cout << "top item = " << s1.top() << endl;
                s1.pop();
            }
        } catch (stack<int>::underflow &ex) {
            cout << "inner: " << ex.what() << endl;
        }

    } catch (std::exception &ex) {
        cout << "outer: " << ex.what() << endl;
    }
  // Termination is handled automatically.

  return 0;
}
