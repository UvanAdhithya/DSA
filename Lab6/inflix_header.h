#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    char data;
    Node* next;
};

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    // Push element onto stack
    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop element from stack
    char pop() {
        if (isEmpty()) return '\0';  // Handle empty stack case
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Peek top element
    char peek() {
        if (isEmpty()) return '\0';
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

#endif