#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   char s1[20],s2[20],s3[40];
   int l=0,space=0,i,j;
   cout<<"write a paragraph"<<endl;
   cin.getline(s1,20);

   for(i=0;s1[i]!='\0';i++)
   {
       l++;
   }
   cout<<"first name:";
   for(i=0;(s1[i]!=' ');i++)
   {
     cout<<s1[i];
   }
   cout<<endl;
   /*no of space*/
   for(i=0;s1[i]!='\0';i++)
   {
       if(s1[i]==' ')
       {
           space=i;
       }
   }
   cout<<"last name:";
   for(j=space+1;s1[j]!='\0';j++)
   {
       cout<<s1[j];
   }
   cout<<endl;
   cout<<"first character:"<<s1[0]<<endl;
   cout<<"last character:"<<s1[l-1]<<endl;



}


