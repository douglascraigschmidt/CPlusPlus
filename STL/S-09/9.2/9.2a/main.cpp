#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
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
static void contrast_bind1st_bind2nd_and_bind();

/**
 * This example introduces the bind1st(), bind2nd(), and bind()
 * function adapters and compares/contrasts them.  It also illustrates
 * how to replace the deprecated binder functors with bind() and
 * generic lambda functions.
 */
int main () {
  demonstrate_bind1st();
  demonstrate_bind2nd();
  contrast_bind1st_bind2nd_and_bind();

  return 0;
}

static void 
demonstrate_bind1st() {
  int numbers[] = {10, 20, 40, 30, 50, 20, 10};

  // Use bind1st()
  auto n = count_if (begin(numbers),
                     end(numbers),
                     bind1st(equal_to<int>(), 10));

  cout << "There are " 
       << n
       << " elements that are equal to 10" 
       << endl;

  // Use bind()
  n = count_if (begin(numbers),
                end(numbers),
                bind(equal_to<>(), placeholders::_1, 10));

  cout << "There are " 
       << n
       << " elements that are equal to 10" 
       << endl;

  // Use generic lambda function
  n = count_if (begin(numbers),
                end(numbers),
                [](auto i) { return i == 10; });

  cout << "There are " 
       << n
       << " elements that are equal to 10" 
       << endl;
}

static void 
demonstrate_bind2nd() {
  int numbers[] = {10, 20, 40, 30, 50, 20, 10};

  // Use bind2nd()
  auto n = count_if (begin(numbers),
                     end(numbers),
                     bind2nd(equal_to<int>(), 20));

  cout << "There are " 
       << n
       << " elements that are equal to 20" 
       << endl;

  // Use bind()
  n = count_if (begin(numbers),
                end(numbers),
                bind(equal_to<int>(), placeholders::_1, 20));

  cout << "There are "
       << n
       << " elements that are equal to 20"
       << endl;

  // Use generic lambda.
  n = count_if (begin(numbers),
                end(numbers),
                [](auto i) { return i == 20; });

  cout << "There are " 
       << n
       << " elements that are equal to 20"
       << endl;
}

static void
contrast_bind1st_bind2nd_and_bind() {
  auto p1 = bind1st(plus<int>(), 10);
  auto p2 = bind2nd(plus<int>(), 10);
  auto p3 = bind(plus<int>(), 10, placeholders::_1);
  auto p4 = bind(plus<int>(), placeholders::_1, 10);

  cout << p1(20) << endl;
  cout << p2(20) << endl;
  cout << p3(20) << endl;
  cout << p4(20) << endl;

  auto m1 = bind1st(minus<int>(), 10);
  auto m2 = bind2nd(minus<int>(), 10);
  auto m3 = bind(minus<int>(), 10, placeholders::_1); 
  auto m4 = bind(minus<int>(), placeholders::_1, 10);

  cout << m1(20) << endl;
  cout << m2(20) << endl;
  cout << m3(20) << endl;
  cout << m4(20) << endl;
}

#pragma clang diagnostic pop
