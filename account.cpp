#include "account.h"

account::account()
{
    //ctor
    account_num = "XXX-XXXX-XXX"; //!< Member variable "account_num"
    account_card = "XXX-XXXX"; //!< Member variable "account_card"
    account_pin = "XXXX"; //!< Member variable "account_pin"
    balance = 1000.00; //!< Member variable "balance"
    status = false; //!< Member variable "status"
    t_amount = 0.00; //!< Member variable "t_amount"
}

account::~account()
{
    //dtor
}

account::account(const account& other)
{
    //copy ctor
}

account& account::operator=(const account& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

