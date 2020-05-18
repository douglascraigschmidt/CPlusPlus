#include <iostream>
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
template <typename T> 
class Container { // class template
public:
  explicit Container (const T &arg) : element (arg) { }
  T increase () {return ++element;}
private:
  T element;
};

// class template specialization:
template <> class Container <char> {
public:
  explicit Container (char arg): element (arg) { }
  char uppercase ();  // note how we've added a totally new method!
private:
  char element;
};

// member of class template specialization:
char Container<char>::uppercase()  {
  if ((element >= 'a') && (element <= 'z'))
    element += 'A' - 'a';
  return element;
}

/**
 * The following code shows several examples of template
 * specialization.
 */
int main () {
  Container<int> myint (7);
  Container<double> mydouble (10.5) ;
  Container<char> mychar ('j');

  cout << myint.increase() << endl;
  cout << mydouble.increase() << endl;
  cout << mychar.uppercase() << endl;
  return 0;
}
