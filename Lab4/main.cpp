//Main menu of 3 linked list
#include "ll.h"
#include <iostream>

int main(){
    List l1,l2,l3;
    int option,value;
    do{
        cout << "Choose an option:\n1.Insert into List1\n2.Insert into List2\n3.Merge lists into List3\n4.Display Lists\n5.Exit" << endl;
        cin >> option;
        switch(option){
            case 1:
                //Insert asc
                cout << "Enter value to insert into List1:" << endl;
                cin >> value;
                l1.insert_ascending(value);
                break;
            case 2:
                //Merge lists
                //Insert asc
                cout << "Enter value to insert into List2:" << endl;
                cin >> value;
                l2.insert_ascending(value);
                break;
            case 3:
                //Merge lists
                l3.merge(l1,l2);
                cout << "Lists merged into List3.\n";
                cout << endl;
                break;
            case 4:
                //Display
                cout << "List1: ";
                l1.display();
                cout << "List2: ";
                l2.display();
                cout << "List3 (Merged): ";
                l3.display();
                break;
            case 5:
                cout << "Program Exited." << endl;
                break;
            default:
                cout << "Invalid" << endl;
        }
    }while(option < 5);    
}