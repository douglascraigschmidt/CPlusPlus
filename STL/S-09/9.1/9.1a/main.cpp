#include <iostream>

using namespace std;

/**
 * In general, adaptors can transform one predefined interface to
 * another. The STL has predefined functor adaptors that will change
 * their functors so that they can:
 *
 * . Perform function composition and binding
 * 
 * . Allow fewer created functors
 * 
 * . Allow building functions as graphs (especially chains and trees)
 *   of other functions
 * 
 * These functors allow one to combine, transform, or manipulate
 * functors with each other, certain values, or with special functions.
 * They are divided into the following categories:
 * 
 * Type of adaptor  STL adaptor        What it does
 * 
 * binders          bind1st, bind2nd   adapt functors by "binding" one of their arguments
 * negators         not1, not2, not_fn adapt functor by negating arguments
 * member functions ptr_fun            allow functors to be class member
 *                  mem_fun            function adaptors                
 *                  mem_fun_ref
 */
