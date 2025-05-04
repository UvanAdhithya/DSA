//Linkd list but more
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class List{
    private:
        struct Node{
            int data;
            struct Node *next;
        }*head;
        //Returns head value of a list
        int gethead(){
            return head->data;
        }

    public:
        List(){
            head = NULL;
        }
        //Number inserted in ascending order
        void insert_ascending(int);
        //Merges two lists into third list in ascending order
        void merge(const List&, const List&);
        //Display list
        void display();
};
void List::insert_ascending(int num) {
    // Create a new node
    struct Node* newnode = new Node();
    newnode->data = num;
    newnode->next = NULL;
    
    // If the list is empty or the new node should be the first node
    if (head == NULL || head->data >= num) {
        newnode->next = head;
        head = newnode;
        return;
    }
    
    // Find the correct position for insertion
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < num) {
        temp = temp->next;
    }
    
    // Insert the node at the correct position
    newnode->next = temp->next;
    temp->next = newnode;
}

void List::display(){
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
void List::merge( const List& list1, const List& list2) {
    Node* temp1 = list1.head;
    Node* temp2 = list2.head;
    
    while (temp1 != NULL) {
        insert_ascending(temp1->data);
        temp1 = temp1->next;
    }
    
    while (temp2 != NULL) {
        insert_ascending(temp2->data);
        temp2 = temp2->next;
    }
}

#endif