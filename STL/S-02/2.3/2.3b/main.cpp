#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>		
class aContainer {
public:
  aContainer(const T &arg): element (arg) {}

  // template member function
  T increase() {return ++element;}

private:
  T element;
};

struct aClass {
  // member function template (can't be virtual)
  template <typename T>     
  void mf(T *t) {
    // print the "name" of the type.
    cout << typeid(t).name() << endl;
  }
};

template <typename T>
struct bClass {
    // member function template (can't be virtual)
    template <typename U>
    void mf(U u, T *t) {
        // print the "name" of the types.
        cout << typeid(u).name() << endl;
        cout << typeid(t).name() << endl;
    }
};

int main () {
  // Show the use of a template member function.
  aContainer<int> myint(7);
  cout << myint.increase() << endl;

  // Show the use of a member function template.
  int i;
  double d;
  aClass a;
  a.mf(&i);
  a.mf(&d);

  // Show more uses of template class and a member function template.
  bClass<int> b;
  bClass<double> c;

  b.mf(10, &i);
  c.mf(20.5, &d);

  return 0;
}
