#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct stu_data
{
    float percentage[10];
    int sem[10];
    char enroll_no[10][8],stu_name[10][30],branch[10][20],grade[10][3];

    struct contacts
    {
        long int mobile_no[10];
        char email_id[10][20];
    }con;
};
int main()
{   int i,no_of_stu;
    stu_data stu_info;
    cin>>no_of_stu;
     for(i=0;i<no_of_stu;i++)
     {
         cout<<"enter your enroll number";
         cin>>stu_info.enroll_no[i];
         cout<<"enter your name";
         cin.ignore();
         cin.getline(stu_info.stu_name[i],30);
         cout<<"enter branch";
         cin.ignore();
         cin.getline(stu_info.branch[i],20);
         cout<<"enter current semester";

         p:cin>>stu_info.sem[i];
         if(stu_info.sem[i]<1||stu_info.sem[i]>8)
         {
            cout<<"ïnvalid sem";
            goto p;
         }
         cout<<"enter your percentage";
         q:cin>>stu_info.percentage[i];
         if(stu_info.percentage[i]>=90)
         {
             strcpy(stu_info.grade[i],"O");
         }
         else if(stu_info.percentage[i]>=80)
         {
             strcpy(stu_info.grade[i],"A+");
         }
         else if(stu_info.percentage[i]>=70)
         {
             strcpy(stu_info.grade[i],"A");
         }
         else if(stu_info.percentage[i]>=60)
         {
             strcpy(stu_info.grade[i],"B");
         }
         else if(stu_info.percentage[i]>=45)
         {
             strcpy(stu_info.grade[i],"C");
         }
         else if(stu_info.percentage[i]<45)
         {
             strcpy(stu_info.grade[i],"F");
         }
         else
         {
             cout<<"invalid percentage"<<endl;
         }
         cout<<"enter your mobile no";
         cin>>stu_info.con.mobile_no[i];
         cout<<"enter your email id";
         cin>>stu_info.con.email_id[i];


  }
     for(i=0;i<no_of_stu;i++)
    {

         cout<<left<<setw(15)<<"enroll id"<<":"<<stu_info.enroll_no[i]<<endl;
         cout<<left<<setw(15)<<"student name"<<":"<<stu_info.stu_name[i]<<endl;
         cout<<left<<setw(15)<<"branch"<<":"<<stu_info.branch[i]<<endl;
         cout<<left<<setw(15)<<"semester"<<":"<<stu_info.sem[i]<<endl;
         cout<<left<<setw(15)<<"percentage"<<":"<<stu_info.percentage[i]<<endl;
         cout<<left<<setw(15)<<"grade"<<":"<<stu_info.grade[i]<<endl;
         cout<<left<<setw(15)<<"mobile no"<<":"<<stu_info.con.mobile_no[i]<<endl;
         cout<<left<<setw(15)<<"email id"<<":"<<stu_info.con.email_id[i]<<endl;
    }
     return 0;
}
