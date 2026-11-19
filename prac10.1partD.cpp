#include<iostream>
using namespace std;
void display_stu_info(stu_info.enroll_no);
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
{   stu_data stu_info;
    stu_dat *p;
    *p=stu_data;
    display_stu_info(stu_info.enroll_no);
   /* update_contact_info();
    display_academic_info();*/

}
void display_stu_info(int Enroll_no)
{
    cout<<
}
