#include <iostream>
using namespace std;

template <typename T> 
class aContainer { // class template
public:
  aContainer (const T &arg) : element (arg) { }
  T increase () {return ++element;}
private:
  T element;
};

// class template specialization:
template <> class aContainer <char> {
public:
  aContainer (char arg): element (arg) { }
  char uppercase ();  // note how we've added a totally new method!
private:
  char element;
};

// member of class template specialization:
char aContainer<char>::uppercase()  {
  if ((element >= 'a') && (element <= 'z'))
    element += 'A' - 'a';
  return element;
}

int main () {
  aContainer<int> myint (7);
  aContainer<double> mydouble (10.5) ;
  aContainer<char> mychar ('j');
  cout << myint.increase() << endl;
  cout << mydouble.increase() << endl;
  cout << mychar.uppercase() << endl;
  return 0;
}
