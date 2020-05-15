#include <iostream>
#include <bitset>
using namespace std;

int main()    {
    bitset<16> aFewBits(32);
    cout << "Bits:"  <<  aFewBits  << endl;
    aFewBits[0] = true;     aFewBits[2] = false;
    aFewBits[10] = true;   aFewBits[12] = true;
    cout << "Bits:" <<   aFewBits << endl;
    aFewBits <<= 2;   // rotate bits
    cout << "Bits rotate: " << aFewBits   << endl;
    aFewBits.flip(); 			                                  // flip bits
    cout << "After flipping bits:    " << aFewBits  << endl;
    if(aFewBits.any())
        cout << "aFewBits has at least 1 bit set.\n";
    cout << "aFewBits has " << aFewBits.count()  << " bits set.\n";
    if(aFewBits[0] == 1)
        cout << "bit 0 is on\n";
    if(aFewBits.test(1))
        cout << "bit 1 is on\n";
    // can add bits to integers
    cout << "Add 11 to bit 0: " << aFewBits[0] + 11 << endl;
    return 0;
}



