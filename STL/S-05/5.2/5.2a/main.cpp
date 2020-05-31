#include <iostream>
#include <utility>

#include "simple_string.h"
#include "point.h"
using namespace std;

/**
 * This program demonstrates several usage of the STL pair template.
 */
int main() {
  // Instantiate an object of the point class to make a point.
  point<int, int> my_point(100, 200);
    
  cout << "my_point.x: "
       << my_point.x
       << "\nmy_point.y: "
       << my_point.y
       << endl;
    
  // Create several other more interesting "points".
  point<string, string> book_chapter_1("Chapter1",
                                       "Meet the C++ STL");

  cout << "book_chapter_1.x: "
       << book_chapter_1.x
       << "\nbook_chapter_1.y: "
       << book_chapter_1.y
       << endl;

  point<string, void *> debug("mynum",
                              reinterpret_cast<void *>(0x410928a8));

  cout << "debug.x: "
       << debug.x
       << "\ndebug.y: "
       << debug.y
       << endl;

  point<simple_string, simple_string> book_chapter_2
    (MOVE(simple_string("Chapter2")),
     MOVE(simple_string("Meet the C++ STL associative containers")));

  cout << "book_chapter_2.x: "
       << (const char *) book_chapter_2.x
       << "\nbook_chapter_2.y: "
       << (const char *) book_chapter_2.y
       << endl;

  return 0;
}
