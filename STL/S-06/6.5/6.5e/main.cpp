#include <iostream>   	// for cout, endl
#include <fstream>    	// for ofstream, istreambuf_iterator
#include <stdio.h>    	// for tmpnam () and remove ()
using namespace std;

int main () {
  const char *fname = tmpnam (0);    // temp filename
  if (!fname)
    return 1;
  ofstream out (fname, ios::out | ios::in | ios::trunc);
 
  // output the example sentence into the file
  out << "Here is a sample sentence for output.\n"
    "I hope that you like this sentence out there.";
  // go to the beginning of the file
  out.seekp (0);

  // construct an istreambuf_iterator pointing to the ofstream object
  // underlying streambuffer
  istreambuf_iterator<char> iter (out.rdbuf ());

  // construct an end of stream iterator
  const istreambuf_iterator<char> end;
  cout << endl;
  // output the content of the file
  while (iter != end)
    cout << *iter++;

  // Alternative more concise approach is:
  // copy (istreambuf_iterator<char> (out.rdbuf ()),
  //		  istreambuf_iterator<char> (),
  //		  ostream_iterator<char> (cout));

  cout << endl;
  remove (fname);     // remove the temp file
  return 0;
}
