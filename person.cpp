#include "person.h"

person::person()
{
    //ctor
    this -> name = "default Name"; //!< Member variable "name"
    this -> birhtInfos = "default birhtInfos"; //!< Member variable "birthInfos"
    this -> address = "default address"; //!< Member variable "address"
    this -> phone = "default phone"; //!< Member variable "phone"
    this -> country = "default country"; //!< Member variable "country"
    this -> parentInfo = "default parentInfo"; //!< Member variable "parentInfo"
    this -> gender = "default gender"; //!< Member variable "gender"
    this -> email = "default email"; //!< Member variable "email"
    this -> profession = "default profession"; //!< Member variable "profession"

}

person::~person()
{
    //dtor
}

person::person(const person& other)
{
    //copy ctor
    this->name = other.Getname();
    this->birhtInfos = other.GetbirhtInfos();
    this->address = other.Getaddress();
    this->phone = other.Getphone();
    this->country = other.Getcountry();
    this->parentInfo = other.GetparentInfo();
    this->gender = other.Getgender();
    this->email = other.Getemail();
    this->profession = other.Getprofession();
}

person& person::operator=(const person& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    //assignment operator
    else
    {
        this->name = rhs.Getname();
        this->birhtInfos = rhs.GetbirhtInfos();
        this->address = rhs.Getaddress();
        this->phone = rhs.Getphone();
        this->country = rhs.Getcountry();
        this->parentInfo = rhs.GetparentInfo();
        this->gender = rhs.Getgender();
        this->email = rhs.Getemail();
        this->profession = rhs.Getprofession();
        return *this;
    }
}
