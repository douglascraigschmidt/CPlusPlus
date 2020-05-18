/**
 * C++ is a "strongly-typed language", i.e. a program must declare all
 * variables with their datatypes before they are used. Strong typing
 * is great for ensuring that the correct amount of storage is used
 * for each variable and that only the correct operations can be
 * performed on its data. In addition, data type checking for each
 * variable prevents memory leaks and illegal operations that might
 * causes exceptions in a running program.
 *
 * However, one drawback of strong typing occurs when a program needs
 * to perform the same or a similar action on many types of variables.
 * Without having classes or OO technology, a language such as C, used
 * #define preprocessor directives to define variables and even small
 * functions without datatypes. Another way to perform such actions in
 * C uses void pointers since no datatype is explicitly involved.
 * Unfortunately, these work-arounds don’t operate in a datatype safe
 * manner – they just avoids the type checking that C or C++ provides.
 *
 * Moreover, neither of these options uses the power of modern OO
 * languages. Other techniques (such as making all such functions or
 * classes refer to Object or an Object reference) also don’t solve
 * the problem entirely. They are objected oriented, but still incur
 * the problem that the data type checking part of C++ is bypassed.
 * 
 * To preserve the power of C++’s datatype checking, another way is to
 * use many overloaded functions in a class, each having a different
 * type of data as input. The problem with this comes later when the
 * program needs to be enhanced, maintained, fixed, etc. Then the job
 * of keeping all of these functions in sync is a hard one. Why
 * not have ONE function that takes one parameter of any datatype?
 * That capability is precisely a "function template" provides!
 *
 * C++ also defines "class templates," which cohesively group together
 * one or more member functions whose types and/or values can be
 * parameterized.
*/
