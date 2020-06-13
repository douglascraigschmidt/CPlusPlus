#include <iostream>
#include <ctype.h>

using namespace std;

/**
 * The idea of C++ class template specialization is similar to
 * function template overloading. It fixes the template code for
 * certain data types that need to be handled differently than most
 * data. For example, string or char data is not handled identically
 * to true numeric datatypes, so a specialization of an ‘add’ template
 * for strings or char data may need to work differently than it would
 * for adding integers or numbers. After the template is specialized,
 * all the member functions should be declared and defined for the
 * specific data type.
 *
 * When a program instantiates a template with a given set of template
 * arguments the compiler generates a new definition based on those
 * template arguments. To override this, instead specify the
 * definition the compiler uses for a given set of template
 * arguments. This is called explicit specialization. A program can
 * explicitly specialize any of the following: 
 * • Function or class template 
 * • Member function of a class template 
 * • Static data member of a class template 
 * • Member class of a class template 
 * • Member function template of a class template 
 * • Member class template of a class template
 * 
 * The template<> prefix indicates that the following template
 * declaration takes no template parameters. The declaration_name is
 * the name of a previously declared template. Note that an explicit
 * specialization can be forward-declared so the declaration_body is
 * optional, at least until the specialization is referenced.
 */

#include "container.h"

// class template specialization:
template <> class container <char *> {
public:
  explicit container (char *arg): element (arg) {}
  char *uppercase ();  // note how we've added a totally new method!

private:
  char *element;
};

// Member of class template specialization:
char *
container<char *>::uppercase() {
  for (int i = 0; element[i] != '\0'; ++i)
    if (islower(element[i]))
      element[i] = toupper(element[i]);

  return element;
}

/**
 * Define class Foo that defines operator++().
 */
class Foo {
public:
  explicit Foo(int i): i_(i) {}

  Foo operator++() {
    cout << "Foo::operator++" << endl;
    return Foo(++i_);
  }

  explicit operator int() const { return i_; }

private:
  int i_;
};

ostream &operator<<(ostream &os,  const Foo &foo) {
  return os << int(foo);
}

/**
 * Specialize container with a Foo.
 */
template<> class container<Foo> {
public:
  explicit container (Foo arg): element (arg) {}
  Foo increase() {
    cout << "container<Foo>::increase()" << endl;
    return ++element;
  }

private:
  Foo element;
};

/**
 * The following code shows several examples of template
 * specialization.
 */
int main () {
  container<int> my_int (7);
  container<double> my_double (10.5) ;

  char lowercase[] = "hello world";
  container<char *> my_charstring (lowercase);

  cout << my_int.increase() << endl;
  cout << my_double.increase() << endl;
  cout << my_charstring.uppercase() << endl;

  container<Foo> my_foo (Foo(10));
  cout << my_foo.increase() << endl;

  return 0;
}
