#ifndef PLUS
#define PLUS

#include <stack>
#include <iostream>
using namespace std;

string processString(string input) {
    stack<char> s; 
    string result = "";

    for (char c : input) {
        if (c == '+') {
            // If '+' is encountered, remove the top character if the stack is not empty
            if (!s.empty()) {
                s.pop(); // Remove the character before '+'
            }
        } else {
            s.push(c); 
        }
    }

    // Build the final string from the stack
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }

    return result;
}

#endif