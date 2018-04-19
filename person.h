#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class person
{
    public:
        /** Default constructor */
        person();
        /** Default destructor */
        virtual ~person();
        /** Copy constructor
         *  \param other Object to copy from
         */
        person(const person& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        person& operator=(const person& other);

        /** Access name
         * \return The current value of name
         */
        string Getname() { return name; }
        /** Set name
         * \param val New value to set
         */
        void Setname(string val) { name = val; }
        /** Access birhtInfos
         * \return The current value of birhtInfos
         */
        string GetbirhtInfos() { return birhtInfos; }
        /** Set birhtInfos
         * \param val New value to set
         */
        void SetbirhtInfos(string val) { birhtInfos = val; }
        /** Access address
         * \return The current value of address
         */
        string Getaddress() { return address; }
        /** Set address
         * \param val New value to set
         */
        void Setaddress(string val) { address = val; }
        /** Access phone
         * \return The current value of phone
         */
        string Getphone() { return phone; }
        /** Set phone
         * \param val New value to set
         */
        void Setphone(string val) { phone = val; }
        /** Access country
         * \return The current value of country
         */
        string Getcountry() { return country; }
        /** Set country
         * \param val New value to set
         */
        void Setcountry(string val) { country = val; }
        /** Access parentInfo
         * \return The current value of parentInfo
         */
        string GetparentInfo() { return parentInfo; }
        /** Set parentInfo
         * \param val New value to set
         */
        void SetparentInfo(string val) { parentInfo = val; }
        /** Access gender
         * \return The current value of gender
         */
        string Getgender() { return gender; }
        /** Set gender
         * \param val New value to set
         */
        void Setgender(string val) { gender = val; }
        /** Access email
         * \return The current value of email
         */
        string Getemail() { return email; }
        /** Set email
         * \param val New value to set
         */
        void Setemail(string val) { email = val; }
        /** Access profession
         * \return The current value of profession
         */
        string Getprofession() { return profession; }
        /** Set profession
         * \param val New value to set
         */
        void Setprofession(string val) { profession = val; }

    protected:

    private:
        string name; //!< Member variable "name"
        string birhtInfos; //!< Member variable "birthInfos"
        string address; //!< Member variable "address"
        string phone; //!< Member variable "phone"
        string country; //!< Member variable "country"
        string parentInfo; //!< Member variable "parentInfo"
        string gender; //!< Member variable "gender"
        string email; //!< Member variable "email"
        string profession; //!< Member variable "profession"
};

#endif // PERSON_H
