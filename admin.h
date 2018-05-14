#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "date_.h"


class admin : public person
{
    public:
        /** Default constructor */
        admin();
        /** Copy constructor
         *  \param other Object to copy from
         */
        admin(const admin& other);
        /** Copy constructor
         *  \param p_other Object to copy from
         */
        admin(const person& p_other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        admin& operator=(const admin& other);

        /** Access username
         * \return The current value of username
         */
        string Getusername() const{ return username; }
        /** Set username
         * \param val New value to set
         */
        void Setusername(string val) { username = val; }
        /** Access password
         * \return The current value of password
         */
        string Getpassword() const{ return password; }
        /** Set password
         * \param val New value to set
         */
        void Setpassword(string val) { password = val; }
        /** Access created_date
         * \return The current value of created_date
         */
        date_ Getcreated_date() const{ return created_date; }
        /** Set created_date
         * \param val New value to set
         */
        void Setcreated_date(date_ val) { created_date = val; }
        /** Access salary
         * \return The current value of salary
         */
        long double Getsalary() const{ return salary; }
        /** Set salary
         * \param val New value to set
         */
        void Setsalary(long double val) { salary = val; }
        /** Access category
         * \return The current value of category
         */
        string Getcategory() const{ return category; }
        /** Set category
         * \param val New value to set
         */
        void Setcategory(string val) { category = val; }

    protected:

    private:
        string username; //!< Member variable "username"
        string password; //!< Member variable "password"
        date_ created_date; //!< Member variable "created_date"
        long double salary; //!< Member variable "salary"
        string category; //!< Member variable "category"
};

#endif // ADMIN_H
