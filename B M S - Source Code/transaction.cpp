#include "transaction.h"

transaction::transaction()
{
    //ctor
    strcpy(transaction_ID,"TRANS-XXXX");
    strcpy(transaction_nature,"TRANS-XXXX");
    strcpy(Acc_No,"XXX-XXXX-XXX");
    strcpy(To_Acc_No,"XXX-XXXX-XXX");
    Amount = 0.0;
    balance = 0.0;
    strcpy(customer_name,"");
    next = NULL;
    previous = NULL;
}

void transaction::set_transaction(account acc_, char* nature,char* to_acc, long double Amount_)
{
    Settransaction_ID(acc_.Gettransaction_id());
    Settransaction_date();
    Settransaction_nature(nature);
    SetAcc_No(acc_.Getaccount_number());
    if(to_acc)
        SetTo_Acc_No(to_acc);
    SetAmount(Amount_);
    Setbalance(acc_.Getbalance());
}

void transaction::display_transaction()
{
    system("cls");
    rectangle(10,5,60,19);
    gotoxy(11,6);
    cout<<"\t:::   "<< Gettransaction_date();
    gotoxy(46,6);
    cout<<"   :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"\t[   TRANSACTION_ID   ] --> "<<Gettransaction_ID();
    gotoxy(11,10);
    cout<<"\t[ TRANSACTION_NATURE ] --> "<<Gettransaction_nature();
    gotoxy(11,12);
    cout<<"\t[   Account_Number   ] --> "<<GetAcc_No();
    gotoxy(11,13);
    cout<<"\t[    To_Account_No   ] --> "<<GetTo_Acc_No();
    gotoxy(11,15);
    cout<<"\t[    Debit Amount    ] --> "<<GetAmount()<<"$";
    gotoxy(11,16);
    cout<<"\t[   Instant Balance  ] --> "<<Getbalance()<<"$";
    gotoxy(11,17);
    cout<<"------------------------------------------------";
    gotoxy(11,18);
    cout<<"\t\t# TRANSACTION DETAIL's #";
    gotoxy(11,20);
    cout<<"\t    [ Press Any Key to Continue ]  ";
    getch();
}


void transaction::save()
{
    FILE *fptr = fopen("transactions.txt","ab");
    fwrite(this,sizeof(transaction),1,fptr);
    fclose(fptr);
}
