#include <utility>
#include <iostream>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;

struct print { // Iterator value is a key-value pair.
  void operator() (const map<string, string>::value_type &p) {
    cout << p.first << "=" << p.second << endl; 
  }
};

/**
 * This program demonstrates several other capabilities of STL map.
 */ 
int main() {
  pair<string, int> pr("heaven", 7);
  cout << pr.first << "=" << pr.second << endl;    // Prints heaven=7
        
  // Declare and initialize pair pointer.
  unique_ptr<pair<string, int>> prp (new pair<string,
                                                int>("yards", 9));
  cout << prp->first << "=" << prp->second << endl;      // Prints yards=9
        
  // Declare map and assign value to keys.
  map<string, string> engGerDict;
  engGerDict["shoe"] = "Schuh";
  engGerDict["head"] = "Kopf";

  map<string, string>::value_type vt("yes", "Ja");
  engGerDict.insert(vt);
    
  // Iterate over map in sorted order.  
  for_each (engGerDict.begin(),
            engGerDict.end(),
            print ());

  auto iter = engGerDict.find("yes");
  if (iter != engGerDict.end())
    engGerDict.erase(iter);

  // Iterate over map in sorted order.  
  for_each (engGerDict.begin(),
            engGerDict.end(),
            // Use a lambda function.
            [](const map<string, string>::value_type &p) { 
              cout << p.first << "=" << p.second << endl; 
            });
            
  return 0;
}
