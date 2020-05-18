#include <iostream>
#include <utility>
using namespace std;

/**
 * The concept of a pair is essential for understanding how
 * associative containers work. A pair binds a key (known as the first
 * element) with an associated value (known as the second element).
 * In the library <utility> and included in other standard libraries
 * such as <map> there is a class called pair that implements the
 * mathematical idea of a Cartesian point. A pair is used to construct
 * maps and other associative data structures.
 *
 * Here we create a Point class that wraps a pair.
 */
template<typename T1, typename T2>
class point {
public:
    point(T1 x, T2 y)
        : pair_(x, y),
          x(pair_.first),
          y(pair_.second) { }
    T1 &x;
    T2 &y;

 private:
    pair<T1, T2> pair_;
};

/**
 * This program demonstrates several usage of the STL pair template.
 */
int main() {
  // Instantiate an object of the point class to make a point.
  point<int, int> my_point(100, 200);
    
  cout << "x = " << my_point.x << "\ny = " << my_point.y << endl;
    
  // Create several other pairs.
  pair <string, string> my_book("Chapter1", "Meet the STL");
  pair <string, void *> debug("mynum",
                             reinterpret_cast<void *>(0x410928a8));

  return 0;
}
