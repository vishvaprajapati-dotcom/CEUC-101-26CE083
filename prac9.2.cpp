#include<iostream>
using namespace std;
void display_stu_rec(int n,char *ENROLL_ID[8],char *NAME[30],char BRANCH[10],int *SEM,float *PER,char *GRADE)
{  int i;
   for(i=0;i<n;i++)
   {
      cout<<"enrollment id"<<":"<<*(ENROLL_ID+i)<<endl;
      cout<<"enrollment name"<<":"<<*(NAME+i)<<endl;
      cout<<"branch"<<":"<<*(BRANCH+i)<<endl;
      cout<<"semester"<<":"<<*(SEM+i)<<endl;
      cout<<"percentage"<<":"<<*(PER+i)<<endl;
      cout<<"garde"<<":"<<*(GRADE+i)<<endl;
    }
}
float avg_per(int n,float *PER)
{
    int i;
    float total,avg_per,max_per=0,min_per=100;
    for(i=0;i<n;i++)
    {
        total=total+*(PER+i);
        if(*(PER+i)>max_per)
        {
            max_per=*(PER+i);
        }
        if(*(PER+i)<min_per)
        {
            min_per=*(PER+i);
        }
    }
    avg_per=total/n;
    cout<<"highest percentage is"<<max_per<<endl;
    cout<<"lowest percentage is"<<min_per<<endl;
    return avg_per;
}
int main()
{
    int no_of_stu,i;
    cout<<"enter number of student";
    cin>>no_of_stu;
    char (*enroll_id)[8]=new char[no_of_stu][8];
    char (*name)[30]=new char[no_of_stu][30];
    char (*branch)[10]=new char[no_of_stu][10];
    int (*sem)=new int[no_of_stu];
    float (*per)=new float[no_of_stu];
    char (*grade)[3]=new char[no_of_stu][3];
    for(i=0;i<no_of_stu;i++)
    {
        cin.getline(*(enroll_id+i),8);
        cin.getline(*(name+i),30);
        cin.getline(*(branch+i),10);
        cin>>(*(sem));
        cin>>(*(per));
        cin.getline(*(grade+i),3);
        display_stu_rec(no_of_stu,enroll_id,name,branch,sem,per,grade);
        cout<<"average percentage:"<<avg_per(no_of_stu,per)<<endl;

    }

    delete[] enroll_id;
    delete[] name;
    delete[] branch;
    delete[] sem;
    delete[] per;
    delete[] grade;
    enroll_id=nullptr;
    name=nullptr;
    branch=nullptr;
    sem=nullptr;
    per=nullptr;
    grade=nullptr;
}
