#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * A member function adapter can be used to allow class member
 * functions as arguments to the STL predefined algorithms. There are
 * 2 of them:
 * 
 * mem_fun(PtrToMember mf); 
 * Converts a pointer to member to a functor whose first arg is a
 * pointer to the object. Unary function if mf takes no arguments,
 * binary function if mf takes an argument.
 * 
 * mem_fun_ref(PtrToMember mf); 
 * Converts a pointer to member to a functor whose first arg is a
 * reference to the object. Unary function if mf takes no arguments,
 * binary function if mf takes one argument.
 * 
 * This example shows the member function reference function adaptor
 * mem_fun_ref, plus examples using several STL algorithm functions
 * and some lambda functions.
 */
class WrapInt {
public:
  WrapInt(): val (0) { }
  explicit WrapInt(int x): val (x) {}

  void showval() const {
    cout << val << " "; 
  }

  bool isPrime() const {
    for (int i = 2; i <= (val / 2); i++)
      if (!(val % i))
        return false;

    return true;
  }

  bool isEven() const { return !(val % 2); }

  bool isOdd() const { return val % 2; }

private:
  int val;
};

int main() {
  vector<WrapInt> aVect(10);

  for (int i = 0; i < 10; i++)
    aVect[i] = WrapInt(i + 1);

  cout << "Sequence contains: ";
  for_each(aVect.begin(),
           aVect.end(),
           mem_fun_ref(&WrapInt::showval));
  cout << endl;

  // remove the primes
  auto end_p = remove_if(aVect.begin(),
                         aVect.end(),
                         mem_fun_ref(&WrapInt::isPrime));

  cout << "Sequence after removing primes: ";
  for_each(aVect.begin(),
           end_p,
           mem_fun_ref(&WrapInt::showval));
  cout << endl;

  for (int i = 0; i < 10; i++)
    aVect[i] = WrapInt(i + 1);

  // Remove even numbers.
  end_p = remove_if(aVect.begin(),
                    aVect.end(), 
                    mem_fun_ref(&WrapInt::isEven));

  cout << "Sequence after removing even values: ";

  for_each(aVect.begin(),
           end_p,
           mem_fun_ref(&WrapInt::showval));

  cout << endl;

  for (int i = 0; i < 10; i++)
    aVect[i] = WrapInt(i + 1);

  end_p = remove_if(aVect.begin(),
                    aVect.end(), 
                    [](WrapInt &wi) { return wi.isOdd(); });

  cout << "Sequence after removing odd values: ";
  for_each(aVect.begin(),
           end_p,
           // Use a lambda function.
           [](WrapInt &wi) { wi.showval(); });
 
  return 0;
}
