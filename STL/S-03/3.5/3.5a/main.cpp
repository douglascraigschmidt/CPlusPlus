#include <iostream>
#include <list>
using namespace std;

/**
 * A list is a sequential collection of elements of type T.  List
 * containers are implemented as doubly-linked lists; Doubly-linked
 * lists can store each of the elements they contain in different and
 * unrelated storage locations. The ordering is kept by the
 * association to each element of a link to the element preceding it
 * and a link to the element following it.  This implementation
 * provides the following advantages to list containers:
 * 
 * . Efficient insertion and removal of elements anywhere in the
 *   container.
 * 
 * . Efficient moving elements and block of elements within the
 *   container or even between different containers.
 *
 * . Iterating over the elements in forward or reverse order.
 * 
 * Compared to vectors and deques, lists perform generally better in
 * inserting, extracting and moving elements in any position within
 * the container, and therefore also in algorithms that make intensive
 * use of these features.
 * 
 * The main drawback of lists compared to these other sequential
 * containers is that lists don?t provide direct (i.e., random) access
 * to the elements by their position. Thus, to access the sixth
 * element in a list, a program must iterate from a known position
 * (like the beginning or the end) to that position, which takes
 * linear time in the distance between these.
 *
 * List also use extra memory to keep the linking information
 * associated to each element (which may be an important factor for
 * large lists of small-sized elements).  As with deques, however,
 * storage is handled automatically by the class, allowing lists to be
 * expanded and contracted as needed.  If you are concerned about the
 * space overhead of the extra pointer needed to implement a
 * doubly-linked list then consider using the STL forward_list.
 *
 * The list implementation in the C++ Standard Template Library take
 * two template parameters:
 * 
 * template <typename T,
 *           typename Allocator = allocator<T> > 
 * class list;
 *
 * 1. T: Datatype of the elements to be stored. 
 * 
 * 2. Allocator: This is the allocator object used to define the
 *    storage allocation model. By default, the Allocator class
 *    template from <memory> for type T is used, which defines the
 *    simplest memory allocation model and is value-independent.
 *
 * Here's an example that uses an STL list.
 */

int main() {
    list<char> aList;

    for(int i = 0; i <10; i++)
        aList.push_back('A' + i);

    cout << "Size = " << aList.size() << endl;
    cout << "Contents: ";

    while (!aList.empty ()) {
        auto p = aList.begin();

        cout << *p;

        aList.pop_front();
    }
    return 0;
}



