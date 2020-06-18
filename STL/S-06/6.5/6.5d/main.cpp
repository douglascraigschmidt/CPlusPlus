#include <iostream>   	// for cout, endl
#include <fstream>    	// for ofstream, istreambuf_iterator
#include <cstdio>    	// for tmpnam () and remove ()
using namespace std;

/**
 * A third type of stream iterator adaptor is the stream buffer
 * iterator, and there are two types, istreambuf_iterator for reading
 * and ostreambuf_iterator for writing streams.  These template class
 * objects can read or write individual characters from or to
 * basic_streambuf objects.
 *
 * The class template istreambuf_iterator reads successive characters
 * from the stream buffer for which it was constructed. operator*()
 * gives access to the current input character, if any, and
 * operator++() advances to the next input character. If the end of
 * stream is reached, the iterator becomes equal to the end of stream
 * iterator value, which is constructed by the default constructor,
 * istreambuf_iterator(). An istreambuf_iterator object can be used
 * only for one-pass-algorithms.
*/
int main () {
  const char *fname = tmpnam (nullptr);    // temp filename
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
#if 0
  istreambuf_iterator<char> first (out.rdbuf ());

  // construct an end of stream iterator
  const istreambuf_iterator<char> last;
  cout << endl;

  // Output the content of the file
  while (first != last)
    cout << *first++;
#else
  // Alternative more concise approach is:
  copy (istreambuf_iterator<char> (out.rdbuf ()),
        istreambuf_iterator<char> (),
        ostream_iterator<char> (cout));
#endif

  cout << endl;

  remove (fname);     // remove the temp file

  return 0;
}
