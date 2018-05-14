#include "person.h"

person::person()
{
    //ctor
    this->name="Enter Name ::  ";
    this->DOB="Enter DOB ::  ";
    this->gender="Enter Gender ::  ";
    this->country="Enter Country ::  ";
    this->profession="Enter Profession ::  ";
    this->parentInfo="Enter Father/Mother's Name ::  ";
    this->email="Enter Email ::  ";
    this->phone="Enter Phone ::  ";
    this->address="Enter Address ::  ";
}

person::person(string _name)
{
    this->name = _name;
}

person::person(const person& other)
{
    //copy ctor
    this->name=other.Getname();
    this->DOB=other.GetDOB();
    this->gender=other.Getgender();
    this->country=other.Getcountry();
    this->profession=other.Getprofession();
    this->parentInfo=other.GetparentInfo();
    this->email=other.Getemail();
    this->phone=other.Getphone();
    this->address=other.Getaddress();
}

person& person::operator=(const person& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->name=rhs.Getname();
    this->DOB=rhs.GetDOB();
    this->gender=rhs.Getgender();
    this->country=rhs.Getcountry();
    this->profession=rhs.Getprofession();
    this->parentInfo=rhs.GetparentInfo();
    this->email=rhs.Getemail();
    this->phone=rhs.Getphone();
    this->address=rhs.Getaddress();
    return *this;
}
