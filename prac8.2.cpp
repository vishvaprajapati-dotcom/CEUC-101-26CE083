
#include<iostream>
using namespace std;
void f1(int &);
void f1();
void f3(int,int);
int f2();
int f4(int,int);
int main()
{   int c,a,b;
    f1();
    c=f2();
    cout<<c<<endl;
    cin>>c>>a;
    f3(c,a);
    b=f4(c,a);
    cout<<b;
    f1(a);
    cout<<a;
}
/*f1 is without argument and without return value.here we are not passing anything as parameter into thr function and not returning anything to main.here c will get printed and everything will get destroyed as soon as the function f1 is over*/
void f1()
{
   int a,b,c;
   cin>>a>>b;
   c=a+b;
   cout<<c<<endl;
}
/*f2 is function with return value and without parameters*/
int f2()
{
    int a,b,c;
    cin>>a>>b;
    c=a+b;
    return c;
}
/*f3 is function with parameters and without return value*/
void f3(int x,int y)
{
    int z;
    z=x+y;
    cout<<z<<endl;
}
/*f4 is function with arguments and with a return value*/
int f4(int x,int y)
{
    int z;
    z=x+y;
    return z;
}
/*in every function the same thing addition of two numbers is done*/\
void(int &S)
{
    S=10;
}





