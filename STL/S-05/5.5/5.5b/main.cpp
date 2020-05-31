#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;

struct print { // Iterator value is a key-value pair.
  void operator () (const map<string, string>::value_type &p) { 
    cout << p.first << "=" << p.second << endl; 
  }
};

/**
 * This program demonstrates several other capabilities of STL map.
 */ 
int main() {
  pair<string, int> pr1, pr2("heaven", 7);
  cout << pr2.first << "=" << pr2.second << endl;    // Prints heaven=7
        
  // Declare and initialize pair pointer.
  unique_ptr<pair<string, int>> prp (new pair<string,
                                                int>("yards", 9));
  cout << prp->first << "=" << prp->second << endl;      // Prints yards=9
        
  // Declare map and assign value to keys.
  map<string, string> engGerDict;
  engGerDict["shoe"] = "Schuh"; engGerDict["head"] = "Kopf";
    
  // Iterate over map in sorted order.  
  for_each (engGerDict.begin(),
            engGerDict.end(),
            print ());

  // Iterate over map in sorted order.  
  for_each (engGerDict.begin(),
            engGerDict.end(),
            // Use a lambda function.
            [](const map<string, string>::value_type &p) { 
              cout << p.first << "=" << p.second << endl; 
            });
            
  return 0;
}
