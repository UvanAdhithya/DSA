// Circular linked list menu
#include <iostream>

using namespace std;

class list{
    private:
        int num;
        struct Node{
            int data;
            struct Node *next;
        }*head;
    public:
        list(){
            head = NULL;
        }
        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int,int);
        int delete_beginning();
        int delete_end();
        int delete_pos(int);
        int search(int);
        void display();
};

int main(){
    list l1;
    int value,option, position;
    do{
        cout << "Choose an option niggeeRRRRRrr!!!" << endl;
        cout << endl;
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Exit" << endl;
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter the number to insert: ";
                cin >> value;
                l1.insert_beginning(value);
                break;
            case 2:
                cout << "Enter the number to insert: ";
                cin >> value;
                l1.insert_end(value);
                break;
            case 3:
                cout << "Enter the number to insert: ";
                cin >> value;
                cout << "Enter the position to insert in: ";
                cin >> position;
                l1.insert_position(value,position);
                break;
            case 4:
                l1.delete_beginning();
                break;
            case 5:
                l1.delete_end();
                break;
            case 6:
                cout << "Enter the position to delete in: ";
                cin >> position;
                l1.delete_pos(position);
                break;
            case 7:
                cout << "Enter the value to find index for: ";
                cin >> value;
                l1.search(value);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                cout << "Program Exited"<<endl;
                break;
            default:
                cout << "Invalid input try again" << endl;
                
        }
    }while(option < 9);
    return 0;
}

void list::insert_beginning(int num){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    if (head == NULL){
        head = newnode;
        newnode->next = head;
    }else{
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void list::insert_end(int num){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = head;
    if(head == NULL){
        head = newnode;
        newnode->next = head;
    }else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
}

void find_waiting_time(int rt, int bt, int wt){
    int time_quantum = 0;
}

void list::insert_position(int value, int pos){
    struct Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        newnode->next = head;
        return;
    }

    if(pos == 1){
        return insert_beginning(value);
    }

    Node* temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if(count != pos - 1){
        cout<<"Invalid position"<<endl;
        delete newnode;
        return;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;

}

int list::delete_beginning(){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1; 
    }

    int data;
    if (head->next == head) { 
        data = head->data;
        free(head);
        head = NULL;
    } else {

        Node* temp = head;
        Node* last = head;

        while (last->next != head){
            last = last->next;
        }

        data = head->data;
        head = head->next;
        last->next = head;
        free(temp);
    }
    return data;
}
int list::delete_end(){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1; 
    }else{

        struct Node *temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        int data = temp->next->data;
        free(temp->next);
        temp->next = head;
        return data;

    }
}

int list::delete_pos(int pos){
    if(head == NULL || pos < 1){
        cout<<"Invalid"<<endl;
        return -1;
    }

    if (pos == 1) {  // Special case: Delete the head
        return delete_beginning();
    }
    
    Node* temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == head || count != pos - 1){
        cout<<"Invalid position"<<endl;
        return -1;
    }

    temp->next = temp->next->next;
    Node* delnode = temp->next;
    int data = delnode->data;

    free(delnode);
    return data;
    
}

int list::search(int key) {
    if (head == NULL) {
        return -1;
    }

    struct Node* temp = head;
    int position = 1;

    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    return -1; 
}


void list::display(){
    if(head == NULL){
        cout << "List is empty" << endl;
    }else{

        Node* temp = head;
        do{
            cout << temp->data <<"->";
            temp = temp->next;
        } while(temp != head);

        cout << "NULL" << endl;
    }
}