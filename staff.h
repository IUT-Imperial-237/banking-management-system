#ifndef STAFF_H
#define STAFF_H

#include "person.h"
#include "date_.h"


class staff : public person
{
    public:
        /** Default constructor */
        staff();
        /** Copy constructor
         *  \param other Object to copy from
         */
        staff(const staff& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        staff& operator=(const staff& other);

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
        /** Access category
         * \return The current value of category
         */
        string Getcategory() const{ return category; }
        /** Set category
         * \param val New value to set
         */
        void Setcategory(string val) { category = val; }
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

    protected:

    private:
        string username; //!< Member variable "username"
        string password; //!< Member variable "password"
        string category; //!< Member variable "category"
        date_ created_date; //!< Member variable "created_date"
        long double salary; //!< Member variable "salary"
};

#endif // STAFF_H
