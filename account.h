#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "date_.h"
using namespace std;

class account
{
    public:
        /** Default constructor */
        account();
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        account& operator=(const account& rhs);


        /** Access account_number
         * \return The current value of account_number
         */
        string Getaccount_number() const{ return account_number; }
        /** Set account_number
         * \param val New value to set
         */
        void Setaccount_number(string val) { account_number = val; }
        /** Access account_card
         * \return The current value of account_card
         */
        string Getaccount_card() const{ return account_card; }
        /** Set account_card
         * \param val New value to set
         */
        void Setaccount_card(string val) { account_card = val; }
        /** Access account_type
         * \return The current value of account_type
         */
        string Getaccount_type() const{ return account_type; }
        /** Set account_type
         * \param val New value to set
         */
        void Setaccount_type(string val) { account_type = val; }
        /** Access opening_date
         * \return The current value of opening_date
         */
        date_ Getopening_date() const{ return opening_date; }
        /** Set opening_date
         * \param val New value to set
         */
        void Setopening_date(date_ val) { opening_date = val; }
        /** Access status
         * \return The current value of status
         */
        bool Getstatus() const{ return status; }
        /** Set status
         * \param val New value to set
         */
        void Setstatus(bool val) { status = val; }
        /** Access balance
         * \return The current value of balance
         */
        long double Getbalance() const{ return balance; }
        /** Set balance
         * \param val New value to set
         */
        void Setbalance(long double val) { balance = val; }
        /** Access min_balance
         * \return The current value of min_balance
         */
        long double Getmin_balance() const{ return min_balance; }
        /** Set min_balance
         * \param val New value to set
         */
        void Setmin_balance(long double val) { min_balance = val; }
        /** Access rate
         * \return The current value of rate
         */
        float Getrate() const{ return rate; }
        /** Set rate
         * \param val New value to set
         */
        void Setrate(float val) { rate = val; }
        /** Access transaction_id
         * \return The current value of transaction_id
         */
        string Gettransaction_id() const{ return transaction_id; }
        /** Set transaction_id
         * \param val New value to set
         */
        void Settransaction_id(string val) { transaction_id = val; }
        /** Access transfer
         * \return The current value of transfer
         */
        int Gettransfer() const{ return transfer; }
        /** Set transfer
         * \param val New value to set
         */
        void Settransfer(int val) { transfer = val; }
        /** Access withdraw
         * \return The current value of withdraw
         */
        int Getwithdraw() const{ return withdraw; }
        /** Set withdraw
         * \param val New value to set
         */
        void Setwithdraw(int val) { withdraw = val; }
        /** Access deposit
         * \return The current value of deposit
         */
        int Getdeposit() const{ return deposit; }
        /** Set deposit
         * \param val New value to set
         */
        void Setdeposit(int val) { deposit = val; }

        /** Set Account Regime
         * \parameterized of account type using "account_type"
         */
        void SetRegime();

    protected:

    private:
        string account_number; //!< Member variable "account_number"
        string account_card; //!< Member variable "account_card"
        string account_type; //!< Member variable "account_type"
        date_ opening_date; //!< Member variable "opening_date"
        bool status; //!< Member variable "status"
        long double balance; //!< Member variable "balance"
        long double min_balance; //!< Member variable "min_balance"
        float rate; //!< Member variable "rate" it content the interest rate for each type of account
        string transaction_id; //!< Member variable "transaction_id" it contains the ID of the transaction in the transaction class
        int transfer; //!< Member variable "transfer" constraints on transfer (0,1,2) --> 0=not possible, 1=possible,2=universal
        int withdraw; //!< Member variable "withdraw" constraints on withdraw(0,1)
        int deposit; //!< Member variable "deposit" constraints on deposit(0,1)
};

#endif // ACCOUNT_H
