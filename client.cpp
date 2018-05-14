#include "client.h"

client::client()
{
    //ctor
    this->pin_code = 0000;
    this->next = NULL;
    this->previous =NULL;
}

client::client(const client& other)
{
    //copy ctor
    this->client_ID = other.Getclient_ID();
    this->pin_code = other.Getpin_code();
    this->current_account = other.Getcurrent_account();
    this->savings_account = other.Getsavings_account();
    this->student_account = other.Getstudent_account();
    /*
    this->next = other.Getnext();
    this->next = other.Getprevious();
    */
    this->pin_code = 0000;
    this->next = NULL;
    this->previous =NULL;
}

client::client(const person& c_person)
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
    this->pin_code = 0000;
    this->next = NULL;
    this->previous =NULL;
}

client::client(account* cur, account* sav, account* stu)
{
    this->current_account = cur;
    this->savings_account = sav;
    this->student_account = stu;
    this->pin_code = 0000;
    this->next = NULL;
    this->previous =NULL;
}

client::client(const person& obj_person, account* cur, account* sav, account* stu)
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
    this->current_account = cur;
    this->savings_account = sav;
    this->student_account = stu;
    this->pin_code = 0000;
    this->next = NULL;
    this->previous =NULL;
}


client& client::operator=(const client& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->client_ID = rhs.Getclient_ID();
    this->pin_code = rhs.Getpin_code();
    this->current_account = rhs.Getcurrent_account();
    this->savings_account = rhs.Getsavings_account();
    this->student_account = rhs.Getstudent_account();
    /*
    this->next = rhs.Getnext();
    this->next = rhs.Getprevious();
    */
    /*
    this->next = NULL;
    this->next = NULL;
    */
    return *this;
}
