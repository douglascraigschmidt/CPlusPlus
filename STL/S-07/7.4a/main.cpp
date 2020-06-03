#include <queue> // priority_queue
#include <string>
#include <iostream>
using namespace std;

/**
 * This struct defines operator< so it can be used with priority_queue.
 */
struct place {
  unsigned int dist;  string dest;
  friend ostream& operator<<(ostream &, const place &) ;
  place (const string dt, unsigned int ds) : dist(ds), dest(dt) {}
  // This method is needed to order the priority queue properly.
  bool operator< (const place & right) const
  {   return dist < right.dist;  }
};

ostream & operator << (ostream& os, const place& p) {
  return os << p.dest << " " << p.dist; 
}

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
 * functor to compare its keys.  Internally it is implemented from a
 * vector that has been "heapified"
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
 *   const value_type& top() const { return container.front(); }
 *   void push(const value_type& t)  { 
 *     container.push_back(t); 
 *     std::push_heap(container_.begin(), container_.end(), comp_);
 *   }
 *   void pop() { 
 *     std::pop_heap(container_.begin(), container_.end(), comp_)
 *     container.pop_back(); 
 *   }
 *
 * private :
 *   Container container_ ;
 *   Compare comp_;
 *   //...
 * };
 *
 * The example below uses a priority_queue that prints out city names
 * and their distance from a given place. The output will be:
 *
 *	El Cajon 20
 * 	Poway 	 10
 * 	La Jolla  3
 */
int main() {
  priority_queue <place> pque;

  pque.push(place("Poway",   10));
  pque.push(place("El Cajon",  20));
  pque.push(place("La Jolla", 3));

  while (!pque.empty()) {		
    cout << pque.top() << endl;

    // remove top entry from queue
    pque.pop();
  }
  return 0;
}
