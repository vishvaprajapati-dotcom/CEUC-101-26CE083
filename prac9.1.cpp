#include<iostream>
using namespace std;
int main()
{
   int a,b[4]={50,30,20,10};
   int *p;
   int &q=a;
   cout<<"enter a";
   cin>>a;
   p=&a;
   cout<<"variable name:a"<<endl;
   cout<<"stored value:"<<a<<endl;
   cout<<"memory address:"<<p<<endl;
   /*indirect referencing here &q is nothing but a same memory address having two names*/
   cout<<a<<" "<<q<<endl;
   /*here we are accessing the variable using its reference*/
   cout<<q+2<<endl;
   /*here we are changing the value of reference variable and eventually value of actual variable is changed too*/
   q=28;
   cout<<a;
   /*a loop to print array b*/
   for(a=0;a<4;a++)
   {
       cout<<b[a]<<" ";
   }
   cout<<endl;
   /*print array using memory address */
   *p=b[0];
   for(a=0;a<4;a++)
   {
       cout<<*(p+a);
   }


}
