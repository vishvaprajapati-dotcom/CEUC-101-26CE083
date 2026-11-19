#include<iostream>
using namespace std;
struct st
{
    int a;
    float b;
    char c;
    double e;
};
struct str
{
    double e;
    float b;
    int a;
    char c;
};
union uni
{
    double b;
    int a;
    char c;
}d;
int main()
{   st s;
    str st;
    /*unoptimized data where there is higher memory loss*/
    cout<<sizeof(s.a)<<endl;
    cout<<sizeof(s.b)<<endl;
    cout<<sizeof(s.c)<<endl;
    cout<<sizeof(s.e)<<endl;
    cout<<sizeof(st)<<endl;
    /*optimized data structure where there is less slag blocks*/
    cout<<sizeof(st.a)<<endl;
    cout<<sizeof(st.b)<<endl;
    cout<<sizeof(st.c)<<endl;
    cout<<sizeof(st.e)<<endl;
    cout<<sizeof(str)<<endl;
    /*unoin is also user defined datatype where the total memory consumption is same as the memory of highest datatype(in here double so 8 bytes).
    pros of union is that space complexity is less.cons is it can hold only one value at a time.when we take input of second variable the value of first data gets overwrite accordingly.
    so we can successfully retrive one value only.*/
    cout<<sizeof(uni)<<endl;
    cin>>d.a;
    cin>>d.b;
    cin>>d.c;
    cout<<d.a<<" "<<d.b<<" "<<d.c<<" ";

}
