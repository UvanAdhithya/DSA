// Removes '+' and preceeding  non '+' element 
#include <iostream>
#include "plus.h"
using namespace std;

int main() {
    string input;

    cout << "Enter a string with '+' symbols: ";
    cin >> input;

    string output = processString(input);

    cout << "Processed string: " << output << endl;

    return 0;
}
