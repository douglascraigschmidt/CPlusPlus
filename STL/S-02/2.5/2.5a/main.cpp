#include <vector>
using namespace std;

template <typename T = int>
class aStack {
  public:
    // ...
  private:
    vector<T> s;
};

int main() {
  // use default so aContainer is a vector of doubles.
  aStack<double> aStackofdoubles;       

  //don't use default, now a vector of ints.
  aStack<> aStackofints;

  return 0;
}

