#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template <typename T>
void printDataType (const T& a)  {  cout << typeid(a).name() << endl; }

template <typename T>
struct aClass
{
  aClass () { }
  T result (T t) { return t; }
  void add (const T &t) {}
};

// explicitly instantiate this function template for types int and double
template void printDataType<int>(const int &);
template void printDataType<double>(const double &);

// explicitly instantiate a template class¡¯ constructor for int data
template aClass<int>::aClass();

// explicitly instantiate an entire template class and all its functions
// later cannot explicitly instantiate particular functions of this class
// because ALL are instantiated by this statement
template struct aClass<double>;

// explicitly instantiate just some member functions 
template aClass<string>::aClass();
template void aClass<string>::add(const string  &);
template string aClass<string>::result(string);

int main() {
  aClass<int> ai;
  aClass<double> ad;
  printDataType(ai);
  printDataType(ad);

  return 0;
}
