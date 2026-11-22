#include<iostream>
using namespace std;
void print1ton(int);
int printnto1(int);
int rev(int);
int total(int);
int main()
{   int no,m;
    cin>>no;
    printnto1(no);
    print1ton(no);
    rev(no);
    m=total(no);
    cout<<m;

}
/*function to print n to 1*/
int printnto1(int n)
{
    cout<<n<<" ";
    if(n==1)
    {
        return 1;
    }
    return printnto1(n-1);

}
/*function to print 1 to n*/
void print1ton(int n)
{
    if(n==0)
    {
      return;
    }
     print1ton(n-1);
     cout<<n<<" ";
}
/*function to print reverse of given numbers*/
int rev(int n)
{   int j=n%10,total=0;
    cout<<j;
    if(n==0)
    {
        return 0;
    }
    return rev(n/10);

}
/*function to find total of digits in given number*/
int total(int n)
{
  if(n==0)
  {
    return 0;
  }
  return (n%10)+total(n/10);
}
