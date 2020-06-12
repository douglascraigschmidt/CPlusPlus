#include <deque>
#include <iostream>
using namespace std;

/**
 * A deque (pronounced "deck") is a double-ended queue that grows and
 * shrinks at both ends efficiently. Insertions and deletions can be
 * made in the middle, but these are slower. They are another type of
 * sequential container with their elements ordered following a strict
 * linear sequence.
 *
 * Deques may be implemented by specific libraries in different ways,
 * but in all cases they allow for the individual elements to be
 * accessed through random access iterators, with storage always
 * handled automatically (expanding and contracting as needed).
 *
 * Deque containers have the following properties:
 *
 * . Individual elements can be accessed by their position index.
 *
 * . Iteration over the elements can be performed in any order. 
 * 
 * . Elements can be efficiently added and removed from any of its
 *   ends (either the beginning or the end of the sequence).
 * 
 * Deques therefore provide a similar functionality to vectors, but
 * with efficient insertion and deletion of elements at the beginning
 * and end of the sequence. Unlike vectors, however, deques don't have
 * all elements in contiguous storage locations, thus eliminating the
 * possibility of traversing the deque container with simple pointer
 * arithmetic.
 *
 * Both vectors and deques provide a very similar interface and can be
 * used for similar purposes, but internally both work in quite
 * different ways: While vectors are very similar to a C-style array
 * that grows by reallocating all of its elements in a unique block
 * when its capacity is exhausted, the elements of a deques can be
 * divided in several chunks of storage, with the class keeping all
 * this information and providing uniform access to the elements.
 * 
 * Deques are a more complex internally, but this generally allows
 * them to grow more efficiently than vectors with their capacity
 * managed automatically. This efficiency is especially noticeable in
 * large sequences, because massive reallocations are avoided.
 * 
 * The deque implementation in the C++ Standard Template Library take
 * two template parameters:
 * 
 * template <typename T, 
 *           typename Allocator = allocator<T>> 
 * class deque;
 * 
 * 1. T: Datatype of the elements to be stored in the deque.
 * 
 * 2. Allocator: This is the allocator object used to define the
 *    storage allocation model. By default, the Allocator class
 *    template from <memory> for type T is used, which defines the
 *    simplest memory allocation model and is value-independent.
 *
 * All of the member function implemented in vector are also
 * implemented in deque except for capacity() and reserve().  Also
 * included are two new functions:
 * 
 * void push_front(const T&)    adds an element to the front
 * void pop_front()             removes the first element
 *
 * This example shows how to create a deque, add elements to it using
 * an index, and then display those elements using an index. Here we
 * process the deque as though it were any container, using its
 * push_back function, but without using its iterator.
 */
int main( ) {
    deque <float> myDeck;

    // can use push_front() and push_back() efficiently
    for (size_t i = 0; i < 7; i++) {
        myDeck.push_front(i * 1.1);
        myDeck.push_back(i * 1.1);
    }

    for (auto f : myDeck)
        cout << f << ' ' ;

    cout << endl;
    return 0;
}


