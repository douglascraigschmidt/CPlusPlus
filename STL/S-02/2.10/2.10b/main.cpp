#include <iostream>
#include <cassert>

using namespace std;

const long long factorial_20 = 2432902008176640000LL;

long long factorial(const long long val,
                    const long long sum = 1) {
  if (val > 1)
    return factorial(val - 1, sum * val);
  else
    return sum;
}

constexpr long long cfactorial(const long long in,
                               const long long sum = 1) {
    if (in > 1)
        return cfactorial(in - 1,sum * in);
    else
        return sum;
}

enum { compileTimeGeneratedValue = cfactorial(20) };
static_assert(compileTimeGeneratedValue == factorial_20, "error");

// generic metafunction calls (inherits from) it self
template<long long LLn, long long LSum = 1>
struct Factorial
       : Factorial<LLn - 1, LLn * LSum>{};

// specialized metafunction has a value and does not inherit
template<long long LSum> // take LSum as a wild card
struct Factorial<1, LSum> {
    enum { value = LSum };
};

const long long fact = Factorial<20>::value;

static_assert(fact == factorial_20, "error");

int main() {
  assert(factorial(20) == factorial_20);
  cout << "factorial(20) = " << factorial_20;
}
