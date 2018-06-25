

#include "menu.h"


bool AUTHENTIF::check_default_credentials()
{
    if(this->username == TEST && this->password == "123")
        return true;
    else
        return false;
}


void welcome_menus(string menu)
{
    if(menu == "BMS" || menu == "bms")
    {
        system("cls");
        printf("\n\n\n");
        cout << "     ===============================================\n     ||                                           ||" << endl;
        cout << "     ||\t*****      *             *   ************ ||           " << endl;
        cout << "     ||\t*******    **           **   ************ ||" << endl;
        cout << "     ||\t**   ***   ***         ***   ***      *** ||" << endl;
        cout << "     ||\t**   ***   ****       ****   ***      *** ||" << endl;
        cout << "     ||\t**   ***   *****     *****   ***      *** ||" << endl;
        cout << "     ||\t**  ***    *** **   ** ***   ***          ||" << endl;
        cout << "     ||\t** **      ***  ** **  ***   ************ ||" << endl;
        cout << "     ||\t****       ***   ***   ***   ************ ||" << endl;
        cout << "     ||\t** **      ***         ***            *** ||" << endl;
        cout << "     ||\t**  ***    ***         ***   ***      *** ||" << endl;
        cout << "     ||\t**   ***   ***         ***   ***      *** ||" << endl;
        cout << "     ||\t**   ***   ***         ***   ***      *** ||" << endl;
        cout << "     ||\t**   ***   ***         ***   ***      *** ||" << endl;
        cout << "     ||\t*******    ***         ***   ************ ||" << endl;
        cout << "     ||\t*****      ***         ***   ************ ||" << endl;
        cout << "     ||                                           ||\n     ===============================================" << endl;
        //cout << "" << endl;
        //my_wait("longer");
    }
}

void loadBar(int option)
{
    size_t num_secs = 1, max_secs = 20;

    switch(option)
    {
    case 1:
        printf("\n________________________________________________________________________________\n");
        for (int i=1; i<=10000; i++)
        {
            printf("\r\t\t      I N   P R O C E S S   %d %c",i/100,'%');
        }
        printf("\n________________________________________________________________________________\n\n");
        break;
    case 2:
        printf("%s\n", "");
        print_progress(0, max_secs);
        for (; num_secs <= max_secs; ++num_secs)
        {
            my_wait((char*)"short");
            print_progress(num_secs, max_secs);
        }
        break;
    case 3:
        printf("%s\n", "");
        Sever_Connection(0,5,(char*)"Loading Data");
        for (; num_secs <= 5; ++num_secs)
        {
            my_wait((char*)"medium");
            Sever_Connection(num_secs, 5,(char*)"Loading Data");
        }
        break;
    case 4:
        printf("%s\n", "");
        Sever_Connection(0,5,(char*)"Connecting Server");
        for (; num_secs <= 5; ++num_secs)
        {
            my_wait((char*)"short");
            Sever_Connection(num_secs, 5,(char*)"Connecting Server");
        }
        break;
    }

}
void Sever_Connection(size_t count, size_t max,char *name)
{
    const char prefix[] = "\r\t\t %s ";
    const char suffix[] = " ";
    const size_t prefix_length = sizeof(prefix) - 1;
    const size_t suffix_length = sizeof(suffix) - 1;
    char *buffer = (char*)calloc(max + prefix_length + suffix_length + 1, 1); // +1 for \0
    size_t i = 0;

    strcpy(buffer, prefix);
    for (; i < max; ++i)
    {
        buffer[prefix_length + i] = i < count ? 178 : ' ';
    }

    strcpy(&buffer[prefix_length + i], suffix);
    printf(buffer,name);
    fflush(stdout);
    free(buffer);
}
void my_wait(char *howlong)
{
    if(strcmp(howlong,"short")==0)
        Sleep(100);
    else if(strcmp(howlong,"medium")==0)
        Sleep(300);
    else if(strcmp(howlong,"long")==0)
        Sleep(500);
    else if(strcmp(howlong,"longer")==0)
        Sleep(1000);
    else if(strcmp(howlong,"extra long")==0)
        Sleep(1500);
}

void print_progress(size_t count, size_t max)
{
    const char prefix[] = "Progress: [";
    const char suffix[] = "]";
    const size_t prefix_length = sizeof(prefix) - 1;
    const size_t suffix_length = sizeof(suffix) - 1;
    char *buffer = (char*)calloc(max + prefix_length + suffix_length + 1, 1); // +1 for \0
    size_t i = 0;

    strcpy(buffer, prefix);
    for (; i < max; ++i)
    {
        buffer[prefix_length + i] = i < count ? '#' : ' ';
    }

    strcpy(&buffer[prefix_length + i], suffix);
    //printf("\b%c[\r%s\n", 27, buffer);
    printf(" %s",buffer);
    fflush(stdout);
    free(buffer);
}

void welcome_message()
{
    /*
    Welcome Menu Function. It displays the first preview of this project!!!
    */
    system("cls");
    rectangle(0,0,80,27);
    gotoxy(1,1);
    printf("\t                       \n\n\n");
    printf("\t                       \n\t");
    printf("                         W E L C O M E       \n\n\t");
    printf("                          T O  T H E        \n\n\t");
    printf("                     BANK MANAGEMENT SYSTEM      \n\n\t");
    printf("                         * * B M S * *      \n");
    gotoxy(1,13);
    printf("______________________________________________________________________________");
    printf("\n\t    Designed By : Fopa Y. Amadou Olabi \t    [ ID : 154446 ]\n");
    printf("\n\t                  Aly AbdelKader Gelany\t    [ID : 160040021]\n");
    printf("\n\t                  Abdel Karim Moukambou\t    [ID : 160040022]\n");
    printf("\n\t                  Tani Barkat       \t    [ID : 160041083]\n");
    printf("\n\t                  Anasse Mohamed \t    [ID : 160041083]\n");
    gotoxy(1,23);
    printf("______________________________________________________________________________\n");
    printf("\n\t\t          [ Press Any Key to Continue ]");
    getch();
    //my_wait("longer");
    //getch();
}
void endMessage()
{
    /*
       End Message Function. It displays the last preview of this project!!!
    */
    system("cls");
    rectangle(0,0,80,27);
    gotoxy(1,1);
    printf("\t                       \n\t\t\t\t* * B M S * *\n\n");
    printf("\t                       \n");
    gotoxy(1,4);
    printf("______________________________________________________________________________\n\n\t");
    printf("                      T H A N K   Y O U       \n\t");
    printf("                       F O R  U S I N G        \n\n\t");
    printf("                    BANK MANAGEMENT SYSTEM      \n\t");
    printf("                                 \n");
    gotoxy(1,13);
    printf("______________________________________________________________________________");
    printf("\n\t    Designed By : Fopa Y. Amadou Olabi \t    [ ID : 154446 ]\n");
    printf("\n\t                  Aly AbdelKader Gelany\t    [ID : 160040021]\n");
    printf("\n\t                  Abdel Karim Moukambou\t    [ID : 160040022]\n");
    printf("\n\t                  Tani Barkat       \t    [ID : 160041083]\n");
    printf("\n\t                  Anasse Mohamed \t    [ID : 160041083]\n");
    gotoxy(1,23);
    printf("______________________________________________________________________________\n");
    printf("\n\t\t          [ Press Any Key to Continue ]");
    getch();
    printf("\n\n********************************************************************************\n\n");
}

void LoginMessage()
{
    system("cls");
    printf("\n\n\t\t\t====== LogIn ======\n");
    //loadBar();
    printf("\n\n\t\t\t___________________\n\t\t\t| User in Section |\n\t\t\t-------------------\n");
    //Sleep(500);
    my_wait((char*)"medium");
}
void LogoutMessage()
{
    system("cls");
    printf("\n\n\t\t\t====== Log Out ======\n");
    //loadBar();
    printf("\n\n\t\t\t ___________________\n\t\t\t |   Section Over  |\n\t\t\t -------------------\n");
    //Sleep(1000);
    my_wait((char*)"long");
}
char *getTime()
{
    time_t curtime;
    time(&curtime);
    return ctime(&curtime);
}
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y);
    printf("%c",201);
    for(i=x+1; i<l-1; i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y);
    printf("%c",187);

    for (m=y+1; m<b; m++)
    {
        gotoxy(x,m);
        for(i=x; i<l; i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m);
                printf("%c",186);
            }

        }

    }

    gotoxy(x,m);
    printf("%c",200);
    for(i=x+1; i<l-1; i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m);
    printf("%c",188);
}


void title(char *usertype)
{
    int i;

    system("cls");

    rectangle(0,0,80,23);
    gotoxy(25,1);
    printf("Banking Management System");
    gotoxy(1,2);
    printf("------------------------------------------------------------------------------");
    gotoxy(5,3);
    printf("Current User : %s",usertype);
    printf("\t\tDate : %s",getTime());

    gotoxy(1,5);
    for(i=0; i<78; i++) printf("%c",196);

}


COORD coord = {0, 0};

void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; ///* X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getChoice(int choice,char *filename,char *label)
{
    ///This is the function to permit us to use the arrows to make a selection!!!

    char ch=10;
    char ar1[20][100],ar2[20][100];
    int num_choice;
    int i,j;
    FILE *fp = fopen(filename,"r");
    fscanf(fp,"%d\n",&num_choice);
    for(i=0; i<num_choice; i++)
        fgets(ar1[i],70,fp);
    for(i=0; i<num_choice; i++)
        fgets(ar2[i],70,fp);

    fclose(fp);

    while(ch!=13)
    {
        system("cls");
        rectangle(0,0,75,22);
        gotoxy(1,1);
        printf("\n\t\t\t::::: %s :::::\n",label);

        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = num_choice;
        else if(choice>num_choice)
            choice = 1;
        if(ch==27)
            return _ERROR;///Exit the menu to end program...

        for(i=1,j=0; i<=num_choice; i++,j++)
        {
            if(choice==i)
            {
                printf("\n\n\t\t     -->\t%s",ar2[j]);
            }
            else printf("\n\n\t\t\t\t%s",ar1[j]);
        }
        printf("\n\n\n\n\t[ Use UP and DOWN to Select Option or Esc to Exit Program ]");
        fflush(stdin);
        ch = getch();
    }
    return choice;
}

void process_execution(char *task)
{
    int time;
    system("cls");
    rectangle(10,5,60,10);
    gotoxy(10,6);
    printf("\t      ::: %s :::",task);
    gotoxy(11,7);
    printf("------------------------------------------------");
    gotoxy(11,9);
    printf("       ");
    print_progress(0, 20);
    for (time=1; time <= 20; ++time)
    {
        my_wait((char*)"short");
        gotoxy(11,9);
        printf("       ");
        print_progress(time, 20);
    }
    return;
}

AUTHENTIF *user_authentif(string option)///*GUI of Authentication {1 = Client and 2 = Admins or Staffs}
{
    AUTHENTIF *user;
    user = new AUTHENTIF;
    if(option==ADMIN || option==STAFF) ///*ADMIN && STAFF ID
    {
        char username[50];
        char password[50];
        char ch;
        int i=0;
        system("cls");
        rectangle(10,5,60,15);
        gotoxy(10,6);
        printf("\t      ::: AUTHENTICATION :::");
        gotoxy(11,7);
        printf("------------------------------------------------");
        gotoxy(11,9);
        printf("         USERNAME :::  ");
        fflush(stdin);
        cin>>username;
        gotoxy(11,12);
        printf("            PIN CODE  :::  ");
        while((ch=getch())!='\r')
        {
            if(ch==8)
            {
                if(i)
                {
                    printf("%c",ch);
                    printf(" ");
                    printf("%c",ch);
                    i--;
                }
            }
            else
            {
                printf("*");
                password[i]=ch;
                i++;
            }

        }
        password[i]='\0';
        i=0;
        user->set_username(username);
        user->set_password(password);
        user->set_usertype(option);

        return user;
    }

    else if(option==CLIENT) ///*CLIENT
    {
        char password[50]="";
        char ch;
        int i=0;
        system("cls");
        rectangle(10,5,60,11);
        gotoxy(10,6);
        printf("\t      ::: AUTHENTICATION :::");
        gotoxy(11,7);
        printf("------------------------------------------------");
        gotoxy(11,9);
        printf("          PIN CODE  :::  ");
        while((ch=getch())!='\r')
        {
            if(ch==8)
            {
                if(i)
                {
                    printf("%c",ch);
                    printf(" ");
                    printf("%c",ch);
                    i--;
                }
            }
            else
            {
                printf("*");
                password[i]=ch;
                i++;
            }

        }
        password[i]='\0';
        i=0;
        user->set_usertype(CLIENT);
        user->set_username((char*)CLIENT);
        user->set_password(password);
        return user;
    }
    else
    {
        ///**** TEST CREDENTIALS FOR THIS PROJECT

        user->set_username((char*)TEST);
        user->set_password((char*)"123");
        user->set_usertype(TEST);
        return user;
    }
    //getch();
    return NULL;
}
void message(string text)
{
    system("cls");
    rectangle(15,5,60,10);
    gotoxy(16,8);
    cout<<text;
    getch();
    return;
}

