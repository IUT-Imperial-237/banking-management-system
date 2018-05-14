#include "account.h"

account::account()
{
    //ctor
    this->account_number = "XXX-XXXX-XXX";
    this->account_card = "XXX-XXXX";
    this->account_type = "CUR/SAV/STU";
    ///* opening_date will be auto-set while creating the account;
    this->status = false;
    this->balance = 0.00;
    this->transaction_id = "";
}

account& account::operator=(const account& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->account_number = rhs.Getaccount_number();
    this->account_card = rhs.Getaccount_card();
    this->account_type = rhs.Getaccount_type();
    this->opening_date = rhs.Getopening_date();
    this->status = rhs.Getstatus();
    this->balance = rhs.Getbalance();
    this->min_balance = rhs.Getmin_balance();
    this->rate = rhs.Getrate();
    this->transaction_id = rhs.Gettransaction_id();
    this->transfer = rhs.Gettransfer();
    this->withdraw = rhs.Getwithdraw();
    this->deposit = rhs.Getdeposit();

    return *this;
}


void account::SetRegime()
{
    if(account_type=="CUR")
     {
         balance=10000.00;
         min_balance=1000.00;
         rate=1.5;
         transfer=2;
         withdraw=1;
         deposit=1;
     }
     else if(account_type=="SAV")
     {
         balance=50000.00;
         min_balance=10000.00;
         rate=2.5;
         transfer=1;
         withdraw=1;
         deposit=1;
     }
     else if(account_type=="STU")
     {
         balance=1000.00;
         min_balance=0.00;
         rate=0.0;
         transfer=0;
         withdraw=1;
         deposit=1;
     }
}
