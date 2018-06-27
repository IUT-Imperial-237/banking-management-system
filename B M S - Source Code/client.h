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
        client(client& other);

        /** Parameterized Constructor
         *  \param temp_acc to set account details of a client
         */
        client(account& temp_acc);

        /** Parameterized Constructor
         *  \param c_person to set personal info of a client
         */
        client(person& c_person);

        /** Parameterized Constructor
         *  \param OBJ_PERSON, Temp_Acc{CUR|SAV|STU} Objects to set an object of client class
         */
        client(person& obj_person,account temp_acc);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        client& operator=( client& other);
        client& operator=( person& c_person);


        /** Access pin_code
         * \return The current value of pin_code
         */
        char* Getpin_code() { return pin_code; }

        /** Auto-Set pin_code*/
        void Setpin_code();

        /** Access client_ID
         * \return The current value of client_ID
         */
        char* Getclient_ID() { return client_ID; }

        /** Auto-Set client_ID*/
        void Setclient_ID();

        account current_account; //!< Member variable "current_account"

        account savings_account; //!< Member variable "savings_account"

        account student_account; //!< Member variable "student_account"

        account *temp_acc; //!< Member variable "student_account" just for accessing purpose;


        /**     RESET ACCOUNT     */
        void Reset_PinCode();

        //!--Display person information
        void display_personal_info();

        void modif_pin(char* val) { strcpy(this->pin_code,val); }

        void add_new_account(account acc_);
        void del_new_account(int option); //!-- 2 = current || 1 = savings || 0 = student

        client* next; //!< Member variable "next"
        client* previous; //!< Member variable "previous"


    protected:

    private:
        char pin_code[10]; //!< Member variable "pin_code"
        char client_ID[20]; //!< Member variable "client_ID"
};

#endif // CLIENT_H
