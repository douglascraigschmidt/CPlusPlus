#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * A vector is a collection of elements of type T, where T can be
 * integer, double, char, or any class. It's a dynamic array that
 * grows and shrinks at the end. A vector is a sequential container,
 * i.e., its elements are ordered following a strict linear sequence.
 *
 * Vector containers are implemented as dynamic arrays. Just as
 * regular arrays, vector containers have their elements stored in
 * contiguous storage locations, which means that their elements can
 * be accessed not only using iterators but also using offsets on
 * regular pointers to elements.
 *
 * Unlike builtin C/C++ arrays, however, storage in vectors is handled
 * automatically, allowing it to be expanded and contracted as needed.
 * 
 * Vectors are efficient for:
 *
 * . Accessing individual elements by their position index. 
 * . Iterating over the elements in any order.  
 * . Adding and removing elements from the end. 
 *
 * Compared to builtin C/C++ arrays, they provide almost the same
 * performance for these tasks, plus they have the ability to be
 * Easily resized. They usually consume a bit more memory than arrays,
 * however, because their capacity is handled automatically, to allow
 * for extra storage space for future growth.
 *
 * Internally, vectors have a size, which represents the amount of
 * elements currently contained in the vector. Vectors also have a
 * capacity, which determines the amount of storage space allocated,
 * and which can be either equal or greater than the actual size. The
 * extra amount of storage allocated is not used, but is reserved for
 * the vector to be used in the case it grows. This way, the vector
 * does not have to reallocate storage on each occasion it grows, but
 * only when this extra space is exhausted and a new element is
 * inserted.
 *
 * Reallocations are costly operations in terms of performance, since
 * they generally involve copying all values used by the vector to be
 * copied to a new location. Therefore, whenever large increases in
 * size are planned for a vector, it is recommended to explicitly
 * indicate a capacity for the vector using the member function
 * vector::reserve().
 *
 * The vector implementation in the C++ Standard Template Library
 * takes two template parameters:
 * 
 * template <typename T, 
 *           typename Allocator = allocator<T>> 
 * class vector;
 *
 * 1. T: Datatype of the elements that can be stored in the vector. 
 * 
 * 2. Allocator: This is the allocator object used to define the
 *    storage allocation model. By default, the Allocator class
 *    template from <memory> for type T is used, which defines the
 *    simplest memory allocation model and is value-independent.
 *
 * Here is an example using a built-in C-style array and an STL vector
 * declared to hold three integers.  One way to initialize a vector¡¯s
 * values is to directly access them just like a C-style array would
 * be accessed. Arithmetic can be performed on vector elements and the
 * result assigned to another element. Likewise, a vector¡¯s methods
 * push_back() and size() can be used along with range-based for loop.
 */
int main() {
  // Built-in arrays.
  int a[3];
  a[0] = 7;
  a[1] = a[0] + 3;
  a[2] = a[0] + a[1];

  // Print elements separated by a space
  for (int i = 0; i < (sizeof(a) / sizeof(a[0])); ++i)
    cout << a[i] << ' ';
  cout << endl;

  vector<int> v(3);
  v[0] = 7;
  v[1] = v[0] + 3;
  v[2] = v[0] + v[1]; // v[0] == 7, v[1] == 10, v[2] == 17

  // Print elements separated by a space
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << ' ';

  cout << endl;

  v.resize(0);

  // append elements with values 0-6
  for (int i = 0; i < 7; ++i)
    v.push_back(i);

  // Another way to print elements separated by a space
  for (auto i : v)
    cout << i << ' ';

  cout << endl;
  return 0;
}

