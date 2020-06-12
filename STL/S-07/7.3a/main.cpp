#include <iostream>
#include <queue>
#include <string>
#include <list>
using namespace std;

/**
 * A queue or FIFO (First In, First Out), is characterized by having
 * elements inserted into one end and removed from the other end, for
 * example: a queue of people at a theater's box office. Again by
 * default it is implemented from a deque, but that can be changed.
 * 
 * Here's the typical implementation for class stack in STL:
 *
 * template <typename T, typename Container = deque<T> >
 * class queue {
 * public:
 *   explicit queue(const Container& c): container_(c) {}
 *   ...
 *   bool empty() const { return container_.empty(); }
 *   size_type size() const { return container_.size(); }
 *   value_type& front() { return container.front(); }
 *   const value_type& front() const { return container.front(); }
 *   void push(const value_type& t)  { container.push_back(t); };
 *   void pop() { container.pop_front(); }
 *
 * private :
 *   Container container_ ;
 *   //...
 * };
 *
 * Here is an example program that uses an STL queue.
 */
int main() {
  queue<string, std::list<string>> aCue;
  cout << "Pushing one two three \n";

  // Note the curious methods for putting and getting elements
  // into and from a queue!
  aCue.push("one");
  aCue.push("two");
  aCue.push("three");

  while(!aCue.empty()) {
    cout << "Popping ";
    cout << aCue.front() << endl;
    aCue.pop();
  }

  return 0;
}
