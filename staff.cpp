#include "staff.h"

staff::staff()
{
    //ctor
    date_ *temp_date;
    temp_date = new date_;
    temp_date->compute_actual_TIME();

    this->username = "STAFF";
    this->password = "STAFF";
    this->created_date = *temp_date;
    this->salary = 500000.00;
    this->category = "TELLER MANAGER";

    this->Setname("ABDEL KARIM");
    this->Setprofession("ACCOUNTER");
    delete temp_date;
}

staff::staff(const staff& other)
{
    //copy ctor
    this->username = other.Getusername();
    this->password = other.Getpassword();
    this->created_date = other.Getcreated_date();
    this->salary = other.Getsalary();
    this->category = other.Getcategory();
    this->Setname(other.Getname());
    this->SetDOB(other.GetDOB());
    this->Setgender(other.Getgender());
    this->Setcountry(other.Getcountry());
    this->Setprofession(other.Getprofession());
    this->SetparentInfo(other.GetparentInfo());
    this->Setemail(other.Getemail());
    this->Setphone(other.Getphone());
    this->Setaddress(other.Getaddress());

}

staff& staff::operator=(const staff& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->username = rhs.Getusername();
    this->password = rhs.Getpassword();
    this->created_date = rhs.Getcreated_date();
    this->salary = rhs.Getsalary();
    this->category = rhs.Getcategory();
    this->Setname(rhs.Getname());
    this->SetDOB(rhs.GetDOB());
    this->Setgender(rhs.Getgender());
    this->Setcountry(rhs.Getcountry());
    this->Setprofession(rhs.Getprofession());
    this->SetparentInfo(rhs.GetparentInfo());
    this->Setemail(rhs.Getemail());
    this->Setphone(rhs.Getphone());
    this->Setaddress(rhs.Getaddress());
    return *this;
}
