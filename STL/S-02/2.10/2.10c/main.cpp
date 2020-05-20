#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

template<typename T,
         template <typename ...> class sequential_container = vector>
struct container_wrapper {
  template<typename... Args>
  explicit container_wrapper(Args&&... args)
    : container_(std::forward<Args>(args)...) {
  }

  sequential_container<T> container_;
};

template<typename T, template <typename ...> class container>
ostream& operator <<(std::ostream& os,
                     container_wrapper<T, container> vw) {
  os << __PRETTY_FUNCTION__ << '\n';

  for (const auto &e : vw.container_)
    os << e << ' ';

  return os;
}

int main() {
  const char *shapes[3] = { "Circle", "Triangle", "Square" };

  // Default to vector.
  container_wrapper<string> b1(3, "words");
  container_wrapper<const char *, deque> b2(shapes, shapes + 3);

  cout << b1 << endl;
  cout << b2 << endl;
  return 0;
}
