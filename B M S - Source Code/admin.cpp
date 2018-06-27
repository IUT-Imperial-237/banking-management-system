#include "admin.h"

admin::admin()
{
    //ctor
    this->Setcreated_date();

    strcpy(this->username, ADMIN);
    strcpy(this->password, ADMIN);
    strcpy(this->category, ADMIN);

    this->Setname((char*)"AMADOU OLABI");
    this->Setprofession((char*)"ENGINEER");

    this->next = NULL;
    this->previous = NULL;
}

admin::admin( admin& other)
{
    //copy ctor
    strcpy(this->username,other.Getusername());
    strcpy(this->password, other.Getpassword());
    strcpy(this->created_date, other.Getcreated_date());
    this->salary = other.Getsalary();
    strcpy(this->category, other.Getcategory());

    strcpy(this->functionality,other.Getfunctionality());
    strcpy(this->user_ID,other.Getuser_ID());

    this->Setname(other.Getname());
    this->SetDOB(other.GetDOB());
    this->Setgender(other.Getgender());
    this->Setcountry(other.Getcountry());
    this->Setprofession(other.Getprofession());
    this->SetparentInfo(other.GetparentInfo());
    this->Setemail(other.Getemail());
    this->Setphone(other.Getphone());
    this->Setaddress(other.Getaddress());

    this->next = NULL;
    this->previous = NULL;
}

admin::admin( person& p_other)
{
    //copy ctor
    this->Setname(p_other.Getname());
    this->SetDOB(p_other.GetDOB());
    this->Setgender(p_other.Getgender());
    this->Setcountry(p_other.Getcountry());
    this->Setprofession(p_other.Getprofession());
    this->SetparentInfo(p_other.GetparentInfo());
    this->Setemail(p_other.Getemail());
    this->Setphone(p_other.Getphone());
    this->Setaddress(p_other.Getaddress());

    this->next = NULL;
    this->previous = NULL;
}

void admin::automate_salary_scale()
{
    message(string("under construction"));

    if(!strcmp(Getcategory(),ADMIN))
    {
        Setsalary(500000.00); //!-- For experimental purpose;
    }
    else
    {
        Setsalary(250000.00); //!-- For experimental purpose;
    }
}

void admin::display_personal_info()
{
    system("cls");
    rectangle(10,5,60,16);
    gotoxy(10,6);
    cout<<"\t     ::: Personal Informations :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,8);
    cout<<"  Name   :: "<<this->Getname();
    gotoxy(11,9);
    cout<<" Born on :: "<<this->GetDOB()<<" in "<<this->Getcountry();
    gotoxy(11,10);
    cout<<"   Sex   :: "<<this->Getgender();
    gotoxy(11,11);
    cout<<" Parent  :: "<<this->GetparentInfo();
    gotoxy(11,12);
    cout<<"Profession :: "<<this->Getprofession();
    gotoxy(11,13);
    cout<<" Address :: "<<this->Getaddress();
    gotoxy(11,14);
    cout<<"  Email  :: "<<this->Getemail();
    gotoxy(11,15);
    cout<<"  Phone  :: "<<this->Getphone();
    gotoxy(10,18);
    cout<<"\t    [ Press Any Key to Continue ]  ";
    getch();
}
void admin::generate_user_ID()
{
    char *f_user_ID;
    char rand_num[10]="";
    char rand_seq[10]="000";
    time_t t;
    int num,r_len;

    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,rand_num,18);
    r_len = strlen(rand_num);

    if(r_len==1)
    {
        strcat(rand_seq,rand_num);
    }
    else if(r_len==2)
    {
        rand_seq[2]='\0';
        strcat(rand_seq,rand_num);
    }
    else if(r_len==3)
    {
        rand_seq[1]='\0';
        strcat(rand_seq,rand_num);
    }
    else
        strcpy(rand_seq,rand_num);

    f_user_ID = new char[20];

    if(!strcmp(this->Getcategory(),ADMIN))
        strcpy(f_user_ID,"ADMIN-");
    else if(!strcmp(this->Getcategory(),STAFF))
        strcpy(f_user_ID,"STAFF-");

    strupr(rand_seq);
    strcat(f_user_ID,rand_seq);

    this->Setuser_ID(f_user_ID);
}
void admin::display_user_credentials()
{
    int see=0;
DISPLAY_:
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     ::: USER CREDENTIALS :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t  [   USER_ID  ] --> "<<this->Getuser_ID();
    gotoxy(10,11);
    cout<<"\t  [  USERNAME  ] --> "<<this->Getusername();
    gotoxy(10,13);
    if(see)
        cout<<"\t  [  PASSWORD  ] --> "<<this->Getpassword();
    else
        cout<<"\t  [  PASSWORD  ] --> "<<"*******";
    gotoxy(10,15);
    cout<<"\t  [  CATEGORY  ] --> "<<((!strcmp(this->Getcategory(),ADMIN))? "ADMIN" : "STAFF");
    gotoxy(10,17);
    cout<<"\t  [  FUNCTION  ] --> "<<this->Getfunctionality();
    gotoxy(10,19);
    if(see)
    {
        cout<<"\t    [ Press Any Key to Continue ]  ";
        getch();
        return;
    }
    else
        cout<<"[ Press 'S' to View Password or Esc to Continue ]  ";
    see = getch();
    if(see==27)
        return;
    else if(see=='s'||see=='S')
        goto DISPLAY_;
}


admin& admin::operator=( admin& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    strcpy(this->username,rhs.Getusername());
    strcpy(this->password, rhs.Getpassword());
    strcpy(this->created_date, rhs.Getcreated_date());
    this->salary = rhs.Getsalary();
    strcpy(this->category, rhs.Getcategory());

    strcpy(this->functionality,rhs.Getfunctionality());
    strcpy(this->user_ID,rhs.Getuser_ID());



    this->Setname(rhs.Getname());
    this->SetDOB(rhs.GetDOB());
    this->Setgender(rhs.Getgender());
    this->Setcountry(rhs.Getcountry());
    this->Setprofession(rhs.Getprofession());
    this->SetparentInfo(rhs.GetparentInfo());
    this->Setemail(rhs.Getemail());
    this->Setphone(rhs.Getphone());
    this->Setaddress(rhs.Getaddress());

    this->next = NULL;
    this->previous = NULL;

    return *this;
}
admin& admin::operator=( person& c_person)
{
    this->Setname(c_person.Getname());
    this->SetDOB(c_person.GetDOB());
    this->Setgender(c_person.Getgender());
    this->Setcountry(c_person.Getcountry());
    this->Setprofession(c_person.Getprofession());
    this->SetparentInfo(c_person.GetparentInfo());
    this->Setemail(c_person.Getemail());
    this->Setphone(c_person.Getphone());
    this->Setaddress(c_person.Getaddress());

    return *this;
}


void admin::reset_password()
{

    char rand_num[10]="";
    char rand_seq[10]="000";
    time_t t;
    int num,r_len;

    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,rand_num,rand()%35);
    r_len = strlen(rand_num);

    if(r_len==1)
    {
        strcat(rand_seq,rand_num);
    }
    else if(r_len==2)
    {
        rand_seq[2]='\0';
        strcat(rand_seq,rand_num);
    }
    else if(r_len==3)
    {
        rand_seq[1]='\0';
        strcat(rand_seq,rand_num);
    }
    else
        strcpy(rand_seq,rand_num);

    strupr(rand_seq);

    this->Setpassword(rand_seq);
}
