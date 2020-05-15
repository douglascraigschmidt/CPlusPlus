#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int  main() {
  int ar[10] = {12, 45, 234, 64, 12, 35, 63, 23, 12, 55};
  const char* str = "Hello World";
  vector<int> vec1(ar, ar+10);
  vector<int> vec2 ({12, 45, 234, 64, 12, 35, 63, 23, 12, 55});

  for (auto i : vec2)
    cout << i << ' ';

  cout << endl;
  vector<char> vec3(str, str+strlen(str));
  vector<char> vec4({'H', 'e', 'l', 'l', 'o'});

  for (auto c : vec4)
    cout << c;

  cout << endl;
  return 0;
}

