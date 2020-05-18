#include <iostream>
#include <string>
using namespace std;

int main() {
    string myLetters="abcdefghijklmnopqrstuvwxyz";

    int i = 0;

    for(char myLetter : myLetters)
        cout << ++i << " " << myLetter << endl;

    return 0;
}



