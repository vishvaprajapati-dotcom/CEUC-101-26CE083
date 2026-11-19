#include<iostream>
using namespace std;
void factorialloop(int);
int factorialrecursion(int);
void fibonacciloop(int);
int fibonaccirec(int);

int main()
{
    int no,fact,m;
    cout<<"no";
    cin>>no;
    factorialloop(no);
    fact=factorialrecursion(no);
    cout<<fact<<endl;
    fibonacciloop(no);
    m=fibonaccirec(no);
    cout<<"The "<<no<<"th term in fibonacci series is"<<m;

    return 0;
}
/*this function factorialloop finds the factorial using loops*/
void factorialloop(int n)
{   int i,fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout<<fact<<endl;
}
/*this function factorialrecursion finds the factorial using recursion.*/
/*recursion is a function calling itself.there are two cases genrel case and base case where base case is the solution to stop the recursion*/

int factorialrecursion(int n)
{   /*base case*/
    if(n==1)
    {
        return 1;
    }
    /*general case*/
    return n*factorialrecursion(n-1);
}
/* finding fibonacci series using loop and recursion*/
void fibonacciloop(int n)
{   int i,t1=0,t2=1,sum;
    cout<<t1<<","<<t2<<",";
    for(i=1;i<=n;i++)
    {
        sum=t1+t2;
        cout<<sum<<",";
        t1=t2;
        t2=sum;
    }
}
/*fibonacci using recursion*/
int fibonaccirec(int n)

{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }

    return fibonaccirec(n-1)+fibonaccirec(n-2);

}

