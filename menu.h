
#ifndef __MENU_HEADER_
#define __MENU_HEADER_
#define _ERROR 0
#define SUCCESS 1
#define ADMIN "A"
#define CLIENT "C"
#define STAFF "S"
#define TEST "BMS-DEV"
#include <iostream>

using namespace std;

/*
typedef struct _ID_AUTHENTIF
{
    char username[50];
    char password[50];
}AUTHENTIF;
*/

class AUTHENTIF
{
    string username; ///**** if user = C||c then username = client || CLIENT, else Otherwise;
    string password;
    string usertype; ///*** C||c = Client, S|s = Staff, A|a = Admin;
public:
    AUTHENTIF() { }

    string get_username() { return username; }
    void set_username(string val) { username = val; }

    string get_password() { return password; }
    void set_password(string val) { password = val; }

    string get_usertype() { return usertype; }
    void set_usertype(string val) { usertype = val; }

};


void welcome_menus(string menu);
void loadBar(int option);
void welcome_message();
void endMessage();
void LoginMessage();
void LogoutMessage();
void print_progress(size_t count, size_t max);
void my_wait(char *howlong);
void Sever_Connection(size_t count, size_t max,char *name);
char *getTime();
void title(char *usertype);
void rectangle(int x,int y,int l,int b);
void gotoxy (int x, int y);
int getChoice(int choice,char *filename,char *label);
void process_execution(char *task);
AUTHENTIF *user_authentif(string option);
void message(string text);

#endif // __MENU_HEADER_
