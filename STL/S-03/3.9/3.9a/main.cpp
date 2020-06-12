#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

/**
 * Create a class that "wraps around" sequential containers.
 */
template<typename T,
         template <typename ...> class sequential_container = vector>
struct sequential_container_wrapper {
  /**
   * This constructor is passed a variadic template it uses to
   * initialize the wrapped sequential container.
   */
  template<typename... Args>
  explicit sequential_container_wrapper(Args&&... args)
    : container_(std::forward<Args>(args)...) {
  }

  /**
   * The wrapped sequential container.
   */
  sequential_container<T> container_;
};

/**
 * This extraction operator prints the contents of a wrapped
 * sequential container to the ostream {@code os} param.
 */
template<typename T, template <typename ...> class container>
ostream& operator <<(std::ostream& os,
                     sequential_container_wrapper<T, container> vw) {
  // Print out method name and arguments.
  os << __PRETTY_FUNCTION__ << '\n';

  // Print the contents of the wrapper sequential container.
  for (const auto &e : vw.container_)
    os << e << ' ';

  return os;
}

/**
 * This example shows how to use C++ template template parameters and
 * variadic templates to wrap sequential containers.
 */
int main() {
  // Create an array of four shape names.
  const char *shapes[] = { "Circle", "Triangle", "Square", "Rectangle"};

  // Wrap a vector of strings to contain three "words".
  sequential_container_wrapper<string> b1(3, "words");

  // Wrap a deque containing the shape names.
  sequential_container_wrapper<const char *, deque> b2(begin(shapes),
                                                       end(shapes));

  // Print the results.
  cout << b1 << endl;
  cout << b2 << endl;
  return 0;
}
