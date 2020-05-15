#include <vector>
#include <string>
#include <list>
#include <deque>
using namespace std;

template <typename T, template <typename ...> class aContainer = deque>
class aStack {
public:
    // ...
private:
    aContainer<T> s;
};


int main() {
    aStack<string> aDequeStackofStrings; // defaults to deque
    aStack<int, list> aListStackofInts;

    return 0;
}

