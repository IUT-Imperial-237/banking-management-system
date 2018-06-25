#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class person
{
    public:
        /** Constructor's */
        person();

        person(string _name,
               string _DOB,
               string _phone,
               string _country,
               string _parentInfo,
               string _gender,
               string _email,
               string _address,
               string _profession); /// for experimental purpose

        person( person& other);
        person& operator=( person& other);

        /** Access name
         * \return The current value of name
         */
        char* Getname() { return name; }
        /** Set name
         * \param val New value to set
         */
        void Setname(char* val) { strcpy(name,val); }
        /** Access DOB
         * \return The current value of DOB
         */
        char* GetDOB() { return DOB; }
        /** Set DOB
         * \param val New value to set
         */
        void SetDOB(char* val) { strcpy(DOB,val); }
        /** Access phone
         * \return The current value of phone
         */
        char* Getphone() { return phone; }
        /** Set phone
         * \param val New value to set
         */
        void Setphone(char* val) { strcpy(phone,val); }
        /** Access country
         * \return The current value of country
         */
        char* Getcountry() { return country; }
        /** Set country
         * \param val New value to set
         */
        void Setcountry(char* val) { strcpy(country,val); }
        /** Access parentInfo
         * \return The current value of parentInfo
         */
        char* GetparentInfo() { return parentInfo; }
        /** Set parentInfo
         * \param val New value to set
         */
        void SetparentInfo(char* val) { strcpy(parentInfo,val); }
        /** Access gender
         * \return The current value of gender
         */
        char* Getgender() { return gender; }
        /** Set gender
         * \param val New value to set
         */
        void Setgender(char* val) { strcpy(gender,val); }
        /** Access email
         * \return The current value of email
         */
        char* Getemail() { return email; }
        /** Set email
         * \param val New value to set
         */
        void Setemail(char* val) { strcpy(email,val); }
        /** Access address
         * \return The current value of address
         */
        char* Getaddress() { return address; }
        /** Set address
         * \param val New value to set
         */
        void Setaddress(char* val) { strcpy(address,val); }
        /** Access profession
         * \return The current value of profession
         */
        char* Getprofession() { return profession; }
        /** Set profession
         * \param val New value to set
         */
        void Setprofession(char* val) { strcpy(profession,val); }

    protected:

    private:
        char name[255]; //!< Member variable "name"
        char DOB[50]; //!< Member variable "DOB"
        char phone[20]; //!< Member variable "phone"
        char country[30]; //!< Member variable "country"
        char parentInfo[50]; //!< Member variable "parentInfo"
        char gender[10]; //!< Member variable "gender"
        char email[50]; //!< Member variable "email"
        char address[255]; //!< Member variable "address"
        char profession[100]; //!< Member variable "profession"
};

#endif // PERSON_H
