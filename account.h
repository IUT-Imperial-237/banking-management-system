#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class account
{
    public:
        /** Default constructor */
        account();
        /** Default destructor */
        virtual ~account();
        /** Copy constructor
         *  \param other Object to copy from
         */
        account(const account& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        account& operator=(const account& other);

        /** Access account_num
         * \return The current value of account_num
         */
        string Getaccount_num() { return account_num; }
        /** Set account_num
         * \param val New value to set
         */
        void Setaccount_num(string val) { account_num = val; }
        /** Access account_card
         * \return The current value of account_card
         */
        string Getaccount_card() { return account_card; }
        /** Set account_card
         * \param val New value to set
         */
        void Setaccount_card(string val) { account_card = val; }
        /** Access account_pin
         * \return The current value of account_pin
         */
        string Getaccount_pin() { return account_pin; }
        /** Set account_pin
         * \param val New value to set
         */
        void Setaccount_pin(string val) { account_pin = val; }
        /** Access balance
         * \return The current value of balance
         */
        long double Getbalance() { return balance; }
        /** Set balance
         * \param val New value to set
         */
        void Setbalance(long double val) { balance = val; }
        /** Access status
         * \return The current value of status
         */
        bool Getstatus() { return status; }
        /** Set status
         * \param val New value to set
         */
        void Setstatus(bool val) { status = val; }
        /** Access t_amount
         * \return The current value of t_amount
         */
        long double Gett_amount() { return t_amount; }
        /** Set t_amount
         * \param val New value to set
         */
        void Sett_amount(long double val) { t_amount = val; }

    protected:

    private:
        string account_num; //!< Member variable "account_num"
        string account_card; //!< Member variable "account_card"
        string account_pin; //!< Member variable "account_pin"
        long double balance; //!< Member variable "balance"
        bool status; //!< Member variable "status"
        long double t_amount; //!< Member variable "t_amount"
};

#endif // ACCOUNT_H
