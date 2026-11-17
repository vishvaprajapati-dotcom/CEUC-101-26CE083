#include<iostream>
using namespace std;
int main()
{
    char para[20],rpara[20];
    int i,l=0,j,same=0,p=0;
    cin.getline(para,20);
   /* cin.ignore();
    cin.getline(para,20);*/
    for(i=0;para[i]!='\0';i++)
    {
        l++;
    }
    for(i=0;para[i]!='\0';i++)
    {
        if(para[i]>=97&&para[i]<=122)
        {
            para[i]=char(para[i]-32);
        }
    }
    cout<<para<<endl;
    cout<<"------------------------------------------------------"<<endl;
    for(i=0;para[i]!='\0';i++)
    {
        if(para[i]>=65&&para[i]<=90)
        {
            para[i]=char(para[i]+32);
        }
    }
    cout<<para<<endl;
    cout<<"------------------------------------------------------"<<endl;
    for(i=l-1;i>=0;i--)
    {
        rpara[j]=para[i];
        j++;
    }
    rpara[l]='\0';
    cout<<rpara<<endl;
    cout<<"----------------------------------------------------"<<endl;
    /*when we print the reverse of the paragraph now we no longer need that paragraph so instead of making another variable for word i used the same variable*/
    cin.getline(para,20);
    l=0;
    for(i=0;para[i]!='\0';i++)
    {
       l++;
    }
    for(i=l-1,j=0;i>=0;i--,j++)
    {
        rpara[j]=para[i];
    }
    /*if word is pelindrome then at every index of para and rpara would be same so tonly if the word is not pelindrome p=1 */
    for(i=0;i<l;i++)
    {
      if(rpara[i]!=para[i])
      {
          p=1;
      }
    }
    if(p==0)
    {
        cout<<"the word is palindrome";
    }
    else
    {
        cout<<"the word is not palindrome";
    }







}
