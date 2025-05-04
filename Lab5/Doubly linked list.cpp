// Doubly Linked List  Menu 
#include <iostream>

using namespace std;

class list{
    private:
        int val, pos;
        struct Node{
            struct Node *prev;
            int data;
            struct Node *next;
        }*head,*tail;
    public:
        list(){
            head = NULL;
            tail = NULL;
        }


        void insert_beginning(int);
        void insert_end(int);
        void insert_at_position(int,int);
        int delete_beginning();
        int delete_end();
        int delete_at_position(int);
        int search(int);
        void display();
     


};

void list::insert_beginning(int val){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        struct Node *temp = head;
        head = newnode;
        tail = head;
    }else{
        struct Node *temp = head;
        head = newnode;
        newnode->next = temp;
        temp->prev = newnode;
    }
    
}

void list::insert_end(int val){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        struct Node *temp = head;
        head = newnode;
        tail = head;
    }else{
        struct Node* temp = tail;
        tail = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }
}

void list::insert_at_position(int position, int value) {
    struct Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Insert at the beginning
    if (position == 1) {
        if (head == NULL) { 
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If position invalid
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    // Insert at end
    if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    // Insert in middle
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}


int list::delete_beginning(){
    if (head == NULL){
        cout << "List is empty" << endl;
        return -1;
    }

    int data = head->data;
    struct Node *temp = head;

    if (head->next == NULL) { 
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL; 
    }

    free(temp);
    return data;
}

int list::delete_end(){
    if (head == NULL){
        cout << "List is empty" << endl;
        return -1;
    } 
    
    int data = tail->data;
    struct Node* temp = tail;

    if (tail->prev == NULL) { 
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL; // Fix dangling pointer
    }

    free(temp);
    return data;
}

int list::delete_at_position(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }

    struct Node* temp = head;
    int count = 1;

    // If deleting the first node
    if (position == 1) {
        return delete_beginning();
    }


    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    // Position invalid
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return -1;
    }

    // If deleting the last node
    if (temp->next == NULL) {
        return delete_end();
    }

    // Delete middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    int data = temp->data;
    free(temp);
    return data;
}


int list::search(int key) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            return position; // Found the key
        }
        temp = temp->next;
        position++;
    }

    return -1; // Key not found
}


void list::display(){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    struct Node *temp = head;
    struct Node *temp2 = tail;

    // Print forwards
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<< endl;

    // Print backwards
    cout << "NULL->";
    while(temp2 != NULL){
        cout << temp2->data << "->";
        temp2 = temp2->prev;
    }
    cout << "NULL" << endl;
}

int main(){
    int value, position, option;
    list l1;
    cout << "HI" << endl;
    do{
        cout << "Choose an option:" << endl;
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert at a position\n4.Delete beginning\n5.Delete End\n6.Delete at a position\n7.Search\n8.Display\n9.Exit" << endl;
        cin >> option;
        switch(option){
            case 1:
                // Insert beg
                cout << "Enter number to insert:"<< endl;
                cin >> value;
                l1.insert_beginning(value);
                break;
            case 2:
                cout << "Enter number to insert:"<< endl;
                cin >> value;
                l1.insert_end(value);
                break;
            case 3:
                // Insert at a pos
                cout << "Enter number to insert:"<< endl;
                cin >> value;
                cout << "Enter position to be inserted in:" << endl;
                cin >> position;
                l1.insert_at_position(position, value);
                break;
            case 4:
                // Delete beginning
                l1.delete_beginning();
                break;
            case 5:
                // Delete end
                l1.delete_end();
                break;
            case 6:
                // Delete at pos
                cout << "Enter position to be inserted in:" << endl;
                cin >> position;
                l1.delete_at_position(position);
                break;
            case 7:
                // Search
                cout << "Enter number to search:"<< endl;
                cin >> value;
                l1.search(value);
                break;
            case 8:
                // Display
                l1.display();
                break;
            case 9:
                cout << "Program Exited..."<< endl;
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }while(option < 9);
    return 0;


}