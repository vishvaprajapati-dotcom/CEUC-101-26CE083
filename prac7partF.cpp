#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s1[40],s2[40],sub[10];
    cin.ignore();
    cin.getline(s1,40);
    cin.ignore();
    cin.getline(sub,10);
    l=strlen(s1);
    strcpy(s2,s1);
    cout<<s2;
    cout<<s2<<endl;
    cout<<strcmp(s1,s2)<<endl;
    cout<<strcat(s1,s2)<<endl;
    cout<<strstr(s1,sub)<<endl;
}

