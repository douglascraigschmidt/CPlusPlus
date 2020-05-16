#include <vector>
#include <iterator>
#include <iostream>
#include <string>
  using namespace std;
int main ()  {
    const char *s[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    vector<string> v1 (s, s + 10);

   // C++11
   vector<string> v2 ({"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"});

    copy (v2.begin (), v2.end (),
         ostream_iterator<string> (cout, "\n"));

    auto p = v2.begin();  // initialized to start of vector
    p += 5;  // Now p refers to the 5th element
    p[1] = "z";    // Value at p[1] is changed but p refers to 5th

    // position still; position wasn"t changed
    p -= 5; // Back to start

    copy (p, v2.end (),
          ostream_iterator<string> (cout, "\n"));
    return 0;
}

