#include <iostream>
#include <cctype>
#include <cstdlib>
#include "fix.h"  // Include the stack header file

using namespace std;

string infixExpression = "";
string postfixExpression = "";

// Function to get operator precedence
int precedence(char op) {
    if (op == '=')
        return 1;
    if (op == '+' || op == '-')
        return 2;
    if (op == '*' || op == '/')
        return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // Add operands to postfix
        } 
        else if (c == '(') {
            stack.push(c);
        } 
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Pop '('
        } 
        else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    Stack stack;

    for (char c : postfix) {
        if (isdigit(c)) {
            stack.push(c - '0');  // Convert char to int and push
        } 
        else {
            int val2 = stack.pop();
            int val1 = stack.pop();

            switch (c) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return 0;
                    }
                    stack.push(val1 / val2);
                    break;
                case '=': 
                    cout << "Assignment operator used, storing value: " << val2 << endl;
                    return val2; // Simulating assignment operation
            }
        }
    }
    return stack.pop(); // Final result
}

int main() {
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                cin >> infixExpression;
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "Error: No infix expression entered!\n";
                } else {
                    postfixExpression = infixToPostfix(infixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "Error: No postfix expression found!\n";
                } else {
                    cout << "Postfix Evaluation Result: " << evaluatePostfix(postfixExpression) << endl;
                }
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
