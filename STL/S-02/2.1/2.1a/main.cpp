/**
 * C++ is a "strongly-typed language", i.e. a program must declare all
 * variables with their datatypes before they are used. Strong typing
 * helps ensure that the correct amount of storage is used for each
 * variable and that only the correct operations can be performed on
 * its data. In addition, data type checking for each variable
 * prevents memory leaks and illegal operations that might causes
 * exceptions in a running program.
 *
 * One drawback of strong typing, however, occurs when a program needs
 * to perform the same action on many types of variables.  Languages
 * like C that lacked classes or OO technology used #define
 * preprocessor directives to define variables and even small
 * functions without datatypes. Another way to perform such actions in
 * C uses void pointers since no datatype is explicitly involved.
 * Unfortunately, these workarounds don’t operate in a datatype safe
 * manner – they just avoid the type checking that C or C++ provides.
 *
 * Moreover, neither of these options uses the power of modern OO
 * languages. Other techniques (such as making all such functions or
 * classes refer to an Object) also don’t solve the problem
 * entirely. They are objected-oriented, but still incur the problem
 * that the data type checking part of C++ is bypassed.
 * 
 * To preserve the power of C++’s datatype checking, another way is to
 * use many overloaded functions in a class, each having a different
 * type of data as input. The problem with this approach occurs during
 * the sustainment phase, when the program must be enhanced,
 * maintained, fixed, etc. The job of keeping all of these functions
 * in sync then becomes very hard.
 *
 * To address this problem, C++ defines the "function template"
 * feature, which enables programmers to write ONE function that takes
 * parameter(s) of any datatype.  C++ also defines "class templates,"
 * which cohesively group together one or more member functions whose
 * types and/or values can be parameterized wholesale.
 *
 * The examples in this section explore the use of C++ function and
 * class templates.  These C++ capabilities form the foundation for
 * the Standard Template Library (STL), so it's essential to
 * understand how they work.
*/
