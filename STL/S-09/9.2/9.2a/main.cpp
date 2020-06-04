#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

/**
 * This example introduces the bind1st() and bind2nd() function
 * adapters.
 */
int main () {
  int numbers[] = {10, 20, 40, 30, 50, 20, 10};
  int numbers_end = numbers + sizeof(numbers) / sizeof(*numbers);

  int n = count_if (numbers,
                    numbers_end,
                    bind1st(equal_to<int>(), 10));

  cout << "There are " 
       << n
       << " elements that are equal to 10" 
       << endl;

  n = count_if (numbers,
                numbers_end,
                bind2nd(equal_to<int>(), 20));

  cout << "There are " 
       << n
       << " elements that are equal to 20" 
       << endl;

  return 0;
}
