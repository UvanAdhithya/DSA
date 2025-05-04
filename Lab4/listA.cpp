//Linked list
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
        //Insert beg
        void insert_beginning(int);
        //Insert end
        void insert_end(int);
        //Insert value at position
        void insert_position(int,int);
        //Delete beg
        int delete_beginning();
        //Delete end
        int delete_end();
        //Delete pos
        int delete_pos(int);
        //Display reverse
        void display_reverse();
        //Display
        void display();
        //Reverse list
        void reverse_list();
};

void list::insert_beginning(int num){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}
void list::insert_end(int num){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        Node* temp = head;
        while(temp->next != NULL){
            //cout << temp->data <<"->";
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
}

void list::insert_position(int value, int pos){
    struct Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if(pos == 0){
        newnode->next = head;
        head = newnode;
        return;
    }

    struct Node *temp = head;
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    if(temp == NULL){
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
        return -1; // Indicate failure (or throw an exception)
    }else{
        struct Node *temp = head;
        head = head->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}
int list::delete_end(){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1; // Indicate failure (or throw an exception)
    }else{
        struct Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        int data = temp->next->data;
        free(temp->next);
        temp->next = NULL;
        return data;

    }
}

int list::delete_pos(int pos){
    if(head == NULL || pos < 1){
        cout<<"Invalid"<<endl;
        return -1;
    }

    if (pos == 1) {  // Special case: Delete the head
        Node* temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
    
    Node *temp = head;
    for(int i = 1; temp->next != NULL && i < pos - 1; i++){
        temp = temp->next;
    }

    temp->next = temp->next->next;
    Node* delnode = temp->next;
    int data = temp->next->data;
    free(delnode);
    return data;
    
}
void list::display_reverse(){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    cout << "NULL" << "->";
    int array[100];
    int size=0;
    Node *temp = head;
    for(int i = 0; temp != NULL; i++){
        array[i] = temp->data;
        temp = temp->next;
        size++;
    }
    for(int j = size -1; j>=0; j--){
        if(j == 0){
            cout << array[0] << endl;
        }else{
            cout << array[j] << "->";
        }
    }
}

void list::display(){
    if(head == NULL){
        cout << "List is empty" << endl;
    }else{
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<"->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}
void list::reverse_list(){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    cout << "NULL" << "->";
    int array[100];
    int size=0;
    Node *temp = head;
    for(int i = 0; temp != NULL; i++){
        array[i] = temp->data;
        temp = temp->next;
        size++;
    }
    temp = head;
    for(int j = size - 1; temp !=NULL; j--){
        temp->data = array[j];
        temp = temp->next;
    }   

}


int main(){
    list l1;
    int value,option, position;
    do{
        cout << "Choose an option niggeeRRRRRrr!!!" << endl;
        cout << endl;
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Display Reverse\n10.Reverse List\n11.Exit" << endl;
        cin >> option;
        
        switch(option){
            case 1:
                //insert beg
                cout << "Enter the number to insert: ";
                cin >> value;
                l1.insert_beginning(value);
                break;
            case 2:
                //insert End
                cout << "Enter the number to insert: ";
                cin >> value;
                l1.insert_end(value);
                break;
            case 3:
                //insert Position
                cout << "Enter the number to insert: ";
                cin >> value;
                cout << "Enter the position to insert in: ";
                cin >> position;
                l1.insert_position(value,position);
                break;
            case 4:
                //Delete Beginning
                l1.delete_beginning();
                break;
            case 5:
                //Delete End
                l1.delete_end();
                break;
            case 6:
                //Delete position
                cout << "Enter the position to delete in: ";
                cin >> position;
                l1.delete_pos(position);
                break;
            case 7:
                cout << "Enter the value to find index for: ";
                cin >> value;
                //list.search(value);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                //Display reverse
                l1.display_reverse();
                break;
            case 10:
                //Reverse list
                l1.reverse_list();
                break;
            case 11:
                cout << "Program Exited"<<endl;
                break;
            default:
                cout << "Invalid input try again" << endl;
                
        }
    }while(option < 11);
    return 0;
}