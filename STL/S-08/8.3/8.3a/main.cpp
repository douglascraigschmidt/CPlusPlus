#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * Three of the most common reasons to use functors instead of using
 * ordinary functions are: 
 *
 * 1. To use an existing functor provided by the standard library
 *    instead of creating a new function.
 *
 * 2. To improve execution by using inline function calls. 
 *
 * 3. To allow a functor to access or set state information that is
 *    held by an object.
 *
 * How Functors differ from functions and algorithms
 * 
 * o Each functor does a single, specific operation
 *   . Often implemented as small classes or structs
 *   . Often has only one public member function: operator()
 * 
 * o Functors can have member variables
 *   . Arguments not stored may be supplied at point of call
 *   . Member variables can parameterize the operations such as the
 *     value k for a +k functor or arguments for an invocation on a
 *     remote object
 * 
 * Types of Functors
 *
 * o The comparison and predicate functors return a boolean value
 *   indicating the result of a comparison such as: 
 *   . one object greater than another, or
 *   . Telling an algorithm whether to perform a conditional action.
 *     For example to remove all objects with a particular attribute. 
 *
 * o The numeric functors perform operations like addition,
 *   subtraction, multiplication or division. These usually apply to
 *   numeric types, but some, like +, can be used with strings. 
 */
