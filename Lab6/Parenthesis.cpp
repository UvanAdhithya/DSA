#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    
    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);  // Push opening bracket
        } else if (ch == ')') {
            if (st.empty()) return false;  // No matching opening bracket
            st.pop();  // Pop the matching opening bracket
        }
    }
    
    return st.empty();  // If stack is empty, it's balanced
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> input;
                cout << (isBalanced(input) ? "Balanced" : "Unbalanced") << endl;
                break;
            case 2:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    } while (choice != 2);

    return 0;
}
