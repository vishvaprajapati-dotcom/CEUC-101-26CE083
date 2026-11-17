#include<iostream>
using namespace std;
int main()
{
    char str[50],word[20];
    short int i,j=0,found=0,z=0;
    cin.getline(str,50);
    cin.getline(word,20);
    for(i=0;str[i]!='\0';i++)
    {
        while(word[j]!='\0'&&str[i]==word[j])
        {
            j++;
            found++;
            if(found==1)
            {
                z=i;
            }

        }
    }
    if(found==0)
    {
        cout<<"keyword not found"<<endl;
    }
    else
    {
        cout<<"keyword found"<<endl;
    }
    cout<<z+1;

}
