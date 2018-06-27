#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "client.h"
#include "admin.h"
#include "menu.h"
#include "mechanism.h"


using namespace std;

int main()
{
    int num = 1;
    admin* head = NULL;
    client* list = NULL;



    welcome_message();
    welcome_menus("BMS");
    gotoxy(20,22);
    loadBar(4);
    my_wait((char*)"short");

    head = LoadData(head);
    list = LoadData(list);


    do
    {
        system("cls");
        rectangle(10,8,70,15);
        gotoxy(11,11);
        cout<<" \t\t[A]   \t\t\t    [C]";
        gotoxy(11,13);
        cout<<"  { ADMINISTRATOR | STAFF }   \t { CLIENT }";
        gotoxy(40,14);
        num = getch();

        switch(num)
        {
        case 'A':
        case 'a':
        case 'S':
        case 's':
            admin_interface(head,list);
            saveData(head,2);
            saveData(list,2);
            head = LoadData(head);
            list = LoadData(list);
            break;
        case 'C':
        case 'c':
            client_interface(list);
            saveData(list,2);
            list = LoadData(list);
            break;
        case 27:
            endMessage();
            break;
        }
    }
    while(num!=27);
    return 0;
}
