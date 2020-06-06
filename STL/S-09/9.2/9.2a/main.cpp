#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

/**
 * Forward declarations.
 */
static void demonstrate_bind1st();
static void demonstrate_bind2nd();
static void contrast_bind1st_and_bind2nd();

/**
 * This example introduces the bind1st() and bind2nd() function
 * adapters and compares/contrasts them.
 */
int main () {
  demonstrate_bind1st();
  demonstrate_bind2nd();
  contrast_bind1st_and_bind2nd();

  return 0;
}

static void 
demonstrate_bind1st() {
  int numbers[] = {10, 20, 40, 30, 50, 20, 10};
  int *numbers_end = numbers + sizeof(numbers) / sizeof(*numbers);

  auto n = count_if (numbers,
                     numbers_end,
                     bind1st(equal_to<int>(), 10));

  cout << "There are " 
       << n
       << " elements that are equal to 10" 
       << endl;
}

static void 
demonstrate_bind2nd() {
  int numbers[] = {10, 20, 40, 30, 50, 20, 10};
  int *numbers_end = numbers + sizeof(numbers) / sizeof(*numbers);

  auto n = count_if (numbers,
                     numbers_end,
                     bind2nd(equal_to<int>(), 20));

  cout << "There are " 
       << n
       << " elements that are equal to 20" 
       << endl;
}

static void
contrast_bind1st_and_bind2nd() {
  auto p1 = bind1st(plus<int>(), 10);
  auto p2 = bind2nd(plus<int>(), 10);
  cout << p1(20) << endl;
  cout << p2(20) << endl;

  auto m1 = bind1st(minus<int>(), 10);
  auto m2 = bind2nd(minus<int>(), 10);
  cout << m1(20) << endl;
  cout << m2(20) << endl;
}

#pragma clang diagnostic pop