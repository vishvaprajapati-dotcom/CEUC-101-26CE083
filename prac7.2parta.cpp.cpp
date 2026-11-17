#include<iostream>
using namespace std;
int main()
{
    char para[60],first_word[10],last_word[10];
    int i,l=0,w=0,A=0,D=0,S=0;
    cin.getline(para,60);
    for(i=0;para[i]!='\0';i++)
    {
        l++;
    }
    cout<<"no of characaters:"<<l<<endl;
    for(i=0;para[i]!='\0';i++)
    {
        if(para[i]==' ')
        {
            w++;
        }
        else if(para[i]>='A'||para[i]<='Z')
        {
            A++;
        }
        else if(para[i]>='a'||para[i]<='z')
        {
            A++;
        }
        else if(para[i]>='0'||para[i]<='9')
        {
            D++;
        }
        else if(para[i]>=32&&para[i]<=47||para[i]>=58&&para[i]>=64||para[i]>=91&&para[i]<=96)
        {
            S++;
        }

    }
    cout<<"no of words:"<<w+1<<endl;
    cout<<"no of alphabets:"<<A<<endl;
    cout<<"no of digits:"<<D<<endl;
    cout<<"no of special characters :"<<S<<endl;
}
