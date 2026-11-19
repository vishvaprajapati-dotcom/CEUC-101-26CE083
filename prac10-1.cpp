#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

struct stu_data
{
    char enroll_no[8],stu_name[30],branch[20],grade[3];
    int sem;
    float percentage;
    struct contacts
    {
        long int mobile_no;
        char email_id;
    }con;
};
int main()
{
     stu_data stu_info;
     cout<<"enter your enroll number";
     cin>>stu_info.enroll_no;
     cout<<"enter your name";
     cin.ignore();
     cin.getline(stu_info.stu_name,30);
     cout<<"enter branch";
     cin.ignore();
     cin.getline(stu_info.branch,20);
     cout<<"enter current semester";

     p:cin>>stu_info.sem;
     if(stu_info.sem<1||stu_info.sem>8)
     {
         cout<<"ïnvalid sem";
         goto p;
     }

     cout<<"enter your percentage";
     q:cin>>stu_info.percentage;
     if(stu_info.percentage>=90)
     {
         strcpy(stu_info.grade,"O");
     }
     else if(stu_info.percentage>=80)
     {
         strcpy(stu_info.grade,"A+");
     }
     else if(stu_info.percentage>=70)
     {
         strcpy(stu_info.grade,"A");
     }
     else if(stu_info.percentage>=60)
     {
         strcpy(stu_info.grade,"B");
     }
     else if(stu_info.percentage>=45)
     {
         strcpy(stu_info.grade,"C");
     }
     else if(stu_info.percentage<45)
     {
         strcpy(stu_info.grade,"F");
     }
     else
     {
         cout<<"invalid percentage"<<endl;
     }
     cout<<"enter your mobile no";
     cin>>stu_info.con.mobile_no;
     cout<<"enter your email id";
     cin>>stu_info.con.email_id;

     cout<<left<<setw(15)<<"enroll id"<<":"<<stu_info.enroll_no<<endl;
     cout<<left<<setw(15)<<"student name"<<":"<<stu_info.stu_name<<endl;
     cout<<left<<setw(15)<<"branch"<<":"<<stu_info.branch<<endl;
     cout<<left<<setw(15)<<"semester"<<":"<<stu_info.sem<<endl;
     cout<<left<<setw(15)<<"percentage"<<":"<<stu_info.percentage<<endl;
     cout<<left<<setw(15)<<"grade"<<":"<<stu_info.grade<<endl;
     cout<<left<<setw(15)<<"mobile no"<<":"<<stu_info.con.mobile_no<<endl;
     cout<<left<<setw(15)<<"email id"<<":"<<stu_info.con.email_id<<endl;
     return 0;
}
