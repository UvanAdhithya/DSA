// Main Menu of RR schedule
#include <iostream>

#include "robin.h"

using namespace std;

int main(){
    Process process;
    int option, time;
    do{
        cout << "1.Insert\n2.Execute\n3.Display\n4.Exit" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "Enter the process time:" << endl;
                cin >> time;
                process.insert(time);
                break;
            case 2:
                process.execute();
                break;
            case 3:
                process.display();
                break;
            case 4:
                cout << "Program Exited..." << endl;
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(option < 4);
}