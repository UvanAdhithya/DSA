#include<cstdio>
#include<cstdlib>
#include<cmath>
int palindrome (int* num)
{
  int* original=(int*)malloc(sizeof(int));
  int* reversed=(int*)malloc(sizeof(int));
  int* temp=(int*)malloc(sizeof(int));
  *original=*num ;
  *reversed= 0 ;
  *temp= *num ;
   
   while(*temp > 0 )
   {
      *reversed = *reversed * 10 + ( *temp % 10) ;
      *temp = *temp/10 ;
   }
    free(original);
    free(reversed);
    free(temp);
   if(*original==*reversed)
   {
   return 1 ;
   }
   else
   {
    return 0 ;
   } 
}
int armstrongnumber(int* num)
{
 int* original = (int*)malloc(sizeof(int));
 int* sum = (int*)malloc(sizeof(int));
 int* temp = (int*)malloc(sizeof(int));
 int* digits = (int*)malloc(sizeof(int));
 *original = *num ;
 *sum = 0 ;
 *temp = *num ;
 *digits = 0 ;
 while (*temp>0)
 {
    *digits= *digits + 1  ;
    *temp = *temp / 10 ;
 }
  
 *temp = *num ;

 while(*temp>0)
 {  
    *sum = *sum + pow(*temp  % 10 ,*digits);
    *temp = *temp /10 ;
 } 
 free(original);
 free(sum);
 free(temp);
 free(digits);
 if (*original==*sum)
 {
    return 1 ;
 }
 else 
 { 
    return 0 ;  
 }

}
int perfectnumber(int* num)
{
 int* original = (int*)malloc(sizeof(int));
 int* sum = (int*)malloc(sizeof(int));
 int* i =(int*)malloc(sizeof(int));
 *original = *num ;
 *sum  = 0 ; 
 for(*i=1; *i <= *original / 2 ;(*i)++)
 {
 if(*original % *i == 0 )
 {
  *sum = *sum + *i ;  
 }
 }
 free(original);
 free(i);
 free(sum);
 if(*original==*sum)
 {
    return 1 ;
 }
 else
 {
    return 0 ;
 }
}
int main () 
{
   int* num =(int*)malloc(sizeof(int));
   int* choice =(int*)malloc(sizeof(int));


do
{
printf("\n    menu    \n");
printf("1. palindrome\n");
printf("2. armstrong number\n");
printf("3. perfect number\n");
printf("4. exit \n");
printf("enter your choice : ");
scanf("%d",choice);    
if(*choice== 1 || *choice== 2 || *choice== 3)
{
    printf(" enter the number : ");
    scanf("%d",num);


switch(*choice)
{
 case 1 :
 if(palindrome(num)==1)
 {
    printf("%d is a palindrome.\n",*num);
 }
 else
 {
    printf("%d is not a palindrome.\n",*num);
 }
 break;
 case 2 :
 if(armstrongnumber(num)==1)
 {
    printf("%d is an armstrong number.\n",*num);
 }
//  else if (*num==153)
//  {
//     printf("153 is an armstrong number ");
//  }
 else
 {
    printf("%d is not an armstrong number.\n",*num);
 }
 break;
 case 3 :
 if(perfectnumber(num)==1)
 {
    printf("%d is a perfect number .\n",*num);
 }
 else
 {
    printf("%d is not a perfect number.\n",*num);
 }
 break;
}
}
else if(*choice!=4)
{
 printf("invalid choice , please choose from the menu \n");
}
}
while(*choice!=4);
printf("exiting program\n");
free(num);
free(choice);
}