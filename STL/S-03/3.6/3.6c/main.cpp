#include <string>
#include <iostream>
using namespace std;

/**
 * More examples of using C++ string class functions.
 */
int main () {
  string a("abcd efg");
  string b("xyz ijk");
  string c;
  cout << a << " " << b << endl;
  cout << "String empty: "  << c.empty()    << endl;

  c = a + b;
  cout << c << endl;
  cout << "String length: "   << c.length()   << endl;
  cout << "String size: "     << c.size()     << endl;
  cout << "String capacity: " << c.capacity() << endl;
  cout << "String empty: "    << c.empty()    << endl;

  string d = c;
  cout << d << endl;
  cout << "First character: " << c[0] << endl;

  string f("    Leading and trailing blanks      ");
  cout << "String f:" << f << endl;
  cout << "String length: " << f.length() << endl;

  cout << "String f:" << f.append("ZZZ") << endl;
  cout << "String length: " << f.length() << endl;
  string g("abc abc abd abc");
  cout << "String g: " << g << endl;

  // Replace 12,1,"xyz",3: abc abc abd xyzbc
  cout << "Replace 12,1,\"xyz\",3: "
       << g.replace(12,1,"xyz",3) << endl;
  cout << g.replace(0,3,"xyz",3) << endl;
  cout << g.replace(4,3,"xyz",3) << endl;
  cout << g.replace(4,3,"ijk",1) << endl;

  cout << "Find: " << g.find("abd",1) << endl;
  cout << (g.find("qrs",1) == string::npos) << endl;

  string h("abc abc abd abc");
  cout << "Find_first_not_of \"abc\",0: "
       << h.find_first_not_of("abc",0) << endl;
  cout << "Find_first_not_of \" \": "
       << h.find_first_not_of(" ") << endl;
  return 0;
}
