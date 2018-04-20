#pragma once
#include "classes.h"//before to use this you need to include the header file containing all the classes used in the projet

//this is an overloaded function call load that take inputs from differents file to form a linked lis(it return the node to the first element

class CLIENT *load(class CLIENT *head)//creating the linked list from clientfile
{
    int i=0;
    class CLIENT *current,*new_elt[1000];

    current =new CLIENT;
    FILE*fp;
    fp=fopen("client.txt","rb");
    new_elt[i] =new CLIENT;

    while(fread(new_elt[i],sizeof (class CLIENT),1,fp)==1)
    {
        new_elt[i]->next=NULL;
        if(head==NULL)
        {
            head = new_elt[i];

        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }

            current->next = new_elt[i];
        }
        i=i+1;
        new_elt[i] =new CLIENT;

    }

    fclose(fp);
    return head;

}


class STAFF *load(class STAFF *head)//creating the linked list from staff file
{
    int i=0;
    class STAFF *current,*new_elt[1000];

    current =new STAFF;
    FILE*fp;
    fp=fopen("staff.txt","rb");
    new_elt[i] =new STAFF;

    while(fread(new_elt[i],sizeof (class STAFF),1,fp)==1)
    {
        new_elt[i]->next=NULL;
        if(head==NULL)
        {
            head = new_elt[i];

        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }

            current->next = new_elt[i];
        }
        i=i+1;
        new_elt[i] =new STAFF;

    }

    fclose(fp);
    return head;

}

class ADMIN *load(class ADMIN *head)//creating the linked list from admin file
{
    int i=0;
    class ADMIN *current,*new_elt[1000];

    current =new ADMIN;
    FILE*fp;
    fp=fopen("admin.txt","rb");
    new_elt[i] =new ADMIN;

    while(fread(new_elt[i],sizeof (class ADMIN),1,fp)==1)
    {
        new_elt[i]->next=NULL;
        if(head==NULL)
        {
            head = new_elt[i];

        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }

            current->next = new_elt[i];
        }
        i=i+1;
        new_elt[i] =new ADMIN;

    }

    fclose(fp);
    return head;

}

class TRANSACTION *load(class TRANSACTION *head)//creating the linked list from transaction file
{
    int i=0;
    class TRANSACTION *current,*new_elt[1000];

    current =new TRANSACTION;
    FILE*fp;
    fp=fopen("transaction.txt","rb");
    new_elt[i] =new TRANSACTION;

    while(fread(new_elt[i],sizeof (class TRANSACTION),1,fp)==1)
    {
        new_elt[i]->next=NULL;
        if(head==NULL)
        {
            head = new_elt[i];

        }
        else
        {
            current=head;
            while(current->next)
            {
                current = current->next;
            }

            current->next = new_elt[i];
        }
        i=i+1;
        new_elt[i] =new TRANSACTION;

    }

    fclose(fp);
    return head;

}


