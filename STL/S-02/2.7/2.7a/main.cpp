#include <vector>
#include <string>
#include <list>
#include <deque>
using namespace std;

/**
 * A template can take a parameter that is itself the name of a
 * template. These parameters have the name of template template
 * parameters. Let¡¯s use a simple example. Start with a template for a
 * stack that would accept a type of data to be stored and a container
 * type to adapt into a stack.
 *
 * The first parameter, T, is just the name of a datatype as
 * usual. The second parameter, Container, is a ¡®template template¡¯
 * parameter. It's the name of a class template that has a single type
 * name parameter, and we didn¡¯t specify a type of data contained in
 * the original container.
 *
 * The Stack template uses its ¡®type name¡¯ parameter to instantiate
 * its ¡®template template¡¯ parameter. The resulting container type is
 * used to implement the Stack object:
*/
template <typename T, template <typename ...> class Container = deque>
class Stack {
public:
    // ...
private:
    Container<T> s;
};

/**
 * The template template parameter approach above allows coordination
 * between the element and its container to be handled by the
 * implementation of the Stack itself, rather than in all the various
 * code that specializes the Stack class.
 *
 * Tis single point of specialization reduces the possibility of
 * mismatches between the element type and the container used to hold
 * the elements.
 * 
 * Below, we show how to create a Stack object from a list or from a
 * deque.  The Stack created from the list will hold integers while
 * the Stack created from the deque will hold strings. All of this
 * resulted from allowing the Stack template to have a parameter that
 * is itself a template.
*/
int main() {
    Stack<string> aDequeStackofStrings; // defaults to deque
    Stack<int, list> aListStackofInts;

    return 0;
}

