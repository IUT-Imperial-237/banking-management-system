#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;
//to do update the file contain after eacu modification

void write(CLIENT * head)
{
    CLIENT *current;
    current=new CLIENT;
    FILE*fp;
    fp=fopen("client.txt","wb");
    current=head;
    if(fp==NULL)
    {
        cout<<" error when opening the file !!!";
    }
    while(current)
    {
        fwrite(current,sizeof (CLIENT),1,fp);
        current=current->next;
    }
    fclose (fp);

}
void write(STAFF * head)
{
    STAFF *current;
    current=new STAFF;
    FILE*fp;
    fp=fopen("staff.txt","wb");
    current=head;
    if(fp==NULL)
    {
        cout<<" error when opening the file !!!";
    }
    while(current)
    {
        fwrite(current,sizeof (STAFF),1,fp);
        current=current->next;
    }

    fclose (fp);
}

void write(ADMIN * head)
{
    ADMIN *current;
    current=new ADMIN;
    FILE*fp;
    fp=fopen("admin.txt","wb");
    current=head;
    if(fp==NULL)
    {
        cout<<" error when opening the file !!!";
    }
    while(current)
    {
        fwrite(current,sizeof (ADMIN),1,fp);
        current=current->next;
    }

    fclose (fp);
}

void write(TRANSACTION * head)
{
    TRANSACTION *current;
    current=new TRANSACTION;
    FILE*fp;
    fp=fopen("transaction.txt","wb");
    current=head;
    if(fp==NULL)
    {
        cout<<" error when opening the file !!!";
    }
    while(current)
    {
        fwrite(current,sizeof (TRANSACTION),1,fp);
        current=current->next;
    }

    fclose (fp);
}
