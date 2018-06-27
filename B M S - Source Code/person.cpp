#include "person.h"

person::person()
{
    //ctor
    strcpy(this->name,"Enter Name ::  ");
    strcpy(this->DOB,"Enter DOB ::  ");
    strcpy(this->gender,"Enter Gender ::  ");
    strcpy(this->country,"Enter Country ::  ");
    strcpy(this->profession,"Enter Profession ::  ");
    strcpy(this->parentInfo,"Enter Father/Mother's Name ::  ");
    strcpy(this->email,"Enter Email ::  ");
    strcpy(this->phone,"Enter Phone ::  ");
    strcpy(this->address,"Enter Address ::  ");


}

person::person(string _name,
               string _DOB,
               string _phone,
               string _country,
               string _parentInfo,
               string _gender,
               string _email,
               string _address,
               string _profession)
{
    strcpy(this->name,_name.c_str());
    strcpy(this->DOB,_DOB.c_str());
    strcpy(this->phone,_phone.c_str());
    strcpy(this->country,_country.c_str());
    strcpy(this->parentInfo,_parentInfo.c_str());
    strcpy(this->gender,_gender.c_str());
    strcpy(this->email,_email.c_str());
    strcpy(this->address,_address.c_str());
    strcpy(this->profession,_profession.c_str());
}

person::person(person& other)
{
    //copy ctor
    strcpy(this->name,other.Getname());
    strcpy(this->DOB,other.GetDOB());
    strcpy(this->gender,other.Getgender());
    strcpy(this->country,other.Getcountry());
    strcpy(this->profession,other.Getprofession());
    strcpy(this->parentInfo,other.GetparentInfo());
    strcpy(this->email,other.Getemail());
    strcpy(this->phone,other.Getphone());
    strcpy(this->address,other.Getaddress());
}

person& person::operator=( person& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    strcpy(this->name,rhs.Getname());
    strcpy(this->DOB,rhs.GetDOB());
    strcpy(this->gender,rhs.Getgender());
    strcpy(this->country,rhs.Getcountry());
    strcpy(this->profession,rhs.Getprofession());
    strcpy(this->parentInfo,rhs.GetparentInfo());
    strcpy(this->email,rhs.Getemail());
    strcpy(this->phone,rhs.Getphone());
    strcpy(this->address,rhs.Getaddress());
    return *this;
}

