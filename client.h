#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "account.h"


class client : public person
{
    public:
        /** Default constructor */
        client();
        /** Copy constructor
         *  \param other Object to copy from
         */
        client(const client& other);
        /** Copy constructor of Clients to set Accounts (CUR,SAV,STU)
         *  \param CUR,SAV,STU ObjectS to copy from "account.h"
         */
        client(account* cur, account* sav, account* stu);
        /** Copy constructor of Clients to set a person
         *  \param c_person Object to copy from "person.h"
         */
        client(const person& c_person);
        /** Copy constructor of Clients to set both Person Info && Accounts (CUR,SAV,STU)
         *  \param OBJ_PERSON,CUR,SAV,STU Objects to copy from "person.h" and "account.h"
         */
        client(const person& obj_person, account* cur, account* sav, account* stu);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        client& operator=(const client& other);

        /** Access pin_code
         * \return The current value of pin_code
         */
        int Getpin_code() const{ return pin_code; }
        /** Set pin_code
         * \param val New value to set
         */
        void Setpin_code(int val) { pin_code = val; }
        /** Access current_account
         * \return The current value of current_account
         */
        account* Getcurrent_account() const{ return current_account; }
        /** Set current_account
         * \param val New value to set
         */
        void Setcurrent_account(account* val) { current_account = val; }
        /** Access savings_account
         * \return The current value of savings_account
         */
        account* Getsavings_account() const{ return savings_account; }
        /** Set savings_account
         * \param val New value to set
         */
        void Setsavings_account(account* val) { savings_account = val; }
        /** Access student_account
         * \return The current value of student_account
         */
        account* Getstudent_account() const{ return student_account; }
        /** Set student_account
         * \param val New value to set
         */
        void Setstudent_account(account* val) { student_account = val; }
        /** Access next
         * \return The current value of next
         */
        client* Getnext() const{ return next; }
        /** Set next
         * \param val New value to set
         */
        void Setnext(client* val) { next = val; }
        /** Access previous
         * \return The current value of previous
         */
        client* Getprevious() const{ return previous; }
        /** Set previous
         * \param val New value to set
         */
        void Setprevious(client* val) { previous = val; }
        /** Access client_ID
         * \return The current value of client_ID
         */
        string Getclient_ID() const{ return client_ID; }
        /** Set client_ID
         * \param val New value to set
         */
        void Setclient_ID(string val) { client_ID = val; }

    protected:

    private:
        int pin_code; //!< Member variable "pin_code"
        account* current_account; //!< Member variable "current_account"
        account* savings_account; //!< Member variable "savings_account"
        account* student_account; //!< Member variable "student_account"
        client* next; //!< Member variable "next"
        client* previous; //!< Member variable "previous"
        string client_ID; //!< Member variable "client_ID"
};

#endif // CLIENT_H
