// Stack menu
#include <iostream>

using namespace std;

class Stack{
    private:
        char val;
        int arr[5] = {0};
        int top;
    public:
        Stack(){
            top = -1;
        }
        char push(char);
        char pop();
        char peek();
};

int main(){
    int option;
    char value;
    Stack l1;
    do{
        cout << "Choose an option:\n1.Push\n2.Pop\n3.Peek stack\n4.Exit" <<endl;
        cin >> option;
        switch(option){
            case 1:
                // Push
                cout << "Enter a character: " << endl;
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


char Stack::push(char val){
    if(top == 4){
        cout << "Stack Overflow" << endl;
        return '\0';
    }else{
        arr[++top] = val;
        return val;
    }
}

char Stack::pop(){
    if(top == -1){
        cout << "Stack is empty" << endl;
        return '\0';
    }else{
        return arr[top--];
    }
}

char Stack::peek(){
    if (top == -1){
        cout << "Stack is empty" << endl;
        return '\0';
    }
    else{
        return arr[top];
    }
}