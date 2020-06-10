#include <iostream>
#include <typeinfo>
using namespace std;

/**
 * This example demonstrates the use of template member functions and
 * member function templates in C++ parameterized types.
 */

/**
 * Here is an example of a template class. This class has one template
 * parameter, T. This datatype will be applied when its constructor
 * and increase() template member function are called.
 */
template <typename T>		
class container {
public:
  explicit container(const T &arg): element (arg) {}

  // template member function
  T increase() {return ++element;}

private:
  T element;
};

/**
 * Templates declared inside classes are called member templates, and
 * they can be either member function templates or member class
 * templates (nested classes).
 * 
 * Member function templates are template functions that are members
 * of any class or class template. Notice that member templates are
 * not the same as template members.
 * 
 * A template member is a member declared inside a class template.
 */
template <typename T> 
struct class_A  {
  explicit class_A(T *p): p_(p) {
    cout << typeid(p).name() << endl;
  }

  // a template (data) member
  T *p_; 	

  // another template member function (can be virtual if necessary)
  void f(T *t) const {
    // print the "name" of the types.
    cout << typeid(t).name() << endl;
  }
};

/**
 * A "member function template" is a template with its template
 * parameters declared inside any class.
 * 
 * Here's an example of a member function template in a non-template
 * class.
 */
struct class_B {
  // member function template (can't be virtual)
  template <typename T>     
  void mf(T *t) {
    // print the "name" of the type.
    cout << typeid(t).name() << endl;
  }
};

/**
 * Here's an example of declaring a member function template in a
 * template class.
 */
template <typename T>
struct class_C {
    // member function template (can't be virtual)
    template <typename U>
    void mf(U u, T *t) {
        // print the "name" of the types.
        cout << typeid(u).name() << endl;
        cout << typeid(t).name() << endl;
    }

    // template member function (can be virtual if necessary)
    void f(T *t) const {
        // print the "name" of the types.
        cout << typeid(t).name() << endl;
    }
};

/**
 * This method demonstrates the use of template member functions and
 * member function templates.
 */
int main () {
  // Show the use of a template member function.
  container<int> myint(7);
  cout << myint.increase() << endl;

  // Show the use of another template member function.
  long l;
  class_A<long> a(&l);
  a.f(&l);

  // Show the use of a member function template.
  int i;
  double d;
  class_B b;
  b.mf(&i); // The C++ compiler is automatically synthesizing
  b.mf(&d); // the mf() member function template for int and double.

  // Show more uses of template class and a member function template.
  class_C<int> c;
  class_C<double> cc;

  c.mf(10, &i);
  cc.mf(20.5, &d);
  c.f(&i);
  cc.f(&d);

  return 0;
}
