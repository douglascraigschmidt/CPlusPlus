#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class Foo {
public:
  Foo () { cout << "Foo::Foo()" << endl; }
  Foo (int i): i_(i) { cout << "Foo::Foo(int)" << endl; }
  Foo (const Foo &f): i_ (f.i_) { cout << "Foo::Foo(const &)" << endl; }
  void operator= (const Foo &) { cout << "Foo::operator=(const &)" << endl; }
  ~Foo () { cout << "Foo::~Foo" << endl; }

  int i_;
};

template <typename T>
class aPair {
public:
  aPair (const T &f, const T &s)
    // aPair (T f, T s)
    : first (f),
    second (s)
  { 
    // first = f;
    // second = s;
  }

  T first; 
  T second;  
};

int main () {
  Foo f1 = 10;
  Foo f2 = 20;
  aPair <Foo> myInts (f1, f2);
}
