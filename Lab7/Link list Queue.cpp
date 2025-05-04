// Queue menu with Linked List ADT
#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enqueue(int);
    void dequeue();
    void peek();
};

void displayMenu() {
    cout << "\n==========Queue ADT Menu==========\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting... Bye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued successfully.\n";
}

void Queue::dequeue() {
    if (front == NULL) {
        cout << "Queue is empty. Nothing to dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    cout << "Dequeued " << temp->data << " from the queue.\n";
    delete temp;
}

void Queue::peek() {
    if (front == NULL) {
        cout << "Queue is empty. Nothing to peek.\n";
    } else {
        cout << "Front element is: " << front->data << endl;
    }
}
