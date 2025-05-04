#include<iostream>
#define SIZE 10
using namespace std;

class Hashtable{
    private:
        int Table[SIZE];
        bool Occupied[SIZE];
        int HashFunction(int key){
            return key % SIZE;
        }
    public:
        Hashtable(){
            for(int i=0;i<SIZE;i++){
                Table[i]=-1;
                Occupied[i]=false;
            }
        }//Constructor.
        void Insert(int key);
        void Delete(int key);
        void Search(int key);
        void Display();
};

int main(){
    Hashtable HT;
    while(true){
    int choice;
    cout << endl;
    cout << "The menu is as follows:- " << endl;
    cout << "1.Insert " << endl;
    cout << "2.Delete " << endl;
    cout << "3.Search " << endl;
    cout << "4.Display " << endl;
    cout << "5.Exit " << endl;
    cout << "Enter your choice:- ";
    cin >> choice;
    cout << endl;
    if(choice==1){
        int key;
        cout << "Enter the key:- ";
        cin >> key;
        cout << endl;
        HT.Insert(key);//Calling insert function with key as a parameter.
    }
    else if(choice==2){
        int key;
        cout << "Enter the key:- ";
        cin >> key;
        cout << endl;
        HT.Delete(key);//Calling delete function with key as a parameter.
    }
    else if(choice==3){
        int key;
        cout << "Enter the key:- ";
        cin >> key;
        cout << endl;
        HT.Search(key);//Calling search function with key as a parameter.
    }
    else if(choice==4){
        HT.Display();//Calling display function.
    }
    else if(choice==5){
        cout << "Exiting...." << endl;//Exiting the menu programme.
        break;
    }
    }
}
//Function definition for insertion.
void Hashtable::Insert(int key){
    int Index=HashFunction(key);
    int OriginalIndex=Index;
    while(Occupied[Index]){
        Index = (Index+1) % SIZE;
        if(Index==OriginalIndex){
            cout << "Hash Table is full!!" << endl;
            return;
        }
    }
    Table[Index]=key;
    Occupied[Index]=true;
    cout << key << " inserted at index " << Index << endl;
}
//Function definition for Deleting.
void Hashtable::Delete(int key){
    int Index=HashFunction(key);
    int OriginalIndex=Index;
    while(Occupied[Index]){
        if (Table[Index]==key){
            cout << Table[Index] << " deleted from index " << Index << endl;
            Table[Index]=-1;
            Occupied[Index]=false;
            return;
        }
        Index = (Index+1) % SIZE;
        if(Index==OriginalIndex){
            break;
        }
    }
    cout << "Key not found!!" << endl;
}
//Function definition for Search.
void Hashtable::Search(int key){
    int Index=HashFunction(key);
    int OriginalIndex=Index;
    while(Occupied[Index]){
        if (Table[Index]==key){
            cout << Table[Index] << " found at index " << Index << endl;
            return;
        }
        Index = (Index+1) % SIZE;
        if(Index==OriginalIndex){
            break;
        }
    }
    cout << "Key not found!!" << endl;
}
//Function definition for Display.
void Hashtable::Display(){
    for (int i=0;i<SIZE;i++){
        if(Occupied[i]==true){
            cout << Table[i] << " is the element at index " << i << endl;
        }
        else{
            cout << "Empty at index " << i << endl;
        }
    }
}