#include <iostream>
#include <stack>
using namespace std;

/**
 * STL functors are classified based on their capabilities in various
 * ways.  For example, they can be categorized by whether the
 * functor's operator( ) takes zero, one or two arguments.  See the
 * new few pages for other classifications.
 * 
 * #1. Functors classified based on number of arguments:
 * 
 * . Generator - Takes no arguments and returns a value of the desired
 *   type. (A RandomNumberGenerator is a special case of a generator
 *   because it takes no arguments but returns a specific thing: a
 *   number.)  But generators can be defined to return any type of
 *   data; they just don't take any arguments as input.
 * 
 * . UnaryFunction - Takes a single argument of any type and returns a
 *   value which may be of a different type. 
 * 
 * . BinaryFunction - Takes two arguments of any two types and returns
 *   a value of any type.
 *    
 * #2. Functors returning a boolean result classified
 * 
 * A special case of the unary and binary functions is the predicate,
 * which simply means a function that returns a boolean result, which
 * is used to make a true/false decision.
 * 
 * . Predicate - This can also be called a UnaryPredicate. It takes a
 *   single argument of any type and returns a boolean result.
 * 
 * . BinaryPredicate - This type of predicate takes two arguments of
 *   the same data type, and returns a boolean result.  It can do
 *   anything inside the function.
 * 
 * #3. Functors classified based on the operators supported:
 * 
 * There are sometimes qualifications on the functor types passed into
 * algorithms. These qualifications are given as the template argument
 * type identifier name for the algorithm. They limit the type of
 * functor that can be used as the argument to that algorithm. Here
 * are some of them. 
 * 
 * . LessThanComparable - A functor class that has a less-than operator<.
 * 
 * . Assignable - A functor class that has an assignment operator =
 *   for its own type (all STL functors are assignable).
 * 
 * . EqualityComparable - A functor class that has an equivalence
 *   operator == .
 * 
 * For functors that are LessThanComparable and EqualityComparable,
 * the STL provides templates in the <utility> header file so they can
 * use the !=, the >=, and <= operators.
 * 
 * #4. Functors classified based whether they can carry a "state":
 * 
 * Having a state means having member variables that can take on
 * values. For example a class named Rectangle can have a fillColor
 * member variable. This could distinguish between different Rectangle
 * object instances.
 * 
 * . Stateless - Stateless functors are the closest correspondent to a
 *   regular function. The functor doesn't have data members, or, if
 *   it does, they have no impact whatsoever on the function call
 *   operator.
 * 
 * . State (constant) - Invariable functors do have a state, but the
 *   function call operator is declared constant.  This means that the
 *   operation will use the state, but won't change it.
 * 
 * . State (variable) - Variable functions objects not only have a
 *   state, but also can change this state with each operation.
 *
 * Functor efficiency considerations
 * 
 * o Passing parameters to Functors
 *   . Can be done by value or by reference
 *   . Same kinds of aliasing issues as with any other object
 * 
 * o Watch performance with many small functors
 *   . Watch out especially for creation and destruction overhead
 *   . May want to inline functors constructors and destructors
 *   . Put functors on stack instead of heap
 * 
 * o Functors are a powerful, general mechanism
 *   . Reduces programming complexity and increases reuse
 *   . Several new uses of generic programming
 *   . Could go farther with parameterization than just algorithms
 * 
 * Functors are often referred to as smart functions because they can:
 * . contain more than their primary function, i.e., operator(),
 * . hold data members (have a state), and 
 * . be passed to other functions.   
 */
