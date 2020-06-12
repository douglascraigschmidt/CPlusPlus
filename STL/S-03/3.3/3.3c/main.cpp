#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>

using namespace std;

/**
 * Here is an example of vectors being created using a C-style array
 * and char pointer, as well as a C++ initializer list.
 */
int  main() {
  int ar[] = {12, 45, 234, 64, 12, 35, 63, 23, 12, 55};
  vector<int> vec1(begin(ar), end(ar));
  vector<int> vec2 {12, 45, 234, 64, 12, 35, 63, 23, 12, 55};

  for (auto i : vec2)
    cout << i << ' ';

  cout << endl;

  const char *str = "Hello World";
  vector<char> vec3(str, str + strlen(str));
  vector<char> vec4{'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};

  for (auto c : vec4)
    cout << c;

  cout << endl;
  return 0;
}

