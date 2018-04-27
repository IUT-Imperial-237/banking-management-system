#include "account.h"

account::account()
{
    //ctor
    this -> account_num = "XXX-XXXX-XXX"; //!< Member variable "account_num"
    this -> account_card = "XXX-XXXX"; //!< Member variable "account_card"
    this -> account_pin = "XXXX"; //!< Member variable "account_pin"
    this -> balance = 1000.00; //!< Member variable "balance"
    this -> status = false; //!< Member variable "status"
    this -> t_amount = 0.00; //!< Member variable "t_amount"
}

account::~account()
{
    //dtor
}

account::account(const account& other)
{
    //copy ctor
    this -> account_num = other.Getaccount_num();
    this -> account_card = other.Getaccount_card();
    this -> account_pin = other.Getaccount_pin();
    this -> balance = other.Getbalance();
    this -> status = other.Getstatus();
    this -> t_amount = other.Gett_amount();
}

account& account::operator=(const account& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this -> account_num = rhs.Getaccount_num();
    this -> account_card = rhs.Getaccount_card();
    this -> account_pin = rhs.Getaccount_pin();
    this -> balance = rhs.Getbalance();
    this -> status = rhs.Getstatus();
    this -> t_amount = rhs.Gett_amount();
    return *this;
}

