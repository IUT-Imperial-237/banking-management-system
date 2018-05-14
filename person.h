#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdlib>

using namespace std;

class person
{
    public:
        /** Default constructor */
        person();
        person(string _name); /// for experimental purpose
        person(const person& other);
        person& operator=(const person& other);

        /** Access name
         * \return The current value of name
         */
        string Getname() const{ return name; }
        /** Set name
         * \param val New value to set
         */
        void Setname(string val) { name = val; }
        /** Access DOB
         * \return The current value of DOB
         */
        string GetDOB() const{ return DOB; }
        /** Set DOB
         * \param val New value to set
         */
        void SetDOB(string val) { DOB = val; }
        /** Access phone
         * \return The current value of phone
         */
        string Getphone() const{ return phone; }
        /** Set phone
         * \param val New value to set
         */
        void Setphone(string val) { phone = val; }
        /** Access country
         * \return The current value of country
         */
        string Getcountry() const{ return country; }
        /** Set country
         * \param val New value to set
         */
        void Setcountry(string val) { country = val; }
        /** Access parentInfo
         * \return The current value of parentInfo
         */
        string GetparentInfo() const{ return parentInfo; }
        /** Set parentInfo
         * \param val New value to set
         */
        void SetparentInfo(string val) { parentInfo = val; }
        /** Access gender
         * \return The current value of gender
         */
        string Getgender() const{ return gender; }
        /** Set gender
         * \param val New value to set
         */
        void Setgender(string val) { gender = val; }
        /** Access email
         * \return The current value of email
         */
        string Getemail() const{ return email; }
        /** Set email
         * \param val New value to set
         */
        void Setemail(string val) { email = val; }
        /** Access address
         * \return The current value of address
         */
        string Getaddress() const{ return address; }
        /** Set address
         * \param val New value to set
         */
        void Setaddress(string val) { address = val; }
        /** Access profession
         * \return The current value of profession
         */
        string Getprofession() const{ return profession; }
        /** Set profession
         * \param val New value to set
         */
        void Setprofession(string val) { profession = val; }


    protected:

    private:
        string name; //!< Member variable "name"
        string DOB; //!< Member variable "DOB"
        string phone; //!< Member variable "phone"
        string country; //!< Member variable "country"
        string parentInfo; //!< Member variable "parentInfo"
        string gender; //!< Member variable "gender"
        string email; //!< Member variable "email"
        string address; //!< Member variable "address"
        string profession; //!< Member variable "profession"
};

#endif // PERSON_H
