#include <iostream>
using namespace std;

template <typename T>		
class aContainer {
public:
  aContainer(const T &arg): element (arg) {}
  T increase() {return ++element;}

private:
  T element;
};

int main () {
  aContainer<int> myint(7);
  cout << myint.increase() << endl;
  return 0;  
}
