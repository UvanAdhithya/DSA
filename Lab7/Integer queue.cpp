// Integer queue
#include <iostream>
#define SIZE 5

using namespace std;

class queue{
    private:
        int* arr;
        int value;
        int front;
        int rear;
    public:
        queue(){
            arr = new int[SIZE];
            rear = -1;
            front = -1;
        }
        void enqueue(int);
        int dequeue();
        int peek();
        void display();
        
};

int main(){
    int option;
    int value;
    queue q1;
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

void queue::enqueue(int value){
    if(rear == SIZE -1){
        cout << "Queue overflow" << endl;
        return;
    }else if(front == -1){
        front = 0;
    }
    rear++;
    arr[rear] = value;
}

int queue::dequeue(){
    if(front == -1 || front > rear){
        cout << "Queue underflow" << endl;
        return -1;
    }

    int x = arr[front];
    cout << "Dequeued "<< x << " from the queue" << endl;
    arr[front] = 0;
    // If last element then reset the queue
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front++;
    }
    return x;
}

void queue::display(){
    if(rear == -1){
        cout << "Queue underflow" << endl;
        return;
    }
    for(int i = 0; i < SIZE ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int queue::peek(){
    if(front == -1 || front > rear){
        return -1;
    }
    int x = arr[front];
    return x;
}