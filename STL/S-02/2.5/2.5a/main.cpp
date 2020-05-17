#include <vector>
using namespace std;

/**
 * Templates classes (but not template functions), can take default
 * template parameters.
 */ 
template <typename T = int>
class Stack {
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
  // Use default so Stack is a vector of doubles.
  Stack<double> aStackofdoubles;       

  // Don't use default, so Stack now a vector of ints.
  aStack<> aStackofints;

  return 0;
}

