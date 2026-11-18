#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
void display_header();
void accept_student_details(char[],char[],char[],int &,int[]);
void calculateresult(int[],int &,float &,char[],char[]);
void displaystudentrecord(char[],char[],char[],int &,int &,float &,char[],char[]);
cout<<"a";
int main()
{   char enroll_no[8],stu_name[30],branch[10],grade[3],result[5];
    int sem,marks[3],total_marks;
    float percentage;
    display_header();
    accept_student_details(enroll_no,stu_name,branch,sem,marks);
    calculateresult(marks,total_marks,percentage,grade,result);
    displaystudentrecord(enroll_no,stu_name,branch,sem,total_marks,percentage,grade,result);
}
/*function to display header*/
void display_header()
{
    cout<<"-------------------------------------------"<<endl;
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM"<<endl;
    cout<<"-------------------------------------------"<<endl;

}
/*function to take input */
void accept_student_details(char ENROLL_NO[],char STU_NAME[],char BRANCH[],int &SEM,int MARKS[])
{ int i;
    cout<<"student registration"<<endl;
    cout<<"enter your enrollment id: ";
    cin.getline(ENROLL_NO,8);
    cout<<"enter your name: ";
    cin.getline(STU_NAME,40);
    cout<<"enter your branch: ";
    cin.getline(BRANCH,10);
    p:cout<<"enter your semester: ";
    cin>>SEM;
    if(SEM<1||SEM>10)
    {
        cout<<"invalid value of semester"<<endl;
        goto p;
    }
    for(i=0;i<3;i++)
    {  q:cout<<"enter your marks of subject"<<i+1<<": ";
        cin>>MARKS[i];
        if(MARKS[i]<0||MARKS[i]>100)
        {
            cout<<"invalid marks"<<endl;
            goto q;
        }
    }
}
void calculateresult(int MARKS[],int &TOTAL_MARKS,float &PERCENTAGE,char GRADE[],char RESULT[])
{ int i=0;
    TOTAL_MARKS=MARKS[0]+MARKS[1]+MARKS[2];
    PERCENTAGE=TOTAL_MARKS/3.0;
    if(PERCENTAGE>=90)
    {
        strcpy(GRADE,"o");
    }
    else if(PERCENTAGE>=80)
    {
        strcpy(GRADE,"A+");
    }
    else if(PERCENTAGE>=70)
    {
        strcpy(GRADE,"A");
    }
    else if(PERCENTAGE>=60)
    {
        strcpy(GRADE,"B+");
    }
    else if(PERCENTAGE>=50)
    {
        strcpy(GRADE,"B");
    }
    else if(PERCENTAGE>=40)
    {
        strcpy(GRADE,"C");

    }
    else
    {
        strcpy(GRADE,"F");
        i=1;
    }
    if(i==1)
    {
        strcpy(RESULT,"fail");
    }
    else
    {
       strcpy(RESULT,"pass");
    }

}
void displaystudentrecord(char ENROLL_NO[],char STU_NAME[],char BRANCH[],int &SEM,int &TOTAL_MARKS,float &PERCENTAGE,char GRADE[],char RESULT[])
{
    cout<<left<<setw(25)<<"Enrollment id"<<":"<<ENROLL_NO<<endl;
    cout<<left<<setw(25)<<"Student name"<<":"<<STU_NAME<<endl;
    cout<<left<<setw(25)<<"Branch"<<":"<<BRANCH<<endl;
    cout<<left<<setw(25)<<"Sem"<<":"<<SEM<<endl;
    cout<<left<<setw(25)<<"Total marks"<<":"<<TOTAL_MARKS<<endl;
    cout<<left<<setw(25)<<"Percentage"<<":"<<PERCENTAGE<<endl;
    cout<<left<<setw(25)<<"Grade"<<":"<<GRADE<<endl;
    cout<<left<<setw(25)<<"Result"<<":"<<RESULT<<endl;

}


