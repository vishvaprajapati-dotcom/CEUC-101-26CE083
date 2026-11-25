#include<iostream>
using namespace std;
void fun()
{
    int x=70;
    cout<<"value of x"<<x<<endl;
    cout<<"adress of x is"<<&x<<endl;
    int *p=new int;
    cin>>*p;
    cout<<"value assinged to p is"<<*p<<endl;
    cout<<"adress of p"<<p<<endl;
    delete p;
    p=nullptr;
}
int main()
{
    int *p1;
    int **p2;
    int ***p3;
    int x=70;
    p1=&x;
    p2=&p1;
    p3=&p2;
    fun();
    cout<<"value of x in main is "<<x<<endl;
    cout<<"value of x using single pointer"<<*p1<<endl;
    cout<<"value of x using double pointer"<<**p2<<endl;
    cout<<"value of x using triple pointer"<<***p3<<endl;

}
