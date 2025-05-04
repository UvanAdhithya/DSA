// Circular Queue ADT Menu
#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
    private:
        int* arr;         
        int capacity;     
        int front;        
        int rear;         
        int count;        // Current size of the queue

    public:
        // Constructor
        CircularQueue() {
            arr = new int[SIZE];
            capacity = SIZE;
            front = 0;
            rear = -1;
            count = 0;
        }
        void enqueue(int);
        int dequeue();
        int peek();
        void display();
        bool isEmpty();
        bool isFull();
};

int main(){
    int option;
    int value;
    CircularQueue q1;
    do{
        cout << "Choose an option:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit" <<endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "Enter a number to enqueue:";
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << q1.dequeue() << endl;
                break;
            case 3:
                cout << "The front element is " << q1.peek() << endl;
                break;
            case 4:
                q1.display();
                break;
            case 5:
                cout << "Program exited..." << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(option != 5);
}

void CircularQueue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot enqueue " << x << endl;
        return;
    }

    // Circular increment of rear
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
    cout << "Enqueued " << x << " to the queue" << endl;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue from an empty queue" << endl;
        return -1;
    }

    int x = arr[front];
    cout << "Dequeued " << x << " from the queue" << endl;

    // Circular increment of front
    front = (front + 1) % capacity;
    count--;

    return x;
}

int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[front];
}

bool CircularQueue::isEmpty() {
    return (count == 0);
}

bool CircularQueue::isFull() {
    return (count == capacity);
}

void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    int itemsDisplayed = 0;
    
    while (itemsDisplayed < count) {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
        itemsDisplayed++;
    }
    cout << endl;
}