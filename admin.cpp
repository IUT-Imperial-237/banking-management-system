#include "admin.h"

admin::admin()
{
    //ctor
    date_ temp_date;
    temp_date.compute_actual_TIME();

    this->username = "ADMIN";
    this->password = "ADMIN";
    this->created_date = temp_date;
    this->salary = 500000.00;
    this->category = "DEV. ENGINEER";

    this->Setname("AMADOU OLABI");
    this->Setprofession("ENGINEER");

}

admin::admin(const admin& other)
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

admin::admin(const person& p_other)
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
}

admin& admin::operator=(const admin& rhs)
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
