// Uses a Array to reverse a name and test various properties of class
// Array<>.

#include <assert.h>
#include <iterator>
#include <functional>
#include <iostream>
#include <cstdio>
#include <string>
// #define RVALUE_REFERENCES
#include "Array.h"

static const char PROMPT[] = "please enter your name..: ";

static const int PROMPT_LENGTH = sizeof (PROMPT);

static const Array<char>::value_type DEFAULT_VALUE = 'D';

/**
 * Prompt the user to enter their name.  Note value semantics for both
 * param and return value.
 */
static Array<char>
get_name(Array<char> prompt) {
    // Prompt the user.
    std::copy (prompt.begin(),
               prompt.end(),
               std::ostream_iterator<char> (std::cout));

    std::string name;

    std::getline (std::cin, name);

    Array<char> a;

    std::copy (name.begin(),
               name.end(),
               std::back_inserter (a));
    return a;
}

#if defined(RVALUE_REFERENCES)
#define moveit std::move
#else
#define moveit
#endif /* RVALUE_REFERENCES */

int
main (int argc, char *argv[])
{
    Array<char> prompt (PROMPT_LENGTH);

    std::copy(PROMPT,
              PROMPT + PROMPT_LENGTH,
              prompt.begin());

    // Pass param by value and return result by value (may or may not be
    // optimized).
    Array<char> a = get_name(moveit(prompt));

    std::cout << "your name backwards is..: ";

    std::reverse_copy(a.begin(),
                      a.end(),
                      std::ostream_iterator<char> (std::cout));

    std::cout << std::endl;

    // Perform an assignment (may or may not be optimized).
    prompt = moveit(a);

    std::cout << "your name forwards is..: ";

    std::copy(prompt.begin(),
              prompt.end(),
              std::ostream_iterator<char> (std::cout));

    std::cout << std::endl;

    return 0;
}
