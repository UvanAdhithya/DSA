// Menu to implement listADT 
#include<iostream>
using namespace std ;



class ListADT 
{
    private :
         
        int arr[5] ;
        int size ; 

    public :
       ListADT() ;

        int  insertbeginnig (int) ;
        int  insertpositon (int,int) ;
        int  insertend (int) ;
        int  deletebeginning () ;
        int  deleteposition (int) ;
        int  deleteend () ; 
        int  search (int) ;
        void display (void) ;
        int  rotate (int ) ;
} ;

int main () 
{
    ListADT list ; 
    int choice , val , pos  ;

    do 
    {
        cout << "\n        menu     \n  " ;
        cout << " 1.insert at the beginning \n  " ;
        cout << " 2.insert at the position \n  " ;
        cout << " 3.insert at the end  \n  " ;
        cout << " 4.delete at beginning \n  " ;
        cout << " 5.delete at positon \n  " ;
        cout << " 6.delete at end \n  " ;
        cout << " 7.search in the array \n " ; 
        cout << "  8.display the array \n " ;
        cout << "  9.rotate in the array \n " ;
        cout << "  10.exit \n " ;       
        cout << "  \n  enter your choice :  " ;
        cin >> choice ;
        switch(choice)
        {
              case 1 : 
              cout << "\n  enter value : " ;
              cin >> val ;
              list.insertbeginnig(val) ;
              list.display() ; 
              break ;
              case 2 : 
              cout << "enter value : " ;
              cin  >> val ;
              cout << "enter position : " ;
              cin  >> pos ; 
              list.insertpositon (val,pos);
              list.display() ; 
              break ; 
              case 3 : 
              cout << " enter value : " ;
              cin >> val ;
              list.insertend(val) ;
              list.display() ; 
              break ;
              case 4 :
              list.deletebeginning() ;
              list.display() ;
              break ; 
              case 5 : 
              cout << "enter position : " ;
              cin  >> pos ; 
              list.deleteposition (pos);
              list.display() ;
              break ;
              case 6 : 
              list.deleteend() ;
              list.display() ;
              break ; 
              case 7 : 
              cout << "enter value : " ;
              cin >> val ;
              list.search(val) ;
              break ;
              case 8 :
              list.display() ; 
              break ; 
              case 9 : 
              cout << "enter the value :  " ;
              cin >> val ;
              list.rotate(val) ;
              list.display() ;
              break ;
              case 10 : 
              cout << " \n exiting the program \n " ;
              break ; 

              default : 
              cout << "invalid try , please try again \n" ;
        } 
    }
    while(choice!=10) ;
    return 0 ;
}

ListADT::ListADT () {size = 0 ;}

// 1.function to insert at the beginning 
int ListADT::insertbeginnig(int val) 
{  
   if( size==5 )
   {
    cout << " list if full cannot insert" ;
    return -1 ;
   }
   //loop to shift elements one by one in the array and emptying the first index to insert at the beginning
   for (int i = size ; i > 0 ; i--) 
   {
    arr[i] = arr [i-1] ;
   }

    arr[0] = val ;
    size++ ;
    
    return 1 ;
}
// 2.function to insert at position 
int ListADT :: insertpositon (int val , int pos) 
{  
     if( size==5 )
    {
    cout << " list if full cannot insert" ;
    return -1 ;
    }

     if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position.\n";
        return -1;
    }

    for (int i = size ; i >= pos  ; i--)
    {
        arr[i] = arr[i-1] ;
    }
    arr[pos-1] = val ;
    size ++ ;
    return 1 ;
}
//3.function to insert at the end 
int ListADT :: insertend (int val) 
{
     if( size==5 )
    {
    cout << " list if full cannot insert" ;
    return -1 ;
    }
    arr[size++] = val ;
    return 1 ; 
}

//4.function to display the array

void ListADT :: display ()
{   
    cout << " \n { " ;
    for (int i = 0 ; i < size ; i++ )
    {
        cout << " "<< arr[i] << " "  ;
    }
    cout << " } " ;

}

//5 . function to delete in the beginning 

int ListADT :: deletebeginning()
{
    if (size==0) 
    {
      cout << " list is empty cannot delete" ;
      return -1 ;
    }
    
    for(int i = 0 ; i < size-1 ; i++)
    {
        arr[i] = arr[i+1] ;
    }
    size-- ;
    return 1 ;
}

// function to Delete from Position
int ListADT :: deleteposition(int pos) 
{
    if (size == 0) 
    {
        cout << "List is empty. Cannot delete.\n";
        return -1;
    }
    if (pos < 1 || pos > size) 
    {
        cout << "Invalid position.\n";
        return -1;
    }
    for (int i = pos - 1; i < size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return 1;
}

// function to Delete from End
int ListADT::deleteend() 
{
    if (size == 0) 
    {
        cout << "List is empty. Cannot delete.\n";
        return -1;
    }
    size--;
    return 1;
}

// 7. Search for an Element
int ListADT::search(int value) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << "Element found at position " << i + 1 << endl;
            return 1;
        }
    }
    cout << "Element not found.\n";
    return -1;
}



// 9. Rotate the Array to the Right by k Steps
int ListADT :: rotate(int k) 
{
    if (size == 0) {
        cout << "List is empty. Cannot rotate.\n";
        return -1;
    }
    k %= size; 
    int temp;
    
    for (int i = 0; i < k; i++) {
        temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    return 1 ;
}

