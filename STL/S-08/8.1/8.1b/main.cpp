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

    float bFun(float a, char b, char c) {
        return i_ += a - b + c;
    }

    float anotherFun(float a, char b, char c) const {
        return i_ + a - b + c;
    }

    static float aStaticFun (float a, char b, char c) {
        return a + b + c;
    }

private:
    int i_;
};

/**
 * This program demonstrates how to use the pointers to functions and pointers
 * to member functions, as defined above.
 */
int main(int argc, char *argv[]) {
  // Since a function pointer is a variable, it must be declared. This
  // example defines function pointers named pt2Function, pt2Member
  // and pt2ConstMember that all point to functions taking one float
  // and two char and return an int.
  float (*pt2Function)(float, char, char) = nullptr; 
  float (example_class::*pt2Member)(float, char, char) = nullptr; 
  float (example_class::*pt2ConstMember)(float, char, char) const = nullptr;

  // Correct assignment using address operator.
  pt2ConstMember = &example_class::anotherFun; 

  // <pt2Member> may also legally point to &anotherFun.
  if (argc > 1)
    pt2Member = &example_class::aFun; 
  else
    pt2Member = &example_class::bFun;

  pt2Function = &example_class::aStaticFun;

  example_class instance1(10);

  cout << (instance1.*pt2Member)(12.5, 'a', 'b') << endl;
  cout << (instance1.*pt2ConstMember)(24.5, 'c', 'd') << endl;
  cout << (*pt2Function)(13.2, 'e', 'f') << endl;

    // instance2 is a pointer
  std::unique_ptr<example_class> instance2 (new example_class());

  cout << (instance2.get()->*pt2Member)(12.5, 'a', 'b');
}
