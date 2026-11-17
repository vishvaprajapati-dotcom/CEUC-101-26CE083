#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char stu_name[30],enroll_no[8],branch[10],ref_id[40],first_name[10],last_name[10];
    int l=0,i,j,k;
    cin.ignore();
    cin.getline(stu_name,30);
    cin.getline(enroll_no,8);
    cin.getline(branch,10);
    for(i=0;stu_name[i]!='\0';i++)
    {
        l++;
        ref_id[i]=stu_name[i];
    }
    ref_id[l]='-';
    for(i=l+1,j=0;enroll_no[j]!='\0';i++,j++)
    {
        ref_id[i]=enroll_no[j];
    }
    /*loop to extract first name*/
    for(i=0;stu_name[i]!=' ';i++)
    {
        first_name[i]=stu_name[i];
    }
    /*2 loops to extract the last name*/
    for(i=0;stu_name[i]!='\0';i++)
    {
      if(stu_name[i]==' ')
      {
          j=i;
      }
    }
    for(i=j+1,k=0;stu_name[i]!='\0';i++,k++)
    {
        last_name[k]=stu_name[i];
    }
    



}



