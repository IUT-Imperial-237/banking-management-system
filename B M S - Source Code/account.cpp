#include "account.h"

int get_total_clients()
{
    return total_clients;
}

int read_total_clients()
{
     FILE*fp;
    fp=fopen("totalclients.txt","rb");
    if(!fp)
        return 0;
    fread(&total_clients,sizeof (int),1,fp);

    fclose(fp);
    return total_clients;
}
void set_total_clients(int val)
{
    total_clients = val;
}
void increase_total_clients()
{
    total_clients += 1;
}
void decrease_total_clients()
{
    total_clients -= 1;
}
void initialize_total_clients()
{
    total_clients = 0;
}
void write_total_clients()
{
     FILE*fp;
    fp=fopen("totalclients.txt","wb");
    fwrite(&total_clients,sizeof(int),1,fp);

    fclose(fp);

}


account::account()
{
    //ctor
    strcpy(this->account_number, "XXX-XXXX-XXX");
    strcpy(this->account_card, "XXX-XXXX");
    strcpy(this->account_type, "");  /**< CUR | SAV | STU >*/

    this->status = false;
    this->balance = 0.00;
    strcpy(this->transaction_id, "TRANS-XXXX");
}

account& account::operator=(account rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment

    //assignment operator
    strcpy(this->account_number, rhs.Getaccount_number());
    strcpy(this->account_card, rhs.Getaccount_card());
    strcpy(this->account_type, rhs.Getaccount_type());
    strcpy(this->opening_date, rhs.Getopening_date());
    this->status = rhs.Getstatus();
    this->balance = rhs.Getbalance();
    this->min_balance = rhs.Getmin_balance();
    this->rate = rhs.Getrate();
    strcpy(this->transaction_id, rhs.Gettransaction_id());
    this->Settransfer_tag(rhs.Gettransfer_tag());
    this->Setwithdraw_tag(rhs.Getwithdraw_tag());
    this->Setdeposit_tag(rhs.Getdeposit_tag());

    return *this;
}


void account::SetRegime()
{
    if(!strcmp(account_type,"CUR"))
    {
        balance=10000.00;
        min_balance=1000.00;
        rate=1.5;
        transfer_tag=2;
        withdraw_tag=1;
        deposit_tag=1;
    }
    else if(!strcmp(account_type,"SAV"))
    {
        balance=50000.00;
        min_balance=10000.00;
        rate=2.5;
        transfer_tag=1;
        withdraw_tag=1;
        deposit_tag=1;
    }
    else if(!strcmp(account_type,"STU"))
    {
        balance=1000.00;
        min_balance=0.00;
        rate=0.0;
        transfer_tag=0;
        withdraw_tag=1;
        deposit_tag=1;
    }
}

void account::Activate_Account()
{
    this->SetRegime();
    this->status = true;
    this->generate_Acc_Number();
    this->generate_Acc_Card();
    this->generate_Trans_ID();
    this->Setopening_date();

}


/***    aUTO-GENERATION     ***/

void account::generate_Acc_Number()
{
    time_t t;
    int num,d_len,r_len,o_len;
    char random[10];
    char rand_sequence[10]="000";
    char order_sequence[5]="000";
    char date_sequence[]="";
    char order[5];
    char *f_acc_num;
    char *date;
    char str_error[10];


    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,random,10);
    r_len = strlen(random);
    if(r_len==1)
    {
        strcat(rand_sequence,random);
    }
    else if(r_len==2)
    {
        rand_sequence[2]='\0';
        strcat(rand_sequence,random);
    }
    else if(r_len==3)
    {
        rand_sequence[1]='\0';
        strcat(rand_sequence,random);
    }
    else
        strcpy(rand_sequence,random);


    ///* Creation Order Generator */

    itoa(total_clients,order,16);
    o_len = strlen(order);
    if(o_len==1)
    {
        order_sequence[2]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==2)
    {
        order_sequence[1]='\0';
        strcat(order_sequence,order);
    }
    else
        strcpy(order_sequence,order);
    strcpy(str_error,order_sequence);

    ///* Week Day Generator */

    date = getTime();
    d_len = strlen(date);
    date_sequence[0] = date[0];
    date_sequence[1] = date[d_len-3];
    date_sequence[2] = date[d_len-2];
    date_sequence[3] = '\0';

    f_acc_num = (char *) malloc(20*sizeof(char));
    strcpy(f_acc_num,"");
    strcat(f_acc_num,date_sequence);
    strcat(f_acc_num,"-");
    strcat(f_acc_num,rand_sequence);
    strcat(f_acc_num,"-");
    strcat(f_acc_num,str_error);

    this->Setaccount_number(f_acc_num);
}
void account::generate_Acc_Card()
{
    char acc_type[10] = "";
    char order_sequence[10]="0000";
    char order[5];
    char *f_car_num;
    int o_len;

    ///* Account Type Generator */

    strcpy(acc_type, this->Getaccount_type());

    ///* Creation Order Generator */

    itoa(total_clients,order,10);
    o_len = strlen(order);

    if(o_len==1)
    {
        order_sequence[3]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==2)
    {
        order_sequence[2]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==3)
    {
        order_sequence[1]='\0';
        strcat(order_sequence,order);
    }
    else
        strcpy(order_sequence,order);

    f_car_num = (char *) malloc(20*sizeof(char));
    strcpy(f_car_num,"");
    strcat(f_car_num,acc_type);
    strcat(f_car_num,"-");
    strcat(f_car_num,order_sequence);

    this->Setaccount_card(f_car_num);
}

void account::display_Acc_Info()
{
    if(Getstatus())
    {
        system("cls");
        rectangle(10,5,60,16);
        gotoxy(10,6);
        cout<<"\t     ::: Account Informations :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(10,9);
        cout<<"\t   [  Account Number ] --> "<<this->Getaccount_number();
        gotoxy(10,11);
        cout<<"\t   [ ATM Card Number ] --> "<<this->Getaccount_card();
        gotoxy(10,13);
        cout<<"\t   [   Account Type  ] --> "<<this->Getaccount_type();
        gotoxy(10,15);
        cout<<"\t  # Account Successfully Generated !!!";
        gotoxy(10,18);
        cout<<"\t    [ Press Any Key to Continue ]  ";
        getch();
    }
    else
        message(string("\t Account IS NOT Activated "));
}
void account::generate_Trans_ID()
{
    char *f_trans_ID;
    char rand_num[10]="";
    char rand_seq[10]="000";
    time_t t;
    int num,r_len;

    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,rand_num,16);
    r_len = strlen(rand_num);

    if(r_len==1)
    {
        strcat(rand_seq,rand_num);
    }
    else if(r_len==2)
    {
        rand_seq[2]='\0';
        strcat(rand_seq,rand_num);
    }
    else if(r_len==3)
    {
        rand_seq[1]='\0';
        strcat(rand_seq,rand_num);
    }
    else
        strcpy(rand_seq,rand_num);

    f_trans_ID = new char[20];

    strcpy(f_trans_ID,"TRANS-");
    strcat(f_trans_ID,rand_seq);

    this->Settransaction_id(f_trans_ID);
}

void account::disable_account(int option)
{
    switch(option)
    {
    case 1:

        this->Setaccount_number((char*)EMPTY);
        this->Setaccount_card((char*)EMPTY);
        this->Setaccount_type((char*)EMPTY);

        strcpy(this->opening_date, "");

        this->Setstatus(false);
        this->Setbalance(0);
        this->Setbalance(0);
        this->Setrate(0);

        strcpy(this->transaction_id, "");

        this->Settransfer_tag(0);
        this->Setwithdraw_tag(0);
        this->Setdeposit_tag(0);

        break;
    case 2:
        this->Setstatus(false);
        break;
    }
}
