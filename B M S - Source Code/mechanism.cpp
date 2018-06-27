#include "mechanism.h"
static string memory_PIN;
///----------------------------------------------------
void Create_New_User(client* list)
{
    int type;
    string name,dob,gender,parent,address,profession,country,phone,email;
INFOS:
    system("cls");
    rectangle(0,0,80,25);
    gotoxy(1,1);
    cout<<"\t\t\t ===  CREATE  NEW  CLIENT  ===";
    gotoxy(1,2);
    cout<<"------------------------P-E-R-S-O-N-A-L _ I-N-F-O-S---------------------------";
    fflush(stdin);
    gotoxy(1,4);
    cout<<"\tEnter Client's Name :  ";
    cin>>name;
    gotoxy(1,6);
    cout<<"\tEnter Date of Birth :  ";
    fflush(stdin);
    cin>>dob;
    gotoxy(1,8);
    cout<<"\tEnter M [for Male] && F [for Female] : ";
    fflush(stdin);
    cin>>gender;
    gotoxy(1,10);
    cout<<"\tEnter Father's && Mother's Name : ";
    fflush(stdin);
    cin>>parent;
    gotoxy(1,12);
    cout<<"\tEnter Client's Permanent Address : ";
    fflush(stdin);
    cin>>address;
    gotoxy(1,14);
    cout<<"\tEnter Client's Profession : ";
    fflush(stdin);
    cin>>profession;
    gotoxy(1,16);
    cout<<"\tEnter Client's Country : ";
    cin>>country;
    gotoxy(1,18);
    cout<<"\tEnter Client's Phone Number : ";
    cin>>phone;
    gotoxy(1,20);
    cout<<"\tEnter Client's Email : ";
    cin>>email;



ACC_CONFIRM:
    system("cls");
    rectangle(10,5,75,15);
    gotoxy(10,6);
    cout<<"\t     ::: Do you Agree with the Client Infos ? :::";
    gotoxy(11,7);
    cout<<"---------------------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [Y] --> Yes, I agree and confirm the Client Infos";
    gotoxy(10,11);
    cout<<"\t   [N] --> No, I disagree, Let's Restart Infos Section";
    gotoxy(10,14);
    cout<<"\t\t  Answer :  ";
    type = getche();
    if(type=='Y' || type=='y')
        goto ACC_TYPE;
    else if(type=='N' || type=='n')
    {
        goto INFOS;
    }
    else
        goto ACC_CONFIRM;

ACC_TYPE:

    person customer_info(name,dob,phone,country,parent,gender,email,address,profession);
    account tem_acc;
    client* new_customer;

    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     ::: Select Account Type :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        tem_acc.Setaccount_type((char*)"SAV");
        break;
    case 2:
        tem_acc.Setaccount_type((char*)"CUR");
        break;
    case 3:
        tem_acc.Setaccount_type((char*)"STU");
        break;
    default:
        goto ACC_TYPE;
    }

    new_customer = new client(customer_info,tem_acc);
    new_customer->Setclient_ID();
    new_customer->Setpin_code();
    process_execution((char*)"GENERATING && ACTIVATION");


    increase_total_clients();

    if(new_customer->current_account.Getstatus())
        new_customer->current_account.display_Acc_Info();
    if(new_customer->savings_account.Getstatus())
        new_customer->savings_account.display_Acc_Info();
    if(new_customer->student_account.Getstatus())
        new_customer->student_account.display_Acc_Info();

    system("cls");
    string met1("\t     PIN-CODE :::  ");
    string met2;
    met2.assign(new_customer->Getpin_code());
    message(met1+met2);
    saveData(new_customer,1);
    write_total_clients();

}

void Create_New_User(admin* head)
{
    int type;
    string name,dob,gender,parent,address,profession,country,phone,email;
INFOS:
    system("cls");
    rectangle(0,0,80,25);
    gotoxy(1,1);
    cout<<"\t\t\t ===  CREATE  NEW  CLIENT  ===";
    gotoxy(1,2);
    cout<<"------------------------P-E-R-S-O-N-A-L _ I-N-F-O-S---------------------------";
    fflush(stdin);
    gotoxy(1,4);
    cout<<"\tEnter Client's Name :  ";
    cin>>name;
    gotoxy(1,6);
    cout<<"\tEnter Date of Birth :  ";
    fflush(stdin);
    cin>>dob;
    gotoxy(1,8);
    cout<<"\tEnter M [for Male] && F [for Female] : ";
    fflush(stdin);
    cin>>gender;
    gotoxy(1,10);
    cout<<"\tEnter Father's && Mother's Name : ";
    fflush(stdin);
    cin>>parent;
    gotoxy(1,12);
    cout<<"\tEnter Client's Permanent Address : ";
    fflush(stdin);
    cin>>address;
    gotoxy(1,14);
    cout<<"\tEnter Client's Profession : ";
    fflush(stdin);
    cin>>profession;
    gotoxy(1,16);
    cout<<"\tEnter Client's Country : ";
    cin>>country;
    gotoxy(1,18);
    cout<<"\tEnter Client's Phone Number : ";
    cin>>phone;
    gotoxy(1,20);
    cout<<"\tEnter Client's Email : ";
    cin>>email;

    person admin_info(name,dob,phone,country,parent,gender,email,address,profession);
    admin* new_admin = NULL;

    new_admin = new admin(admin_info);


INFOS_CONFIRM:
    system("cls");
    rectangle(10,5,75,15);
    gotoxy(10,6);
    cout<<"\t     ::: Do you Agree with these Informations ? :::";
    gotoxy(11,7);
    cout<<"---------------------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [Y] --> Yes, I agree and confirm these Infos";
    gotoxy(10,11);
    cout<<"\t   [N] --> No, I disagree, Let's Restart Infos Section";
    gotoxy(10,14);
    cout<<"\t\t  Answer :  ";
    type = getche();
    if(type=='Y' || type=='y')
        goto CATEGORY;
    else if(type=='N' || type=='n')
    {
        goto INFOS;
    }
    else
        goto INFOS_CONFIRM;

CATEGORY:

    string username, password, functionality;
    system("cls");
    rectangle(10,5,75,15);
    gotoxy(10,6);
    cout<<"\t     ::: SELECT USER-TYPE :::";
    gotoxy(11,7);
    cout<<"---------------------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [A] --> 'A' for Bank Administrator Members";
    gotoxy(10,11);
    cout<<"\t   [S] --> 'S' for Bank Staff Members";
    gotoxy(10,14);
    cout<<"\t\t  Answer :  ";
    type = getche();
    if(type=='A' || type=='a' )
    {
        new_admin->Setcategory((char*)ADMIN);
        goto CREDENTIAL;
    }
    else if(type=='S' || type=='s')
    {
        new_admin->Setcategory((char*)STAFF);
        goto CREDENTIAL;
    }
    else
        goto CATEGORY;

CREDENTIAL:
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     ::: SET USER CREDENTIALS :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [ FUNCTION ] --> ";
    functionality = "";
    cin>>functionality;
    gotoxy(10,11);
    cout<<"\t   [ USERNAME ] --> ";
    username = "";
    cin>>username;
    gotoxy(10,13);
    cout<<"\t   [ PASSWORD ] --> ";
    password = "";
    cin>>password;
    gotoxy(11,16);
    cout<<"Press any Key to Continue or Esc to input again";
    fflush(stdin);
    type = getch();
    if(type==27)
        goto CREDENTIAL;

    new_admin->generate_user_ID();
    new_admin->Setfunctionality((char*)functionality.c_str());
    new_admin->Setusername((char*)username.c_str());
    new_admin->Setpassword((char*)password.c_str());
    new_admin->Setcreated_date();
    new_admin->automate_salary_scale();


    saveData(new_admin,1);
    process_execution((char*)"GENERATING NEW USER");
    new_admin->display_user_credentials();
    message(string("ADMIN USER HAS BEEN SUCCESSFULLY CREATED !!!"));
}

///----------------------------------------------------

client* Delete_New_User(client* list, int option)
{
    string acc_num;
    client* temp_delete = NULL;
    int type;

    switch(option)
    {
    case 1: //!-- Delete a Specific Account;
        title((char*)"ADMIN");
        gotoxy(5,5);
        cout<<"\t\t\t===== DELETE ACCOUNT =====";
        gotoxy(5,9);
        cout<<"\t\tEnter Account Number ::  ";
        fflush(stdin);
        cin>>acc_num;

        temp_delete = Search_User(list,acc_num,1);
        if(temp_delete)
        {
ANSWER:
            message(string("\tACCOUNT SUCCESSFULLY FOUND !!!"));
            temp_delete->temp_acc->display_Acc_Info();
            system("cls");
            rectangle(10,5,60,11);
            gotoxy(10,6);
            cout<<"\t::: Do you wish to Delete this Account ? :::";
            gotoxy(11,7);
            cout<<"------------------------------------------------";
            gotoxy(11,9);
            cout<<"          Yes [Y] or No [N]  :::  ";
            type = getche();
            if(type=='Y'||type=='y')
            {
                temp_delete->temp_acc->disable_account(1);
                temp_delete->temp_acc = NULL;
                message(string("\tACCOUNT SUCCESSFULLY DELETED !!!"));
                return list;
            }
            else if(type=='N'||type=='n')
            {
                message(string("\tOPERATION HAS BEEN CANCELLED !!!"));
                return list;
            }
            else
            {
                goto ANSWER;
            }
        }
        else
        {
            message(string(" ACCOUNT DOESN'T EXIST IN THE SYSTEM !!!"));
            //return list;
            break;
        }
        break;
    case 2:  //!-- Delete Completely a Client from the System;
        title((char*)"ADMIN");
        gotoxy(5,5);
        cout<<"\t\t\t===== DELETE COMPLETELY CLIENT =====";
        gotoxy(5,9);
        cout<<"\t\tEnter CLIENT-ID ::  ";
        fflush(stdin);
        cin>>acc_num;

        client* previous;
        previous = NULL;
        client* next;
        next = NULL;

        temp_delete = Search_User(list,acc_num,1);
        if(temp_delete)
        {
ANSWER1:
            message(string("\tACCOUNT SUCCESSFULLY FOUND !!!"));
            temp_delete->temp_acc->display_Acc_Info();
            system("cls");
            rectangle(10,5,60,11);
            gotoxy(10,6);
            cout<<"\t      ::: Do you wish to Delete this Account ? :::";
            gotoxy(11,7);
            cout<<"------------------------------------------------";
            gotoxy(11,9);
            cout<<"          Yes [Y] or No [N]  :::  ";
            int type;
            type = getche();
            if(type=='Y'||type=='y')
            {
                if(temp_delete->next == NULL && temp_delete->previous == NULL)
                {
                    delete temp_delete;
                    list = NULL;
                    decrease_total_clients();
                    process_execution((char*)"DELETING ACCOUNT");
                }
                else if(temp_delete->previous == NULL && temp_delete->next != NULL)
                {
                    next = temp_delete->next;
                    next->previous = NULL;
                    delete temp_delete;
                    list = next;
                    decrease_total_clients();
                    process_execution((char*)"DELETING ACCOUNT");
                }
                else if(temp_delete->previous != NULL && temp_delete->next == NULL)
                {
                    previous = temp_delete->previous;
                    previous->next = NULL;
                    delete temp_delete;
                    decrease_total_clients();
                    process_execution((char*)"DELETING ACCOUNT");
                }
                else
                {
                    previous = temp_delete->previous;
                    next = temp_delete->next;
                    delete temp_delete;
                    previous->next = next;
                    next->previous = previous;
                    decrease_total_clients();
                    process_execution((char*)"DELETING ACCOUNT");
                }
                message(string("  ACCOUNT SUCCESSFULLY DELETED FROM SYSTEM !!!"));
                return list;
            }
            else if(type=='N'||type=='n')
            {
                message(string("\tOPERATION HAS BEEN CANCELLED !!!"));
                return list;
            }
            else
            {
                goto ANSWER1;
            }
        }
        else
        {
            message(string(" ACCOUNT DOESN'T EXIST IN THE SYSTEM !!!"));
            break;
        }
        break;
    default:
        message(string("SYSTEM FAILURE RESULTS :( :( PLEASE CONTACT US"));
        error_report(string("SYSTEM FAILURE RESULTS DUE TO CODING ERROR IN DELETE_USER(client)."));
        exit(1);
    }
    return list;
}
admin* Delete_New_User(admin* head)
{
    string user_ID;
    admin* temp_delete = NULL;
    admin* next = NULL;
    admin* previous = NULL;
    title((char*)"ADMIN");
    gotoxy(5,5);
    cout<<"\t\t\t===== DELETE MEMBER USER =====";
    gotoxy(5,9);
    cout<<"\t\tEnter MEMBER USER-ID ::  ";
    fflush(stdin);
    cin>>user_ID;

    temp_delete = Search_User(head,user_ID,3);

    if(temp_delete)
    {
RESPONSE:
        message(string("\tUSER SUCCESSFULLY FOUND !!!"));
        temp_delete->display_user_credentials();
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(11,6);
        cout<<"   ::: Do you wish to Delete this User ? :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(11,9);
        cout<<"          Yes [Y] or No [N]  :::  ";
        int type;
        type = getche();
        if(type=='Y'||type=='y')
        {
            if(temp_delete->next == NULL && temp_delete->previous == NULL)
            {
                delete temp_delete;
                head = NULL;
                process_execution((char*)"DELETING USER");
            }
            else if(temp_delete->previous == NULL && temp_delete->next != NULL)
            {
                next = temp_delete->next;
                temp_delete->next = NULL;
                next->previous = NULL;
                delete temp_delete;
                head = next;
                process_execution((char*)"DELETING USER");
            }
            else if(temp_delete->previous != NULL && temp_delete->next == NULL)
            {
                previous = temp_delete->previous;
                temp_delete->previous = NULL;
                previous->next = NULL;
                delete temp_delete;
                process_execution((char*)"DELETING USER");
            }
            else
            {
                previous = temp_delete->previous;
                temp_delete->previous = NULL;
                next = temp_delete->next;
                temp_delete->next = NULL;
                delete temp_delete;
                previous->next = next;
                next->previous = previous;
                process_execution((char*)"DELETING USER");
            }
            message(string("\tUSER SUCCESSFULLY DELETED !!!"));
            return head;
        }
        else if(type=='N'||type=='n')
        {
            message(string("\tOPERATION HAS BEEN CANCELLED !!!"));
            return head;
        }
        else
        {
            goto RESPONSE;
        }
        return head;
    }
    else
    {
        message(string("\tUSER NOT FOUND IN THE SYSTEM !!!"));
        return head;
    }
    return NULL;
}

///----------------------------------------------------

client* Search_User(client* head,string key,int option)
{
    client* current = NULL;
    current = head;
    switch(option)
    {
    case 1: //!*** search by account_number
        while(current)
        {
            if(!strcmp(current->current_account.Getaccount_number(),key.c_str()))
            {
                current->temp_acc = &(current->current_account);
                return current;
            }
            else if(!strcmp(current->savings_account.Getaccount_number(),key.c_str()))
            {
                current->temp_acc = &(current->savings_account);
                return current;
            }
            else if(!strcmp(current->student_account.Getaccount_number(),key.c_str()))
            {
                current->temp_acc = &(current->student_account);
                return current;
            }
            current = current->next;
        }
        break;
    case 2: //!*** search by account_card
        while(current)
        {
            if(!strcmp(current->current_account.Getaccount_card(),key.c_str()))
            {
                current->temp_acc = &(current->current_account);
                return current;
            }
            else if(!strcmp(current->savings_account.Getaccount_card(),key.c_str()))
            {
                current->temp_acc = &(current->savings_account);
                return current;
            }
            else if(!strcmp(current->student_account.Getaccount_card(),key.c_str()))
            {
                current->temp_acc = &(current->student_account);
                return current;
            }
            current = current->next;
        }
        break;
    case 3: //!*** search by pin_code
        while(current)
        {
            if(!strcmp(current->Getpin_code(),key.c_str()))
                return current;
            current = current->next;
        }
        break;
    case 4: //!*** search by client_ID
        while(current)
        {
            if(!strcmp(current->Getclient_ID(),key.c_str()))
                return current;
            current = current->next;
        }
        break;
    }
    return NULL;
}
admin* Search_User(admin* head,string key,int option)
{
    admin* current = NULL;
    current = head;
    switch(option)
    {
    case 1://!-- search by username;
        while(current)
        {
            if(!stricmp(current->Getusername(),key.c_str()))
                return current;
            current = current->next;
        }
        break;
    case 2://!-- search by password;
        while(current)
        {
            if(!strcmp(current->Getpassword(),key.c_str()))
                return current;
            current = current->next;
        }
        break;
    case 3://!-- search by user-ID;
        while(current)
        {
            if(!strcmp(current->Getuser_ID(),key.c_str()))
                return current;
            current = current->next;
        }
        break;
    case 4://!-- search and return all the User of Same Category;
        admin* sub_head = NULL;
        admin* sub_current = NULL;
        admin* sub_new = NULL;
        while(current)
        {
            if(!strcmp(current->Getcategory(),key.c_str()))
            {
                sub_new = new admin(*current);
                if(sub_head)
                {
                    sub_current = sub_head;
                    while(sub_current->next)
                        sub_current = sub_current->next;
                    sub_current->next = sub_new;
                    sub_current->previous = sub_current;
                }
                else
                {
                    sub_head = sub_new;
                }
            }
            current = current->next;
        }
        break;
    }
    return NULL;
}

///----------------------------------------------------

void saveData(client *head,int option)
{
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/clients");

    // open a file in write mode.
    FILE* fp;
    client* current;
    switch(option)
    {
    case 1:
        fp=fopen("clientbin.txt","ab");
        fwrite(head,sizeof (client),1,fp);
        break;
    case 2:
        fp=fopen("clientbin.txt","wb");
        current = head;
        while(current)
        {
            fwrite(current,sizeof (client),1,fp);
            current = current->next;
        }
        break;
    }
    fclose(fp);
    write_total_clients();
}
void saveData(admin *head,int option)
{
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/admins");

    // open a file in write mode.
    FILE* fp;
    admin* current = NULL;

    switch(option)
    {
    case 1:
        fp=fopen("admins.txt","ab");
        fwrite(head,sizeof (admin),1,fp);
        break;
    case 2:
        fp=fopen("admins.txt","wb");
        current = head;
        while(current)
        {
            fwrite(current,sizeof (admin),1,fp);
            current = current->next;
        }
        break;
    }
    fclose(fp);
}


client* LoadData(client*)
{
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/clients");

    // open a file in read mode.
    client *current,*new_elt;
    client *head = NULL;
    new_elt=(client*)malloc(sizeof(client));
    FILE* fp;

    fp=fopen("clientbin.txt","rb");

    if(read_total_clients()==0 || fp == NULL)
    {
        initialize_total_clients();
        return NULL;
    }

    while(fread(new_elt,sizeof (client),1,fp)==1)
    {
        new_elt->next=NULL;
        new_elt->previous=NULL;
        if(head==NULL)
        {
            head = new_elt;
        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }
            current->next = new_elt;
            new_elt->previous = current;
        }
        new_elt=(client*)malloc(sizeof(client));
    }
    fclose(fp);
    return head;
}

admin* LoadData(admin*)
{
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/admins");

    // open a file in read mode.

    FILE*fp;
    fp=fopen("admins.txt","rb");
    admin *current,*new_elt;
    admin *head = NULL;
    new_elt = new admin;

    while(fread(new_elt,sizeof (admin),1,fp)==1)
    {
        new_elt->next=NULL;
        new_elt->previous=NULL;
        if(head==NULL)
        {
            head = new_elt;
        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }
            current->next = new_elt;
            new_elt->previous = current;
        }
        new_elt = new admin;
    }
    fclose(fp);
    return head;
}

void balance_check(client *customer)
{
    int type;
    account temp_ACC;
BALANCE:
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     :::     Select Account     :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        if(customer->savings_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto BALANCE;
        }
        system("cls");
        title((char*)"CLIENT");
        gotoxy(5,10);
        cout<<"\t\t   # Current Balance :::  "<<customer->savings_account.Getbalance()<<" $";
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ] ");
        getch();
        break;
    case 2:
        if(customer->current_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto BALANCE;
        }
        system("cls");
        title((char*)"CLIENT");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,10);
        cout<<"\t\t   # Current Balance :::  "<<customer->current_account.Getbalance()<<" $";
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ] ");
        getch();
        break;
    case 3:
        if(customer->student_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto BALANCE;
        }
        system("cls");
        title((char*)"CLIENT");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,10);
        cout<<"\t\t   # Current Balance :::  "<<customer->student_account.Getbalance()<<" $";
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ] ");
        getch();
        break;
    default:
        message(string("\t\t WRONG CHOICE !!!"));
        goto BALANCE;
    }
}

void withdraw(client *customer, char* type_acc)
{
    if(!strcmp(type_acc,"CUR"))
    {
        double amount;
        system("cls");
        title((char*)"CLIENT");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,5);
        printf("\t\t\t===== WITHDRAW SECTION =====");
        gotoxy(5,10);
        //customer->account.active=1;
        //customer->account.balance=1000;

        cout<<"\t\t\tAmount to Withdraw ::  ";
        cin>>amount;

        switch(customer->current_account.difference(amount))
        {
        case -1:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 0:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 1:
            customer->current_account.withdraw(amount);
            gotoxy(5,13);
            cout<<"\t\t       # Successful Transaction !!!";
            generate_transactions(customer->current_account,(char*)"Withdraw",NULL,amount);
            gotoxy(5,15);
            cout<<"\t\t        Current Balance = "<<customer->current_account.Getbalance()<<" $";
            gotoxy(5,17);
            cout<<"\t\t     [ Press Any Key to Continue ]";
            getch();
            break;
        }
    }
    else if(!strcmp(type_acc,"SAV"))
    {
        double amount;
        system("cls");
        title((char*)"CLIENT");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,5);
        printf("\t\t\t===== WITHDRAW SECTION =====");
        gotoxy(5,10);
        //customer->account.active=1;
        //customer->account.balance=1000;

        cout<<"\t\t\tAmount to Withdraw ::  ";
        cin>>amount;

        switch(customer->savings_account.difference(amount))
        {
        case -1:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 0:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 1:
            customer->savings_account.withdraw(amount);
            gotoxy(5,13);
            printf("\t\t       # Successful Transaction !!!");
            generate_transactions(customer->savings_account,(char*)"Withdraw",NULL,amount);
            gotoxy(5,15);
            cout<<"\t\t        Balance = "<<customer->savings_account.Getbalance()<<" $";
            gotoxy(5,17);
            printf("\t\t     [ Press Any Key to Continue ]");
            getch();
            break;
        }
    }
    else if(!strcmp(type_acc,"STU"))
    {
        double amount;
        system("cls");
        title((char*)"CLIENT");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,5);
        printf("\t\t\t===== WITHDRAW SECTION =====");
        gotoxy(5,10);
        //customer->account.active=1;
        //customer->account.balance=1000;

        cout<<"\t\t\tAmount to Withdraw ::  ";
        cin>>amount;

        switch(customer->student_account.difference(amount))
        {
        case -1:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 0:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For the Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 1:
            customer->student_account.withdraw(amount);
            gotoxy(5,13);
            printf("\t\t       # Successful Transaction !!!");
            generate_transactions(customer->student_account,(char*)"Withdraw",NULL,amount);
            gotoxy(5,15);
            cout<<"\t\t        Balance = "<<customer->student_account.Getbalance()<<" $";
            gotoxy(5,17);
            printf("\t\t     [ Press Any Key to Continue ]");
            getch();
            break;
        }
    }

}

void withdraw(client *customer)
{
    /** withdraw option */
WITHDRAWAL:
    int type;
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     :::     Select Account     :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        if(customer->savings_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto WITHDRAWAL;
        }
        withdraw(customer,customer->savings_account.Getaccount_type());
        break;
    case 2:
        if(customer->current_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto WITHDRAWAL;
        }
        withdraw(customer,customer->current_account.Getaccount_type());
        break;
    case 3:
        if(customer->student_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto WITHDRAWAL;
        }
        withdraw(customer,customer->student_account.Getaccount_type());
        break;
    default:
        message(string("\t\t WRONG CHOICE !!!"));
        goto WITHDRAWAL;
    }
}


transaction* read_all_transactions()
{
    transaction *current = NULL, *new_trans = NULL, *head = NULL;
    FILE *fptr = fopen("transactions.txt","rb");
    new_trans = new transaction;
    while(fread(new_trans,sizeof(transaction),1,fptr)==1)
    {
        if(head)
        {
            current = head;
            while(current->next)
                current = current->next;
            current->next = new_trans;
            new_trans->previous = current;
        }
        else
            head = new_trans;
        new_trans = new transaction;
    }
    fclose(fptr);
    return head;
}

void generate_transactions(account acc_, char* nature,char* to_acc, long double Amount_)
{
    transaction new_trans;
    new_trans.set_transaction(acc_,nature,to_acc,Amount_);
    new_trans.save();
}
void view_transactions_of_account(account acc_,int option)
{
    transaction *head_trans = NULL,*current = NULL;
    int i=0;

    current = read_all_transactions();

    switch(option)
    {
    case 1:
        /***  Continuous Card of Transactions made (1 by 1) */
        while(current)
        {
            if(!strcmp(current->Gettransaction_ID(),acc_.Gettransaction_id()))
                current->display_transaction();
            current = current->next;
        }
        break;
    case 2:
        /***    Continuous List of Transactions made (3 by 3)*/
        static string stars("\t***********************************************");
        static string tirs("\t|---------------------------------------------");
        system("cls");
        cout<<"\n\t\tHistory of Account Activities"<<endl;
        cout<<stars<<endl;
        while(current)
        {
            if(!strcmp(current->Gettransaction_ID(),acc_.Gettransaction_id()))
            {
                cout<<"\t| Transact. Nature :: ";
                cout<<current->Gettransaction_nature()<<"\t\t      |"<<endl;
                cout<<"\t| Transaction Date :: ";
                cout<<current->Gettransaction_date();
                cout<<"\t| Account  Number  :: ";
                cout<<current->GetAcc_No()<<"\t      |"<<endl;
                cout<<"\t| Transfer Account :: ";
                cout<<current->GetTo_Acc_No()<<"\t      |"<<endl;
                cout<<tirs<<"|"<<endl;
                cout<<"\t|\tAmount :: ";
                cout<<current->GetAmount()<<"$    Balance ::"<<current->Getbalance()<<"$"<<"  |"<<endl;
                cout<<stars<<endl;
                i++;
                if(i==3)
                {
                    cout<<"\n\t[ Press Any Key to view more or Esc to return ] ";
                    i=0;
                    if(getch()==27)
                        return;
                    system("cls");
                    cout<<"\n\t\tHistory of Account Activities"<<endl;
                    cout<<stars<<endl;
                }
            }
            current = current->next;
        }
        cout<<"\n\t\t\t[ Esc to return ] ";
        if(getch()==27)
            return;
        break;
    case 3:
        /***    Most Latest Transaction made */
        while(current)
        {
            if(!strcmp(current->Gettransaction_ID(),acc_.Gettransaction_id()))
                head_trans = current;
            current = current->next;
        }
        if(head_trans)
            head_trans->display_transaction();
        else
            message(string(" NO TRANSACTION HAVE BEEN YET DONE !!!"));
        break;
    }

}
void view_all_transactions(int option)
{
    transaction *current = NULL;
    int i=0;

    current = read_all_transactions();

    switch(option)
    {
    case 1:
        /***  Continuous Card of Transactions made (1 by 1) */
        while(current)
        {
            current->display_transaction();
            current = current->next;
        }
        break;
    case 2:
        /***    Continuous List of Transactions made (3 by 3)*/
        static string stars("\t***********************************************");
        static string tirs("\t|---------------------------------------------");
        system("cls");
        cout<<"\n\t\tHistory of Account Activities"<<endl;
        cout<<stars<<endl;
        while(current)
        {
            cout<<"\t| Transact. Nature :: ";
            cout<<current->Gettransaction_nature()<<"\t\t      |"<<endl;
            cout<<"\t| Transaction Date :: ";
            cout<<current->Gettransaction_date();
            cout<<"\t| Account  Number  :: ";
            cout<<current->GetAcc_No()<<"\t      |"<<endl;
            cout<<"\t| Transfer Account :: ";
            cout<<current->GetTo_Acc_No()<<"\t      |"<<endl;
            cout<<tirs<<"|"<<endl;
            cout<<"\t|\tAmount :: ";
            cout<<current->GetAmount()<<"$    Balance ::"<<current->Getbalance()<<"$"<<"  |"<<endl;
            cout<<stars<<endl;
            i++;
            if(i==3)
            {
                cout<<"\n\t[ Press Any Key to view more or Esc to return ] ";
                i=0;
                if(getch()==27)
                    return;
                system("cls");
                cout<<"\n\t\tHistory of Account Activities"<<endl;
                cout<<stars<<endl;
            }
            current = current->next;
        }
        cout<<"\n\t\t\t[ Esc to return ] ";
        if(getch()==27)
            return;
        break;
    }
}
void transfer(client* customer, client* head)
{
    long double amount;
    string acc_num;
    client *transf_customer;
    int type;

    /** transfer option */
TRANSFER:
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     :::     Select Account     :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        if(customer->savings_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto TRANSFER;
        }
        else if(customer->savings_account.judgment(NULL)==false)
        {
            gotoxy(3,10);
            message(string("This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING"));
            return;
        }
        system("cls");
        title((char*)"CLIENT");
        gotoxy(5,7);
        cout<<"Amount to Transfer ::  ";
        cin>>amount;
        switch(customer->savings_account.difference(amount))
        {
        case -1:
        case 0:
            message(string("# Insufficient Balance For this Transaction"));
            break;
        case 1:
            gotoxy(5,9);
            cout<<"Transfer to Acount No. ::  ";
            cin>>acc_num;
            transf_customer = Search_User(head,acc_num,1);
            if(transf_customer==NULL)
            {
                gotoxy(5,10);
                cout<<"The Transferring Account Number '"<<acc_num<<"' Doesn't Exist in BMS!!!";
                gotoxy(5,15);
                printf("\t\t    [ Press Any Key to Continue ] ");
                getch();
                message(string("\t* UNSUCCESSFUL TRANSACTION  :( !!!"));
                return;
            }
            else if(customer == transf_customer)
            {
                message(string("TRANSACTION IS NOT ALLOWED <ERR_CODE::T001>"));
                return;
            }
            else if(customer->savings_account.judgment(transf_customer->temp_acc))
            {
                customer->savings_account.transfer(amount);
                transf_customer->temp_acc->deposit(amount);
                gotoxy(5,13);
                cout<<"\t\t       # Successful Transaction !!!";
                generate_transactions(customer->current_account,(char*)"Transfer Sender",(char*)acc_num.c_str(),amount);
                generate_transactions(*(transf_customer->temp_acc),(char*)"Transfer Receiver",(char*)acc_num.c_str(),amount);
                gotoxy(5,15);
                cout<<"\t\t        Current Balance = "<<customer->current_account.Getbalance()<<" $";
            }
            else
            {
                gotoxy(3,10);
                cout<<"This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING TO "<<transf_customer->temp_acc->Getaccount_type();
                gotoxy(5,13);
                cout<<"\t* Unsuccessful Transaction !!!";
            }
            gotoxy(5,17);
            printf("\t\t     [ Press Any Key to Continue ]");
            getch();
            break;
        }
        break;
    case 2:
        if(customer->current_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto TRANSFER;
        }
        else if(customer->current_account.judgment(NULL)==false)
        {
            gotoxy(3,10);
            message(string("This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING"));
            return;
        }
        system("cls");
        title((char*)"CLIENT");
        gotoxy(5,7);
        cout<<"Amount to Transfer ::  ";
        cin>>amount;
        switch(customer->current_account.difference(amount))
        {
        case -1:
        case 0:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For this Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 1:
            gotoxy(5,9);
            cout<<"Transfer to Account No. ::  ";
            cin>>acc_num;
            transf_customer = Search_User(head,acc_num,1);
            if(transf_customer==NULL)
            {
                gotoxy(5,10);
                cout<<"The Transferring Account Number '"<<acc_num<<"' Doesn't Exist in BMS!!!";
                gotoxy(5,13);
                cout<<"\t* Unsuccessful Transaction !!!";
                gotoxy(5,15);
                printf("\t\t    [ Press Any Key to Continue ] ");
                getch();
                return;
            }
            else if(customer == transf_customer)
            {
                message(string("TRANSACTION IS NOT ALLOWED <ERR_CODE::T001>"));
                return;
            }
            else if(customer->current_account.judgment(transf_customer->temp_acc))
            {
                customer->current_account.transfer(amount);
                transf_customer->temp_acc->deposit(amount);
                gotoxy(5,13);
                printf("\t\t       # Successful Transaction !!!");
                generate_transactions(customer->current_account,(char*)"Transfer Sender",(char*)acc_num.c_str(),amount);
                generate_transactions(*(transf_customer->temp_acc),(char*)"Transfer Receiver",(char*)acc_num.c_str(),amount);
                gotoxy(5,15);
                cout<<"\t\t        Current Balance = "<<customer->current_account.Getbalance()<<" $";
            }
            else
            {
                gotoxy(3,10);
                cout<<"This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING TO "<<transf_customer->temp_acc->Getaccount_type();
                gotoxy(5,13);
                cout<<"\t* Unsuccessful Transaction !!!";
            }
            gotoxy(5,17);
            printf("\t\t     [ Press Any Key to Continue ]");
            getch();
            break;
        }
        break;
    case 3:
        if(customer->student_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            type = 0;
            goto TRANSFER;
        }
        else if(customer->student_account.judgment(NULL)==false)
        {
            gotoxy(3,10);
            message(string("This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING"));
            return;
        }
        system("cls");
        title((char*)"CLIENT");
        gotoxy(5,7);
        cout<<"Amount to Transfer ::  ";
        cin>>amount;
        switch(customer->student_account.difference(amount))
        {
        case -1:
        case 0:
            gotoxy(5,13);
            cout<<"\t\t# Insufficient Balance For this Transaction";
            gotoxy(5,15);
            cout<<"\t\t    [ Press Any Key to Continue ]";
            getch();
            break;
        case 1:
            gotoxy(5,9);
            cout<<"Transfer to Acount No. ::  ";
            cin>>acc_num;
            transf_customer = Search_User(head,acc_num,1);
            if(transf_customer==NULL)
            {
                gotoxy(5,10);
                cout<<"The Transferring Account Number '"<<acc_num<<"' Doesn't Exist in BMS!!!";
                gotoxy(5,13);
                cout<<"\t* Unsuccessful Transaction !!!";
                gotoxy(5,15);
                printf("\t\t    [ Press Any Key to Continue ] ");
                getch();
                return;
            }
            else if(customer == transf_customer)
            {
                message(string("TRANSACTION IS NOT ALLOWED <ERR_CODE::T001>"));
                return;
            }
            else if(customer->student_account.judgment(transf_customer->temp_acc))
            {
                customer->student_account.transfer(amount);
                transf_customer->temp_acc->deposit(amount);
                gotoxy(5,13);
                printf("\t\t       # Successful Transaction !!!");
                generate_transactions(customer->student_account,(char*)"Transfer Sender",(char*)acc_num.c_str(),amount);
                generate_transactions(*(transf_customer->temp_acc),(char*)"Transfer Receiver",(char*)acc_num.c_str(),amount);
                gotoxy(5,15);
                cout<<"\t\t        Current Balance = "<<customer->student_account.Getbalance()<<" $";
            }
            else
            {
                gotoxy(3,10);
                cout<<"This Account DOES'NT MEET NECESSARY CONDITIONS FOR TRANSFERRING TO "<<transf_customer->temp_acc->Getaccount_type();
                gotoxy(5,13);
                cout<<"\t* Unsuccessful Transaction !!!";
            }
            gotoxy(5,17);
            printf("\t\t     [ Press Any Key to Continue ]");
            getch();
            break;
        }
        break;
    default:
        message(string("\t\t WRONG CHOICE !!!"));
        goto TRANSFER;
    }
}

void client_interface(client* head)
{
    string in_time;
    string out_time;
    int trial=0;
Start:
    if(trial==3)
        return;
    AUTHENTIF *user = NULL;
    client *customer = NULL;

    user = user_authentif(CLIENT);
    customer = Search_User(head,user->get_password(),3);
    if(!customer)
    {
        message(string("\tW R O N G   P I N "));
        trial++;
        goto Start;
    }
    else
    {
        if(non_redunadancy(head,customer->Getpin_code()))
        {
            int choice = 1;
            system("cls");
            rectangle(5,5,50,7);
            gotoxy(5,5);
            loadBar(3);
            LoginMessage();

            in_time.assign(getTime());

            while(choice != _ERROR)
            {
                choice = getChoice(choice,(char*)"./Menu/client",(char*)"ITEM'S SELECTION MENU");
                switch(choice)
                {
                case 1:
                    balance_check(customer);
                    break;
                case 2:
                    withdraw(customer);
                    saveData(head,2);
                    break;
                case 3:
                    transfer(customer,head);
                    saveData(head,2);
                    break;
                case 4:
                    last_transaction(customer);
                    break;
                case 5:
                    int next_ch;
                    next_ch = 1;
                    while(next_ch != _ERROR)
                    {
                        next_ch = getChoice(next_ch,(char*)"./Menu/client-next",(char*)"ITEM'S SELECTION MENU");
                        switch(next_ch)
                        {
                        case 1:
                            account_information(customer);
                            break;
                        case 2:
                            customer->display_personal_info();
                            break;
                        case 3:
                            if(edit_pincode(customer))
                            {
                                if(non_redunadancy(head,customer->Getpin_code()))
                                    message(string("PIN CODE MODIFIED SUCCESSFULLY :) !!!"));
                                else
                                {
                                    customer->modif_pin((char*)memory_PIN.c_str());
                                    message(string("\tPIN CODE IS UNCHANGED :O !!!"));
                                }
                            }
                            break;
                        case 4:
                            //!--FEEDBACK
                            message(string("UNDER CONSTRUCTION,CONTACT US FOR ASSISTANT"));
                            break;
                        case 5:
                            next_ch = _ERROR;
                            break;
                        default:
                            saveData(head,2);
                            goto END;
                        }
                    }
                    break;
                default:
                    saveData(head,2);
                    goto END;
                }
            }
END:
            LogoutMessage();
            out_time.assign(getTime());
            generate_logIn_activity(customer,(char*)in_time.c_str(),(char*)out_time.c_str(),2);

        }
        else
        {
            message(string("SYSTEM FAILURE RESULTS :( :( PLEASE CONTACT US"));
            error_report(string("SYSTEM FAILURE RESULTS DUE TO REDUNDANCY IN PIN-CODE FOR SEVERAL CUSTOMERS."));
            exit(1);
        }
    }

}

bool non_redunadancy(client* head,char* key)
{
    client *current = NULL;
    int flag = 0;
    current = head;
    while(current)
    {
        if(strcmp(current->Getpin_code(),key)==0)
            flag++;
        current = current->next;
    }
    if(flag==1)
        return true;
    else
        return false;
}

void error_report(string report)
{
    FILE *fp = fopen("errors.txt","a");
    fprintf(fp,"--> %s\n",report.c_str());
    fclose(fp);
}

void last_transaction(client *customer)
{
LAST_TRANS:
    int type;
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     :::     Select Account     :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        if(customer->savings_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto LAST_TRANS;
        }
        view_transactions_of_account(customer->savings_account,3);
        break;
    case 2:
        if(customer->current_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto LAST_TRANS;
        }
        view_transactions_of_account(customer->current_account,3);
        break;
    case 3:
        if(customer->student_account.Getstatus()==false)
        {
            message(string("\t Account IS NOT Activated "));
            goto LAST_TRANS;
        }
        view_transactions_of_account(customer->student_account,3);
        break;
    default:
        message(string("\t\t WRONG CHOICE !!!"));
        goto LAST_TRANS;
    }
}

void account_information(client* customer)
{
ACC_INFO:
    int type;
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     :::     Select Account     :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        customer->savings_account.display_Acc_Info();
        break;
    case 2:
        customer->current_account.display_Acc_Info();
        break;
    case 3:
        customer->student_account.display_Acc_Info();
        break;
    default:
        message(string("\t\t WRONG CHOICE !!!"));
        goto ACC_INFO;
    }
}


bool edit_pincode(client *customer)
{

    string met,c_met;
    system("cls");
    rectangle(15,5,50,10);
    gotoxy(14,5);
    cout<<"\t## E D I T   P I N   C O D E ##";
    gotoxy(16,8);
    cout<<" ENTER NEW PIN CODE  :: ";
    cin>>met;
    gotoxy(16,9);
    cout<<"CONFIRM NEW PIN CODE :: ";
    cin>>c_met;

    if(met == c_met)
    {
        memory_PIN.assign(customer->Getpin_code());
        customer->modif_pin((char*)met.c_str());
        return true;
    }
    else
        message(string("\t  SEQUENCE DOESN'T MATCH :( !!!"));
    return false;
}



void admin_interface(admin* head,client* list)
{
    string in_time;
    string out_time;
    int trial=0;
Start:
    if(trial==3)
        return;
    AUTHENTIF *user = NULL;
    admin *admin_user = NULL;

    user = user_authentif(ADMIN);
    if(user->check_default_credentials())
        goto ADMIN_SECTION;
    admin_user = Search_User(head,user->get_username(),1);

    if(admin_user)
    {

        if(admin_user == Search_User(head,user->get_password(),2))
        {
            if(!strcmp(admin_user->Getcategory(),STAFF))
            {
                staff_interface(admin_user,list);
                return;
            }
            else
            {
ADMIN_SECTION:
                int choice = 1;
                system("cls");
                rectangle(5,5,50,7);
                gotoxy(5,5);
                loadBar(3);
                LoginMessage();

                in_time.assign(getTime());

                while(choice != _ERROR)
                {
                    choice = getChoice(choice,(char*)"./Menu/admin",(char*)"ITEM'S SELECTION MENU");
                    switch(choice)
                    {
                    case 1:
                        display_user(head,list);
                        break;
                    case 2:
                        Create_New_User(head);
                        head = LoadData(head);
                        break;
                    case 3:
                        void* v_head;
                        v_head = Delete_New_User(head,list);
                        if(sizeof(v_head)==sizeof(admin*))
                            head = (admin*) v_head;
                        else if(sizeof(v_head)==sizeof(client*))
                            list = (client*)v_head;
                        else
                            message(string("-->CODING FAILURE IN DELETE_USER(ADMIN,CLIENT)"));
                        saveData(head,2);
                        saveData(list,2);
                        head = LoadData(head);
                        list = LoadData(list);
                        break;
                    case 4:
                        edit_User(head);
                        saveData(head,2);
                        head = LoadData(head);
                        break;
                    case 5:
                        int next_ch;
                        next_ch = 1;
                        while(next_ch != _ERROR)
                        {
                            next_ch = getChoice(next_ch,(char*)"./Menu/admin-next",(char*)"ITEM'S SELECTION MENU");
                            switch(next_ch)
                            {
                            case 1:
                                view_logIn_activity();
                                break;
                            case 2:
                                check_BMS_Wallet(list);
                                break;
                            case 3:
                                //!--FEEDBACK
                                message(string("UNDER CONSTRUCTION,CONTACT US FOR ASSISTANT"));
                                break;
                            case 4:
                                myProfile(admin_user);
                                saveData(head,2);
                                break;
                            case 5:
                                next_ch = _ERROR;
                                saveData(head,2);
                                saveData(list,2);
                                head = LoadData(head);
                                list = LoadData(list);
                                break;
                            default:
                                saveData(head,2);
                                saveData(list,2);
                                goto END;
                            }
                        }
                        break;
                    default:
                        saveData(head,2);
                        saveData(list,2);
                        goto END;
                    }
                }
            }
        }
        else
        {
            message(string("\t:O  W R O N G   P A S S W O R D"));
            trial++;
            goto Start;
        }
    }
    else
    {
        message(string("\tW R O N G   U S E R N A M E  :O"));
        trial++;
        goto Start;
    }

END:
    LogoutMessage();
    out_time.assign(getTime());
    generate_logIn_activity(admin_user,(char*)in_time.c_str(),(char*)out_time.c_str(),1);
}
void staff_interface(admin* staff_member,client* list)
{
    string in_time;
    string out_time;
    int choice = 1;
    system("cls");
    rectangle(5,5,50,7);
    gotoxy(5,5);
    loadBar(3);
    LoginMessage();

    client* customer;
    account temp;
    string acc_key;
    int type;

    in_time.assign(getTime());
    while(choice != _ERROR)
    {
        choice = getChoice(choice,(char*)"./Menu/staff",(char*)"ITEM'S SELECTION MENU");
        switch(choice)
        {
        case 1:
            Add_New(list);
            list = LoadData(list);
            break;
        case 2:
            deposit(list);
            saveData(list,2);
            list = LoadData(list);
            break;
        case 3:
DISP:
            system("cls");
            rectangle(10,5,60,15);
            gotoxy(10,6);
            cout<<"\t     :::    VIEW HISTORY    :::";
            gotoxy(11,7);
            cout<<"------------------------------------------------";
            gotoxy(10,9);
            cout<<"\t   [1] --> ALL TRANSACTIONS IN THE SYSTEM";
            gotoxy(10,11);
            cout<<"\t   [2] --> TRANSACTIONS OF SPECIFIC ACCOUNT";
            gotoxy(10,14);
            cout<<"\t\t  Enter Choice :  ";
            fflush(stdin);
            type = getche()-48;

            switch(type)
            {
            case 1:
                view_all_transactions(2);
                break;
            case 2:
                system("cls");
                rectangle(10,5,60,11);
                gotoxy(10,6);
                cout<<"\t   ::: ENTER ACCOUNT NUMBER :::";
                gotoxy(11,7);
                cout<<"------------------------------------------------";
                gotoxy(11,9);
                cout<<"     ACCOUNT NUMBER  :::  ";

                cin>>acc_key;

                customer = Search_User(list,acc_key,1);
                if(customer)
                {
                    temp = *(customer->temp_acc);
                    view_transactions_of_account(temp,2);
                }
                else
                {
                    message(string("   ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
                }
                break;
            default:
                goto DISP;
            }
            break;
        case 4:
            system("cls");
            rectangle(10,5,60,11);
            gotoxy(10,6);
            cout<<"\t       ::: SEARCH ACCOUNT :::";
            gotoxy(11,7);
            cout<<"------------------------------------------------";
            gotoxy(11,9);
            cout<<"     ACCOUNT NUMBER  :::  ";
            cin>>acc_key;
            customer = Search_User(list,acc_key,1);
            if(customer)
            {
                message(string("ACCOUNT SUCCESSFULLY FOUND :D !!!"));
                customer->temp_acc->display_Acc_Info();
            }
            else
            {
                message(string("   ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
            }
            break;
        case 5:
            int next_ch;
            next_ch = 1;
            while(next_ch != _ERROR)
            {
                next_ch = getChoice(next_ch,(char*)"./Menu/staff-next",(char*)"ITEM'S SELECTION MENU");
                switch(next_ch)
                {
                case 1:
                    Activate_or_Block_Account(list);
                    saveData(list,2);
                    break;
                case 2:
                    reset_pincode(list);
                    saveData(list,2);
                    break;
                case 3:
                    myProfile(staff_member);
                    break;
                case 4:
                    //!--FEEDBACK
                    message(string("UNDER CONSTRUCTION,CONTACT US FOR ASSISTANT"));
                    break;
                case 5:
                    next_ch = _ERROR;
                    break;
                default:
                    saveData(list,2);
                    goto END;
                }
            }
            break;
        default:
            saveData(list,2);
            goto END;
        }
    }
END:
    LogoutMessage();
    out_time.assign(getTime());
    generate_logIn_activity(staff_member,(char*)in_time.c_str(),(char*)out_time.c_str(),1);
}


void display_user(client* list)
{
    system("cls");
    rectangle(0,0,70,20);
    gotoxy(1,1);
    cout<<"=========================DISPLAY-CLIENTS============================";
    gotoxy(1,2);
    cout<<"--------------------------------------------------------------------";
    gotoxy(1,3);
    cout<<"  CLIENT-ID            |               ACTIVE ACCOUNT";
    gotoxy(1,4);
    cout<<"-----------------------|--------------------------------------------";
    if(list==NULL)
    {
        gotoxy(1,8);
        cout<<"\t\t\t### EMPTY LIST ###";
        gotoxy(1,21);
        cout<<"\t\t     [ Press Any Key to return ]";
        getch();
        return;
    }
    int i=0;
    client* current = NULL;
    current = list;
    while(current)
    {
        gotoxy(4,5+i);
        cout<<current->Getclient_ID()<<"            |   \t";
        if(current->current_account.Getstatus())
            cout<<"CUR\t";
        else if(current->savings_account.Getstatus())
            cout<<"SAV\t";
        else if(current->student_account.Getstatus())
            cout<<"STU";
        cout<<endl;
        //cout<<"--------------------------------------------------------------------";
        if(i==10)
        {
            gotoxy(1,19);
            cout<<"\t\t [ Press Any Key to view more or Esc to return ]";
            if(getch()==27)
                return;
            system("cls");
            rectangle(0,0,70,20);
            gotoxy(1,1);
            cout<<"=========================DISPLAY-CLIENTS============================";
            gotoxy(1,2);
            cout<<"--------------------------------------------------------------------";
            gotoxy(1,3);
            cout<<"  CLIENT-ID                           ACTIVE ACCOUNT";
            gotoxy(1,4);
            cout<<"--------------------------------------------------------------------";
            i=0;
        }
        i++;
        current = current->next;
    }
    gotoxy(1,19);
    cout<<"\t\t\t### END OF LIST ###";
    gotoxy(1,21);
    cout<<"\t\t     [ Press Any Key to return ]";
    getch();
}
void display_user(admin* head)
{
    system("cls");
    rectangle(0,0,70,20);
    gotoxy(1,1);
    cout<<"=========================DISPLAY-CLIENTS============================";
    gotoxy(1,2);
    cout<<"--------------------------------------------------------------------";
    gotoxy(1,3);
    cout<<"    USER-ID      |           CREATED           |    FUNCTION";
    gotoxy(1,4);
    cout<<"-----------------|-----------------------------|--------------------";



    if(head==NULL)
    {
        gotoxy(1,8);
        cout<<"\t\t\t### EMPTY LIST ###";
        gotoxy(1,21);
        cout<<"\t\t     [ Press Any Key to return ]";
        getch();
        return;
    }
    int i=0;
    admin* current = NULL;
    current = head;
    while(current)
    {
        gotoxy(4,5+i);
        cout<<current->Getuser_ID()<<"    |   ";
        cout<<current->Getcreated_date();
        gotoxy(48,5+i);
        cout<<"| "<<current->Getfunctionality();
        //cout<<"--------------------------------------------------------------------";
        if(i==10)
        {
            gotoxy(1,19);
            cout<<"\t\t [ Press Any Key to view more or Esc to return ]";
            if(getch()==27)
                return;
            system("cls");
            rectangle(0,0,70,20);
            gotoxy(1,1);
            cout<<"=========================DISPLAY-CLIENTS============================";
            gotoxy(1,2);
            cout<<"--------------------------------------------------------------------";
            gotoxy(1,3);
            cout<<"  CLIENT-ID                           ACTIVE ACCOUNT";
            gotoxy(1,4);
            cout<<"--------------------------------------------------------------------";
            i=0;
        }
        i++;
        current = current->next;
    }
    gotoxy(1,19);
    cout<<"\t\t\t### END OF LIST ###";
    gotoxy(1,21);
    cout<<"\t\t     [ Press Any Key to return ]";
    getch();
}

void display_user(admin* head,client* list)
{
    system("cls");
    rectangle(10,5,60,15);
    gotoxy(10,6);
    cout<<"\t         ::: DISPLAY USERS :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [A/S] --> 'A' or 'S' for Bank Members";
    gotoxy(10,11);
    cout<<"\t   [C] --> 'C' for Bank Client's Users";
    gotoxy(10,14);
    cout<<"\t\t  Answer :  ";
    int type;
    type = getche();
    if(type=='A' || type=='a' || type=='S' || type=='s' )
    {
        display_user(head);
    }
    else if(type=='C' || type=='c')
    {
        display_user(list);
    }
    else if(type==27)
        return;
    else
        display_user(head,list);
}

void* Delete_New_User(admin* head,client* list)
{
    system("cls");
    rectangle(10,5,60,15);
    gotoxy(10,6);
    cout<<"\t         ::: DELETE USERS :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [A/S] --> 'A' or 'S' for Bank Members";
    gotoxy(10,11);
    cout<<"\t   [C] --> 'C' for Bank Client's Users";
    gotoxy(10,14);
    cout<<"\t\t  Answer :  ";
    int type;
    type = getche();
    if(type=='A' || type=='a' || type=='S' || type=='s' )
    {
        return Delete_New_User(head);
    }
    else if(type=='C' || type=='c')
    {
ANS:
        system("cls");
        rectangle(10,5,60,15);
        gotoxy(10,6);
        cout<<"\t     ::: DELETE CLIENT | ACCOUNT :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(10,9);
        cout<<"\t   [A] --> 'A' for Account of a Client";
        gotoxy(10,11);
        cout<<"\t   [C] --> 'C' for the Client Entirely";
        gotoxy(10,14);
        cout<<"\t\t  Answer :  ";
        int ans;
        ans = getche();
        if(ans=='A'||ans=='a')
        {
            return Delete_New_User(list, 1);
        }
        else if(ans=='C'||ans=='c')
        {
            return Delete_New_User(list, 2);
        }
        else
        {
            goto ANS;
        }
    }
    else if(type==27)
        return NULL;
    else
    {
        return Delete_New_User(head,list);
    }
    return NULL;
}

void edit_User(admin* head)
{
EDIT:
    system("cls");
    rectangle(10,5,60,11);
    gotoxy(10,6);
    cout<<"\t      ::: ENTER USER-ID :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"          USER-ID   :::  ";
    string id;
    fflush(stdin);
    cin>>id;;
    admin *temp_user = Search_User(head,id,3);
    string func,categ,passowrd;
    if(temp_user==NULL)
    {
        message(string("  USER DOESN'T NOT EXIST IN THE SYSTEM !!!"));
        return;
    }
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t   ::: EDIT '"<<id<<"' CREDENTIALS :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Edit Functionality";
    gotoxy(10,11);
    cout<<"\t   [2] --> Edit Category";
    gotoxy(10,13);
    cout<<"\t   [3] --> Reset Password";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(10,6);
        cout<<"\t      ::: NEW FUNCTION :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(11,9);
        cout<<"          FUNCTION   :::  ";
        fflush(stdin);
        cin>>func;
        if(!strcmp(temp_user->Getfunctionality(),func.c_str()))
        {
            message(string("\tFUNCTION IN BANK STAYS THE SAME !!!"));
            break;
        }
        temp_user->Setfunctionality((char*)func.c_str());
        message(string("@ WELCOME TO NEW FUNCTITON IN B.M.S !!!"));
        break;
    case 2:
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(10,6);
        cout<<"\t      ::: NEW CATEGORY :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(11,9);
        cout<<"          CATEGORY   :::  ";
        fflush(stdin);
        cin>>categ;
        if(!strcmp(temp_user->Getcategory(),categ.c_str()))
        {
            message(string("\tCATEGORY STAYS THE SAME !!!"));
            break;
        }
        temp_user->Setcategory((char*)categ.c_str());
        message(string("@ WELCOME TO  THE NEWLY RECRUTED ADMINISTRATOR!!!"));
        break;
    case 3:
        temp_user->display_user_credentials();
        temp_user->reset_password();
        loadBar(1);
        temp_user->display_user_credentials();
        break;
    default:
        goto EDIT;
    }
}

void view_logIn_activity()
{
    FILE *fptr1=fopen("logIn_Activities.log","r");
    char data[500];
    int line=0;
    system("cls");
    rectangle(0,0,70,20);
    gotoxy(1,1);
    cout<<"=========================Log In Activity============================";
    gotoxy(1,3);
    cout<<"--------------------------------------------------------------------";
    gotoxy(1,4);
    cout<<"  USERNAME       \t     START TIME \t     END TIME";
    gotoxy(1,5);
    cout<<"--------------------------------------------------------------------\n";
    while(fgets(data,450,fptr1))
    {
        cout<<data;
        strcpy(data,"");
        line++;
        if(line==10)
        {
            line=0;
            cout<<"\n\t[ Press Any Key to View More || Esc to Continue ] ";
            if(getch()==27)
                return;
            system("cls");
            rectangle(0,0,70,20);
            gotoxy(1,1);
            cout<<"=========================Log In Activity============================";
            gotoxy(1,3);
            cout<<"--------------------------------------------------------------------";
            gotoxy(1,4);
            cout<<"  USERNAME       \t     START TIME \t     END TIME";
            gotoxy(1,5);
            cout<<"--------------------------------------------------------------------\n";
        }
    }
    cout<<"\n\t\t\t### END OF LIST ###";
    cout<<"\n\n\t\t\t[  Esc to Continue ] ";
    getch();
    fclose(fptr1);
    return;
}
void generate_logIn_activity(void* user,char* start_section,char* end_section,int option)
{
    admin* admin_user = NULL;
    client* customer = NULL;
    FILE *fptr1=fopen("logIn_Activities.log","a");
    switch(option)
    {
    case 1:     //!-- For Administrators && Staffs
        admin_user = (admin*) user;
        if(admin_user)
            fprintf(fptr1,"  %s\t\t %s\t %s",admin_user->Getuser_ID(),start_section,end_section);
        else
            fprintf(fptr1,"  %s\t\t %s\t %s","**BMS-DEV**",start_section,end_section);
        break;
    case 2:     //!-- For Clients
        customer = (client*) user;
        if(customer)
            fprintf(fptr1,"  %s\t\t %s\t %s",customer->Getclient_ID(),start_section,end_section);
        else
            fprintf(fptr1,"  %s\t\t %s\t %s","CUS-#ERROR#",start_section,end_section);
        break;
    }
    fclose(fptr1);
}

void check_BMS_Wallet(client* list)
{
    long double wallet = 0.0;
    client* current = NULL;

    current = list;
    while(current)
    {
        if(current->current_account.Getstatus())
            wallet += current->current_account.Getbalance();
        if(current->savings_account.Getstatus())
            wallet += current->savings_account.Getbalance();
        if(current->student_account.Getstatus())
            wallet += current->student_account.Getbalance();

        current = current->next;
    }

    system("cls");
    title((char*)"ADMIN");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,10);
    cout<<"\t\t   # Current BMS Wallet :::  $"<<wallet<<" USD";
    gotoxy(5,15);
    cout<<"\t\t    [ Press Any Key to Continue ] ";
    getch();
}


void myProfile(admin* user)
{
    if(user==NULL)
    {
        message(string("\tEXPERIMENTIAL USER IN USED !!!"));
        return;
    }
PROFILE:
    int type;
    system("cls");
    rectangle(10,5,60,15);
    gotoxy(10,6);
    cout<<"\t     :::    # MY PROFILE #    :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> PERSONAL INFORMATIONS";
    gotoxy(10,11);
    cout<<"\t   [2] --> USER CREDENTIALS & DETAILS";
    gotoxy(10,14);
    cout<<"\t\t  Enter Choice :  ";
    fflush(stdin);
    type = getche()-48;
    switch(type)
    {
    case 1:
        user->display_personal_info();
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(10,6);
        cout<<"   ::: Do you wish to Edit those Infos ? :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(11,9);
        cout<<"          Yes [Y] or No [N]  :::  ";
        int type;
        type = getche();
        if(type=='Y'||type=='y')
        {
            string name,dob,gender,parent,address,profession,country,phone,email;
PERS:
            system("cls");
            rectangle(0,0,80,25);
            gotoxy(1,1);
            cout<<"\t\t\t ===  EDIT  USER INFOS  ===";
            gotoxy(1,2);
            cout<<"------------------------P-E-R-S-O-N-A-L _ I-N-F-O-S---------------------------";
            fflush(stdin);
            gotoxy(1,4);
            cout<<"\tEnter Client's Name :  ";
            cin>>name;
            gotoxy(1,6);
            cout<<"\tEnter Date of Birth :  ";
            fflush(stdin);
            cin>>dob;
            gotoxy(1,8);
            cout<<"\tEnter M [for Male] && F [for Female] : ";
            fflush(stdin);
            cin>>gender;
            gotoxy(1,10);
            cout<<"\tEnter Father's && Mother's Name : ";
            fflush(stdin);
            cin>>parent;
            gotoxy(1,12);
            cout<<"\tEnter Client's Permanent Address : ";
            fflush(stdin);
            cin>>address;
            gotoxy(1,14);
            cout<<"\tEnter Client's Profession : ";
            fflush(stdin);
            cin>>profession;
            gotoxy(1,16);
            cout<<"\tEnter Client's Country : ";
            cin>>country;
            gotoxy(1,18);
            cout<<"\tEnter Client's Phone Number : ";
            cin>>phone;
            gotoxy(1,20);
            cout<<"\tEnter Client's Email : ";
            cin>>email;

PERS_CONFIRM:
            system("cls");
            rectangle(10,5,75,15);
            gotoxy(10,6);
            cout<<"\t     ::: Do you Agree with the Client Infos ? :::";
            gotoxy(11,7);
            cout<<"---------------------------------------------------------------";
            gotoxy(10,9);
            cout<<"\t   [Y] --> Yes, I agree and confirm the Client Infos";
            gotoxy(10,11);
            cout<<"\t   [N] --> No, I disagree, Let's Restart Infos Section";
            gotoxy(10,14);
            cout<<"\t\t  Answer :  ";
            type = getche();
            if(type=='Y' || type=='y')
                goto GOOD;
            else if(type=='N' || type=='n')
            {
                goto PERS;
            }
            else
                goto PERS_CONFIRM;
GOOD:
            person info(name,dob,phone,country,parent,gender,email,address,profession);
            *user = info;
            process_execution((char*)"MODIFYING & SAVING DATA");
            message(string(" OPERATION SUCCESSFULLY DONE :) !!!!"));
        }
        break;
    case 2:
        user->display_user_credentials();
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(11,6);
        cout<<" ::: Do you wish to Edit your Credential's ? :::";
        gotoxy(11,7);
        cout<<"------------------------------------------------";
        gotoxy(11,9);
        cout<<"          Yes [Y] or No [N]  :::  ";
        fflush(stdin);
        type = getche();
        if(type=='Y'||type=='y')
        {
            string username,password;
            system("cls");
            rectangle(10,5,60,15);
            gotoxy(1,16);
            cout<<"[Note:: Just Fill Those Credentials you wish to change and Fill '#' for those you wish to keep]";
            gotoxy(10,6);
            cout<<"\t      ::: CREDENTIALS :::";
            gotoxy(11,7);
            cout<<"------------------------------------------------";
            gotoxy(11,9);
            cout<<"         USERNAME :::  ";
            fflush(stdin);
            cin>>username;

            gotoxy(11,12);
            cout<<"            PIN CODE  :::  ";
            cin>>password;

            if(username=="#" && password=="#")
            {
                message(string(" USER CREDENTIAL STAYS UNCHANGED !!!"));
                break;
            }
            else if(username!="#" && password!="#")
            {
                user->Setusername((char*)username.c_str());
                user->Setpassword((char*)password.c_str());
            }
            else
            {
                if(username!="#")
                    user->Setusername((char*)username.c_str());
                else if(password!="#")
                    user->Setpassword((char*)password.c_str());
            }

            process_execution((char*)"MODIFYING & SAVING DATA");
            message(string(" OPERATION SUCCESSFULLY DONE :) !!!!"));
        }
        break;
    default:
        goto PROFILE;
    }
}


void deposit(client* list)
{
    long double amount;
    string depos_acc_num;
    system("cls");
    title((char*)"STAFF");
    gotoxy(5,10);
    printf("\t\t   # Amount to Deposit :::  ");
    cin>>amount;
    gotoxy(5,13);
    printf("\t\t   # Account Number (XXX-XXXX-XXX) ::  ");
    cin>>depos_acc_num;

    client* temp_client = Search_User(list,depos_acc_num,1);
    if(temp_client == NULL)
    {
        message(string("  ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
        message(string("\tOPERATION HAS BEEN CANCELLED !!!"));
        return;
    }
    else
    {
        temp_client->temp_acc->deposit(amount);
        gotoxy(5,13);
        cout<<"\t\t       # Successful Transaction !!!";
        generate_transactions(*(temp_client->temp_acc),(char*)"Deposit",NULL,amount);
        gotoxy(5,15);
        cout<<"\t\t        Current Balance = "<<temp_client->temp_acc->Getbalance()<<" $";
        gotoxy(5,17);
        cout<<"\t\t     [ Press Any Key to Continue ]";
        getch();
    }
}

void reset_pincode(client* list)
{
    system("cls");
    rectangle(10,5,60,11);
    gotoxy(10,6);
    cout<<"\t   ::: ENTER ACCOUNT NUMBER :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"     ACCOUNT NUMBER  :::  ";
    string acc_key;
    cin>>acc_key;
    client* customer = NULL;
    customer = Search_User(list,acc_key,1);
    if(customer==NULL)
    {
        message(string("ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
        return;
    }
    customer->Reset_PinCode();
    string met1("\t     PIN-CODE :::  ");
    string met2;
    met2.assign(customer->Getpin_code());
    message(met1+met2);
}

void Activate_or_Block_Account(client* list)
{
    system("cls");
    rectangle(10,5,60,11);
    gotoxy(10,6);
    cout<<"\t   ::: ENTER ACCOUNT NUMBER :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"     ACCOUNT NUMBER  :::  ";
    string acc_key;
    cin>>acc_key;
    client* customer;
    customer = Search_User(list,acc_key,1);
    if(customer == NULL)
    {
        message(string("ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
        return;
    }
ANSWER1:
    message(string("\tACCOUNT SUCCESSFULLY FOUND !!!"));
    customer->temp_acc->display_Acc_Info();
    system("cls");
    rectangle(10,5,60,11);
    gotoxy(10,6);
    cout<<"\t      ::: Activate or Block this Account ? :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"          Activate [A] or Block [B]  :::  ";
    int type;
    type = getche();

    if(type=='A'||type=='a')
    {
        if(customer->temp_acc->Getstatus())
            message(string("  ACCOUNT IS ALREADY ACTIVATED !!!"));
        else
            customer->temp_acc->Setstatus(true);
    }
    else if(type=='B'||type=='b')
    {
        if(customer->temp_acc->Getstatus())
            customer->temp_acc->disable_account(2);

        else
            message(string("  ACCOUNT IS ALREADY BLOCKED !!!"));
    }
    else if(type==27)
        message(string(" OPERATION HAS BEEN CANCELLED !!!"));
    else
        goto ANSWER1;
}

void Create_New_Account(client* list)
{
    int type;
    system("cls");
    rectangle(10,5,60,11);
    gotoxy(10,6);
    cout<<"\t::: ENTER AN EXIISTING ACCOUNT NUMBER :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(11,9);
    cout<<"     ACCOUNT NUMBER  :::  ";
    string acc_key;
    cin>>acc_key;
    client* customer = Search_User(list,acc_key,1);
    if(customer)
        message(string("ACCOUNT SUCCESSFULLY FOUND !!!"));
    else
    {
        message(string("ACCOUNT DOESN'T EXIST IN SYSTEM !!!"));
        return;
    }

    account tem_acc;
ACC_:
    system("cls");
    rectangle(10,5,60,18);
    gotoxy(10,6);
    cout<<"\t     ::: Select Account Type :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> Savings Account (SAV)";
    gotoxy(10,11);
    cout<<"\t   [2] --> Current Account (CUR)";
    gotoxy(10,13);
    cout<<"\t   [3] --> Student Account (STU)";
    gotoxy(10,16);
    cout<<"\t\t  Enter Selection :  ";
    fflush(stdin);
    cin>>type;
    switch(type)
    {
    case 1:
        tem_acc.Setaccount_type((char*)"SAV");
        break;
    case 2:
        tem_acc.Setaccount_type((char*)"CUR");
        break;
    case 3:
        tem_acc.Setaccount_type((char*)"STU");
        break;
    default:
        goto ACC_;
    }

    tem_acc.Activate_Account();

    customer->add_new_account(tem_acc);
    process_execution((char*)"GENERATING && ACTIVATION");

    message(string(" :D  ACCOUNT SUCCESSFULLY CREATED !!!"));
    increase_total_clients();
    saveData(list,2);
}
void Add_New(client* list)
{
    int type;
ADD:
    system("cls");
    rectangle(10,5,60,15);
    gotoxy(10,6);
    cout<<"\t     :::    ADD NEW CLIENT | ACCOUNT    :::";
    gotoxy(11,7);
    cout<<"------------------------------------------------";
    gotoxy(10,9);
    cout<<"\t   [1] --> CREATE NEW CLIENT IN SYSTEM";
    gotoxy(10,11);
    cout<<"\t   [2] --> CREATE NEW ACCOUNT (EXISTING CLIENT)";
    gotoxy(10,14);
    cout<<"\t\t  Enter Choice :  ";
    fflush(stdin);
    type = getche()-48;
    switch(type)
    {
    case 1:
        Create_New_User(list);
        break;
    case 2:
        Create_New_Account(list);
        break;
    default:
        goto ADD;
    }
}


