
#include<cstdio>
int bubble_sort (int arr[] , int n)
{
  for(int i = 0 ; i<n-1 ; i++) 
  {
     for( int j = 0 ; j<n-i-1 ; j++)
     {
        if( arr[j] > arr[j+1] ) 
        {
          int temp = arr[j] ;
          arr[j]=arr[j+1];
          arr[j+1]= temp ;
        }
        
     }
  }
}
int selection_sort( int arr[],int n )
{
for(int i = 0 ; i < n-1 ; i++) 
{
  int min = i ; 
for(int j = i + 1 ; j < n ; j++) 
{
  if(arr[j] < arr[min]) 
  {
    min = j ;
  }
  
}
if(min != i) 
  {
          int temp = arr[i] ;
          arr[i] = arr[min];
          arr[min] = temp ;
  }
}
}

int insertion_sort (int arr[] , int n )
{
 for(int i = 0 ; i<n ; i++)
{
   int k = arr[i] ;
   int j = i- 1 ;
   
   while(j>=0 && arr[j]>k) 
   {
    arr[j+1] = arr[j] ;
    j-- ;
   }
   arr[j+1] = k ;

}


}

void printArray(int arr[], int size) 
 {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

}

int main () 
{
  int arr[100] ; 
  int n ,choice ;
   
do {
    printf("
    menu    
");
    printf("1.bubble sort
");
    printf("2.selection sort
");
    printf("3.insertion sort
");
    printf("4.exit
");
    printf("enter choice
") ;
    scanf("%d",&choice);

    switch(choice)
    {  
       case 1:
       printf("enter the no of elements in the array : ") ;
       scanf("%d",&n) ;
       printf("enter the elements : ");
       for(int i = 0 ; i<n ; i++) 
       {
       scanf("%d",&arr[i]); 
       }

       printf("original array :");
       printArray(arr,n) ;
       bubble_sort(arr,n);
       printf("
sorted array is : ");
       printArray(arr,n) ;
       break ;


       case 2 :
       printf("enter the no of elements in the array : ") ;
       scanf("%d",&n) ;
       printf("enter the elements : ");
       for(int i = 0 ; i<n ; i++) 
       {
       scanf("%d",&arr[i]); 
       }
    
       printf("original array : ");
       printArray(arr,n) ;
       selection_sort(arr,n) ;
       printf("
sorted array is :  ");
       printArray(arr,n);

       break;
      
       case 3 : 
       printf("enter the no of elements in the array : ") ;
       scanf("%d",&n) ;
       printf("enter the elements : ");
       for(int i = 0 ; i<n ; i++) 
       {
       scanf("%d",&arr[i]); 
       }
    
       printf("original array:  ");
       printArray(arr,n) ;
       insertion_sort(arr,n) ;
       printf("
sorted array is : ");
       printArray(arr,n);

       break ; 

       case 4 :
       printf("exiting the code ");
       break ;
       default : 
       printf("invaild choice  . please try again ");
    }


} 
while (choice!=4) ;
 
 return 0 ;

}
