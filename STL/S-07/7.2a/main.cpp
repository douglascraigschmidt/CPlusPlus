#include <iostream>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

/**
 * A stack is an ideal choice when one need to use a LIFO (Last In,
 * First Out) data structure. For example, think about people entering
 * the back seat of a car that has only one door: the last person to
 * enter is the first to exit. It is implemented with a deque by
 * default, but that can easily be changed.
 *
 * Here's the typical implementation for class stack in STL:
 *
 * template <typename T, typename Container = deque<T>>
 * class stack {
 * public:
 *   explicit stack(const Container& c): container_(c) {}
 *   ...
 *   bool empty() const { return container_.empty(); }
 *   size_type size() const { return container_.size(); }
 *   value_type& top() { return container_.back(); }
 *   const value_type& top() const { return container_.back(); }
 *   void push(const value_type& t)  { container_.push_back(t); };
 *   void pop() { container_.pop_back(); }
 *
 * private:
 *   Container container_;
 *   //...
 * };
 */

/**
 * Forward decl.
 */
void print_top(const stack<char> &s);

/**
 * Here is a simple example using the STL stack class.
 */
int main() {
  stack<char> aStack; // Could also use ({'A', 'B', 'C', 'D'});
  cout << "Pushing 'A', 'B', 'C', and 'D'" << endl;

  aStack.push('A');
  aStack.push('B');
  aStack.push('C');
  aStack.push('D');

  while(!aStack.empty()) {
    cout << "Popping: ";

    if (aStack.top() == 'C')
      aStack.top() = 'Z';

    print_top(aStack);

    // pop() and top() are decoupled!
    aStack.pop();
  }

  return 0;
}

void print_top(const stack<char> &s) {
    cout << s.top() << endl;
}
