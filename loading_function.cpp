
#pragma once
#include "classes.h"//before to use this you need to include the header file containing all the classes used in the projet

//this is an overloaded function call load that take inputs from differents file to form a linked lis(it return the node to the first element

CLIENT *load(CLIENT *head)//creating the linked list from clientfile
{
    CLIENT *current,*new_elt;
    new_elt=new CLIENT;
    FILE*fp;
    fp=fopen("client.txt","rb");


    while(fread(new_elt,sizeof (CLIENT),1,fp)==1)
    {
        new_elt->next=NULL;
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
        }

        new_elt =new CLIENT;

    }

    fclose(fp);
    return head;

}


STAFF*load(STAFF*head)//creating the linked list from clientfile
{
    STAFF*current,*new_elt;
    new_elt=new STAFF;
    FILE*fp;
    fp=fopen("staff.txt","rb");


    while(fread(new_elt,sizeof (STAFF),1,fp)==1)
    {
        new_elt->next=NULL;
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
        }

        new_elt =new STAFF;

    }

    fclose(fp);
    return head;

}
ADMIN *load(ADMIN *head)//creating the linked list from ADMINfile
{
    ADMIN *current,*new_elt;
    new_elt=new ADMIN;
    FILE*fp;
    fp=fopen("admin.txt","rb");


    while(fread(new_elt,sizeof (ADMIN),1,fp)==1)
    {
        new_elt->next=NULL;
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
        }

        new_elt =new ADMIN;

    }

    fclose(fp);
    return head;

}


TRANSACTION *load(TRANSACTION *head)//creating the linked list from TRANSACTIONfile
{
    TRANSACTION *current,*new_elt;
    new_elt=new TRANSACTION;
    FILE*fp;
    fp=fopen("transaction.txt","rb");


    while(fread(new_elt,sizeof (TRANSACTION),1,fp)==1)
    {
        new_elt->next=NULL;
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
        }

        new_elt =new TRANSACTION;

    }

    fclose(fp);
    return head;

}


ACCOUNT *load(ACCOUNT *head)//creating the linked list from ACCOUNTfile
{
    ACCOUNT *current,*new_elt;
    new_elt=new ACCOUNT;
    FILE*fp;
    fp=fopen("account.txt","rb");


    while(fread(new_elt,sizeof (ACCOUNT),1,fp)==1)
    {
        new_elt->next=NULL;
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
        }

        new_elt =new ACCOUNT;

    }

    fclose(fp);
    return head;

}

