// Stack using linked list menu
#include <iostream>

using namespace std;

class Stack{
    private:
        int val;
        struct Node{
            int data;
            struct Node *next;
        }*head;
    public:
        Stack(){
            head = NULL;
        }
        int pop();
        void push(int);
        int peek();
};

int main(){
    int option;
    int value;
    Stack l1;
    do{
        cout << "Choose an option:\n1.Push\n2.Pop\n3.Peek stack\n4.Exit" <<endl;
        cin >> option;
        switch(option){
            case 1:
                // Push
                cout << "Enter a number " << endl;
                cin >> value;
                l1.push(value);
                break;
            case 2:
                // Pop
                cout << l1.pop() << endl;
                break;
            case 3:
                // Peek
                cout << l1.peek() << endl;
                break;
            case 4:
                cout << "Program exited..." << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(option != 4);
}

void Stack::push(int val){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

int Stack::pop(){
    if (head == NULL){
        cout << "Stack empty" << endl;
        return -1;
    }else{
        struct Node *temp = head;
        head = head->next;
        int num = temp->data;
        free(temp);
        return num;
    }
}

int Stack::peek(){
    if (head == NULL){
        cout << "Stack is empty" << endl;
        return -1;
    }else{
        return head->data;
    }
}