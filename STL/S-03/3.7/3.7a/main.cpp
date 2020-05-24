#include <iostream>
#include <bitset>
using namespace std;

/**
 * The C++ Standard Library contains several classes that work
 * similarly to the STL's predefined container classes.
 *
 * A bitset provides a set of bits as a data structure. They can be
 * manipulated by various binary operators such as logical AND, OR,
 * etc. They are used to model sets of flags, bits or Boolean
 * values. Once a bitset is constructed, the size of the container
 * (bitset) cannot be changed.
 * 
 * Operations of bitset
 * 
 * !=   returns true if the two bitsets are not equal. 
 * ==   returns true if the two bitsets are equal. 
 * &=   performs the AND operation on the two bitsets. 
 * ^=   performs the XOR operation on the two bitsets. 
 * |=   performs the OR operation on the two bitsets. 
 * ~    reverses the bitset (same as calling flip()) 
 * <<=  shifts the bitset to the left 
 * >>=  shifts the bitset to the right 
 * [n]  returns a reference to the nth bit in the bitset. 
 */
int main() {
  // Create a bitset with 16 bites and the initial value of
  // 0b100000.
  bitset<16> aFewBits(32);
  cout << "Bits:" << aFewBits << endl;

  aFewBits[0] = true; aFewBits[5] = false;
  aFewBits[10] = true; aFewBits[12] = true;

  cout << "Bits:" << aFewBits << endl;

  aFewBits <<= 2;   // rotate bits
  cout << "Bits rotate: " 
       << aFewBits   << endl;

  aFewBits.flip();  // flip bits
  cout << "After flipping bits: " 
       << aFewBits  << endl;

  if (aFewBits.any())
    cout << "aFewBits has at least 1 bit set.\n";

  cout << "aFewBits has " 
       << aFewBits.count() << " bits set.\n";

  if (aFewBits[0] == 1)
    cout << "bit 0 is on\n";

  if (aFewBits.test(1))
    cout << "bit 1 is on\n";

  // can add bits to integers.
  cout << "Add 11 to bit 0: " 
       << aFewBits[0] + 11 << endl;

  return 0;
}



