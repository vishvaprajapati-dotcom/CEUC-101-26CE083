#include<iostream>
using namespace std;
int main()
{
    char s1[150],s2[30];
    int l=0,i,k;
    /* can be done in three ways.
    1.just print both of them one after anothere.
    2.concatenate in either s1 or s2.
    3.concatenate in another variable.
    since we need to update the paragraph will do in s1.*/
    cout<<"write a paragraph";
    cin.getline(s1,150);
    for(i=0;s1[i]!='\0';i++)
    {
        l++;
    }
    cout<<"add another sentence";
    cin.getline(s2,30);
    for(i=l,k=0;s2[k]!='\0';i++,k++)
    {
        s1[i]=s2[k];
    }
    s1[i]='\0';
    cout<<"-------------------------------------------------"<<endl;
    cout<<s1;

}
