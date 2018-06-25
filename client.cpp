#include "client.h"

client::client()
{
    //ctor

    strcpy(this->pin_code, "0000");

    this->next = NULL;
    this->previous = NULL;
    this->temp_acc = NULL;
}


client::client(client& other)
{
    //copy ctor
    strcpy(this->client_ID, other.Getclient_ID());
    strcpy(this->pin_code, other.Getpin_code());
    this->current_account = other.current_account;
    this->savings_account = other.savings_account;
    this->student_account = other.student_account;

    this->next = NULL;
    this->previous = NULL;
    this->temp_acc = NULL;
}

client::client( person& c_person)
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

    strcpy(this->pin_code, "0000");

    this->next = NULL;
    this->previous = NULL;
    this->temp_acc = NULL;
}

client::client( account& temp_acc)
{
    if(!strcmp(temp_acc.Getaccount_type(),"CUR"))
    {
        this->current_account = temp_acc;
        current_account.Activate_Account();
    }
    else if(!strcmp(temp_acc.Getaccount_type(),"SAV"))
    {
        this->savings_account = temp_acc;
        savings_account.Activate_Account();
    }
    else
    {
        this->student_account = temp_acc;
        student_account.Activate_Account();
    }

    strcpy(this->pin_code, "0000");

    this->next = NULL;
    this->previous = NULL;
    this->temp_acc = NULL;
}

client::client( person& obj_person, account temp_acc)
{
    this->Setname(obj_person.Getname());
    this->SetDOB(obj_person.GetDOB());
    this->Setgender(obj_person.Getgender());
    this->Setcountry(obj_person.Getcountry());
    this->Setprofession(obj_person.Getprofession());
    this->SetparentInfo(obj_person.GetparentInfo());
    this->Setemail(obj_person.Getemail());
    this->Setphone(obj_person.Getphone());
    this->Setaddress(obj_person.Getaddress());

    if(!strcmp(temp_acc.Getaccount_type(),"CUR"))
    {
        this->current_account = temp_acc;
        current_account.Activate_Account();
    }
    else if(!strcmp(temp_acc.Getaccount_type(),"SAV"))
    {
        this->savings_account = temp_acc;
        savings_account.Activate_Account();
    }
    else
    {
        this->student_account = temp_acc;
        student_account.Activate_Account();
    }

    strcpy(this->pin_code, "0000");

    this->next = NULL;
    this->previous = NULL;

    this->temp_acc = NULL;
}


client& client::operator=( client& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    strcpy(this->client_ID, rhs.Getclient_ID());

    this->current_account = rhs.current_account;
    this->savings_account = rhs.savings_account;
    this->student_account = rhs.student_account;

    strcpy(this->pin_code, rhs.Getpin_code());

    this->next = NULL;
    this->previous = NULL;
    this->temp_acc = NULL;

    return *this;
}
client& client::operator=( person& c_person)
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


void client::Setpin_code()
{
    char random[10];
    char random_sequence[]="0000";
    char *f_acc_pin;
    int num,r_len;
    //time_t t;

    ///* Random Number Generator */
    //srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,random,10);
    r_len = strlen(random);
    if(r_len==1)
    {
        random_sequence[3]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==2)
    {
        random_sequence[2]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==3)
    {
        random_sequence[1]='\0';
        strcat(random_sequence,random);
    }
    else strcpy(random_sequence,random);

    f_acc_pin = (char *) malloc(20*sizeof(char));
    strcpy(f_acc_pin,"");
    strcat(f_acc_pin,random_sequence);

    strcpy(this->pin_code,f_acc_pin);
}

void client::Setclient_ID()
{
    char random[10];
    char random_sequence[10]="0000";
    char *f_acc_pin;
    int num,r_len;
    time_t t;

    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,random,10);
    r_len = strlen(random);
    if(r_len==1)
    {
        random_sequence[3]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==2)
    {
        random_sequence[2]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==3)
    {
        random_sequence[1]='\0';
        strcat(random_sequence,random);
    }
    else strcpy(random_sequence,random);

    f_acc_pin = new char[20];
    strcpy(f_acc_pin,random_sequence);

    strcpy(this->client_ID,"CUS-");
    strcat(this->client_ID,f_acc_pin);
}


void client::Reset_PinCode()
{
    process_execution((char*)"RESETTING ACCOUNT PIN");
    this->Setpin_code();
    gotoxy(11,11);
    cout<<"       # PIN-CODE  Successfully  Reset !!!";
    gotoxy(11,13);
    cout<<"\t       [ Press Any Key to Continue ]";
    getch();

}

void client::display_personal_info()
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

void client::add_new_account(account acc_)
{
    switch(acc_.Gettransfer_tag())
    {
    case 2:
        if(this->current_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY EXIST FOR THIS USER !!!"));
            break;
        }
        this->current_account = acc_;
        break;
    case 1:
        if(this->savings_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY EXIST FOR THIS USER !!!"));
            break;
        }
        this->savings_account = acc_;
        break;
    case 0:
        if(this->student_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY EXIST FOR THIS USER !!!"));
            break;
        }
        this->student_account = acc_;
        break;
    }
}
void client::del_new_account(int option)
{
    switch(option)
    {
    case 2:
        if(!this->current_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY DELETED FOR THIS USER !!!"));
            break;
        }
        this->current_account.disable_account(1);
        break;
    case 1:
        if(this->savings_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY DELETED FOR THIS USER !!!"));
            break;
        }
        this->savings_account.disable_account(1);
        break;
    case 0:
        if(this->student_account.Getstatus())
        {
            message(string("\t ACCOUNT ALREADY DELETED FOR THIS USER !!!"));
            break;
        }
        this->student_account.disable_account(1);
        break;
    }
}
