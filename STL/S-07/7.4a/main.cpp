#include <queue> // priority_queue
#include <string>
#include <iostream>
#include <utility>
using namespace std;

#include "simple_string.h"

/**
 * A priority queue assigns a priority to every element that it
 * stores. New elements are added to the queue using the push()
 * function, just as with a FIFO queue.
 *
 * This queue also has a pop() function, which differs from the FIFO
 * pop() in one key area. When you call pop() for the priority queue,
 * you don't get the oldest element in the queue. Instead, one get the
 * element with the highest priority.
 *
 * The priority queue fits in well with certain types of tasks. For
 * example, the scheduler in an operating system might use a priority
 * queue to track processes running in the operating system.
 *
 * Its template is found in the <queue> header file. It uses the less
 * functor to compare its keys by default, but you can change this!
 * Internally it is implemented from a vector that has been "heapified."
 *
 * Here's a typical implementation of a priority_queue in STL:
 *
 * template <typename T,
 *           typename Container = vector<T>>
 *           typename Compare = less<typename Container::value_type>>
 * class priority_queue {
 * public:
 *   explicit priority_queue(const Compare &comp,
 *                           const Container& c): container_(c) {}
 *   ...
 *   bool empty() const { return container_.empty(); }
 *   size_type size() const { return container_.size(); }
 *   const value_type& top() const { return container_.front(); }
 *   void push(const value_type& t)  {
 *     container_.push_back(t);
 *     std::push_heap(container_.begin(), container_.end(), comp_);
 *   }
 *   void pop() {
 *     std::pop_heap(container_.begin(), container_.end(), comp_)
 *     container_.pop_back();
 *   }
 *
 * private :
 *   Container container_;
 *   Compare comp_;
 *   //...
 * };
 */

/**
 * This struct defines operator< so it can be used with priority_queue.
 */
struct place {
  unsigned int dist;
  simple_string dest;

  friend ostream& operator<<(ostream &, const place &) ;

  place (simple_string dt, unsigned int ds)
    : dist(ds), dest(std::move(dt)) {}

  // This method is needed to order the priority queue properly.
  bool operator< (const place &right) const
  {  return dist < right.dist;  }

  // This method is needed to order the priority queue properly.
  bool operator> (const place &right) const
  {   return dist > right.dist;  }
};

/**
 * Insertion operator prints the contents of a place.
 */
ostream &operator <<(ostream& os, const place &p) {
  return os << p.dest << " " << p.dist; 
}

/**
 * The example below uses a priority_queue that prints out city names
 * and their distance from a given place. The output will be:
 *
 *  Nashville 21
 * 	Green Hills 15
 * 	Cool Springs 3
 */
int main() {
  priority_queue<place> pque;
  // priority_queue<place, std::deque<place>, std::greater<>> pque;

  // Show three different ways to put an item into the priority_queue.
  cout << "begin emplace()" << endl;
  pque.emplace("Nashville",  21);
  cout << "end emplace()" << endl;

  cout << "begin push(&&)" << endl;
  pque.push(place("Cool Springs", 3));
  cout << "end push(&&)" << endl;

  cout << "begin push(const &)" << endl;
  place green_hills ("Green Hills", 15);
  pque.push(green_hills);
  cout << "end push(const &)" << endl;

  while (!pque.empty()) {
    cout << pque.top() << endl;

    // remove top entry from queue
    pque.pop();
  }
  return 0;
}
