#ifndef __MECHANISM_HEADER_
#define __MECHANISM_HEADER_

#define _ERROR 0
#define SUCCESS 1

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <conio.h>

#include "client.h"
#include "admin.h"
#include "menu.h"
#include "transaction.h"

using namespace std;

void Create_New_User(client* );
void Create_New_User(admin* );

client* Delete_New_User(client* ,int);
admin* Delete_New_User(admin* );
void* Delete_New_User(admin* ,client*);

client* Search_User(client* ,string ,int );
admin* Search_User(admin* ,string ,int );

transaction* read_all_transactions();
void generate_transactions(account , char* ,char* , long double );
void view_transactions_of_account(account ,int);
void view_all_transactions(int );
void last_transaction(client*);


void saveData(client *,int);
void saveData(admin *,int);

client* LoadData(client*);
admin* LoadData(admin*);

void balance_check(client*);
void withdraw(client*, char* );
void withdraw(client*);
void transfer(client*, client*);

void client_interface(client*);
void error_report(string );
bool non_redunadancy(client* ,char* );
bool edit_pincode(client*);
void reset_pincode(client*);

void account_information(client*);

void display_user(client*);
void display_user(admin*);
void display_user(admin*,client*);

void edit_User(admin*);

void admin_interface(admin*,client*);
void staff_interface(admin*,client*);

void view_logIn_activity();
void generate_logIn_activity(void* ,char*,char*,int );

void check_BMS_Wallet(client*);
void deposit(client*);
void myProfile(admin*);

void Activate_or_Block_Account(client*);
void Create_New_Account(client*);
void Add_New(client*);

#endif // __MECHANISM_HEADER_
