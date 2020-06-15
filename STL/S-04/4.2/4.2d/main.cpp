#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * This example demonstrates how to read command-line arguments into a
 * vector and then print them via an iterator.
 */
int main (int argc, char *argv[]) {
  std::vector <std::string> arguments;

  for (int i = 1; i < argc; ++i)  
    arguments.emplace_back (std::string (argv [i]));

  for (std::vector<std::string>::iterator j = arguments.begin ();
       j != arguments.end ();
       ++j)
    std::cout << *j << std::endl;

  return 0;
}
