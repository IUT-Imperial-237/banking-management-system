#include "person.h"

person::person()
{
    //ctor
    name = "default Name"; //!< Member variable "name"
    birhtInfos = "default birhtInfos"; //!< Member variable "birthInfos"
    address = "default address"; //!< Member variable "address"
    phone = "default phone"; //!< Member variable "phone"
    country = "default country"; //!< Member variable "country"
    parentInfo = "default parentInfo"; //!< Member variable "parentInfo"
    gender = "default gender"; //!< Member variable "gender"
    email = "default email"; //!< Member variable "email"
    profession = "default profession"; //!< Member variable "profession"

}

person::~person()
{
    //dtor
}

person::person(const person& other)
{
    //copy ctor

}

person& person::operator=(const person& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
