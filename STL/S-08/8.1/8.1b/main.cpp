#include <iostream>
#include <memory>

using namespace std;

/**
 * Here's a C++ class that defines methods matching the signatures
 * that are shown below.
 */
class example_class {
public:
    explicit example_class(int i = 0): i_(i) {}

    float aFun(float a, char b, char c) {
        return i_ += a + b + c;
    }

    float anotherFun(float a, char b, char c) const {
        return i_ + a - b +c;
    }

    static float aStaticFun (float a, char b, char c) {
        return a + b + c;
    }

private:
    int i_;
};

/**
 * Since a function pointer is a variable, it must be declared. This
 * example   defines some function pointers named pt2Function,
 * pt2Member and pt2ConstMember. They all point to functions, which
 * take one float and two char and return an int. In the C++ examples
 * it is assumed that the functions pointed to are non-static member
 * functions. 
 */
float (*pt2Function)(float, char, char) = nullptr; // C
float (example_class::*pt2Member)(float, char, char) = nullptr; // C++
float (example_class::*pt2ConstMember)(float, char, char) const = nullptr; // C++

/**
 * This program demonstrates how to use the pointers to functions and pointers
 * to member functions, as defined above.
 */
int main() {
  // Correct assignment using address operator.
  pt2ConstMember = &example_class::anotherFun; 

  // <pt2Member> may also legally point to &anotherFun.
  pt2Member = &example_class::aFun; 

  pt2Function = &example_class::aStaticFun;

  example_class instance1(10);

  cout << (instance1.*pt2Member)(12.5, 'a', 'b') << endl;
  cout << (instance1.*pt2ConstMember)(24.5, 'c', 'd') << endl;
  cout << (*pt2Function)(13.2, 'e', 'f') << endl;

    // instance2 is a pointer
  std::unique_ptr<example_class> instance2 (new example_class());

  cout << (instance2.get()->*pt2Member)(12.5, 'a', 'b');
}
