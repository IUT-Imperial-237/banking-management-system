#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "menu.h"

class admin : public person
{
    public:
        /** Default constructor */
        admin();
        /** Copy constructor
         *  \param other Object to copy from
         */
        admin( admin& other);
        /** Copy constructor
         *  \param p_other Object to copy from
         */
        //admin(const person& p_other);
        admin(person& p_person);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        admin& operator=( admin& other);
        admin& operator=( person& c_person);

        /** Access username
         * \return The current value of username
         */
        char* Getusername() { return username; }
        /** Set username
         * \param val New value to set
         */
        void Setusername(char* val) { strcpy(username, val); }
        /** Access password
         * \return The current value of password
         */
        char* Getpassword() { return password; }
        /** Set password
         * \param val New value to set
         */
        void Setpassword(char* val) { strcpy(password, val); }
        /** Access created_date
         * \return The current value of created_date
         */
        char* Getcreated_date() { return created_date; }
        /** Set created_date
         * \param val New value to set
         */
        void Setcreated_date() { strcpy(created_date, getTime()); }
        /** Access salary
         * \return The current value of salary
         */
        long double Getsalary() { return salary; }
        /** Set salary
         * \param val New value to set
         */
        void Setsalary(long double val) { salary = val; }
        /** Access category
         * \return The current value of category
         */
        char* Getcategory() { return category; }
        /** Set category
         * \param val New value to set
         */
        void Setcategory(char* val) { strcpy(category, val); }
        /** Access USER_ID
         * \return The current value of category
         */
        char* Getuser_ID() { return user_ID; }
        /** Set USER_ID
         * \param val New value to set
         */
        void Setuser_ID(char* val) { strcpy(user_ID,val); }

        void automate_salary_scale();
        void generate_user_ID();
        void reset_password();

        //!--Display person information
        void display_personal_info();
        void display_user_credentials();

        char* Getfunctionality() { return functionality; }
        void Setfunctionality(char* val) { strcpy(functionality, val); }

        admin* next; //!< Member variable "next"
        admin* previous; //!< Member variable "previous"

    protected:

    private:
        char username[50]; //!< Member variable "username"
        char password[50]; //!< Member variable "password"
        char created_date[50]; //!< Member variable "created_date"
        long double salary; //!< Member variable "salary"
        char category[10]; //!< Member variable "category"
        char functionality[255]; //!< Member variable "functionality"
        char user_ID[10]; //!< Member variable "functionality"
};

#endif // ADMIN_H
