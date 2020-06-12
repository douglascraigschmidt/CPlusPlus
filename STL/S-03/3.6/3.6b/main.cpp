#include <string>
#include <iostream>
using namespace std;

/**
 * Here are some examples of C++ string creation.
 */
int main() {
  // create a string by using a char string
  const char *ptr = "say goodnight, Gracie";

  // create a string initialized by const char* string pointer.
  string str1(ptr);

  string str2("say goodnight, Gracie");  // or even using the constructor
  string str3(str2);                     // by another string

  // by a substring of another string - a 9 char substring starting
  // with the 4th character
  string str4(str3, 4, 9);

  string str5 = str3.substr(4, 9) ;     // or an explicit call to substr method

  string::size_type pos = str2.find("Gracie",0);

  // To find where a substring starts, erase it, and insert another,
  // use the following code:
  if (pos != string::npos) {   // check that found
    str2.erase(pos, 6);
    str2.insert(pos, "Irene");
    cout << str2 << endl;
  }

  // Appending strings can be done using the plus (+) operator:
  str3 = str2 + " " + str4;
  cout << str3 << endl;

  // To find the first instance of one of a number of characters, use
  // the following code:
  string match = "Ie";
  pos = str2.find_first_of(match,0);

  cout << "Found character " << str2[pos]
       << " at position " << pos << endl;

  return 0;
}



