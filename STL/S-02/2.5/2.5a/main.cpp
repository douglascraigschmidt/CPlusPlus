#include <vector>
using namespace std;

/**
 * Templates classes (but not template functions), can take default
 * template parameters.
 */ 
template <typename T = int>
class stack {
  public:
    // ...
  private:
    vector<T> s;
};

/**
 * This example shows how a program can use default template
 * parameters when instantiating a template.
 */
int main() {
  // Use default so stack is a vector of doubles.
  stack<double> a_stack_of_doubles;       

  // Don't use default, so stack now a vector of ints.
  stack<> a_stack_of_ints;

  return 0;
}

