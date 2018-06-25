#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstring>
#include "menu.h"
using namespace std;

static int total_clients;
int get_total_clients();
void set_total_clients(int );
void initialize_total_clients();
void increase_total_clients();
void decrease_total_clients();
void write_total_clients();
int read_total_clients();

class account
{
    public:
        /** Default constructor */
        account();
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        account& operator=(account rhs);


        /** Access account_number
         * \return The current value of account_number
         */
        char* Getaccount_number() { return account_number; }
        /** Set account_number
         * \param val New value to set
         */
        void Setaccount_number(char* val) { strcpy(account_number,val); }
        /** Access account_card
         * \return The current value of account_card
         */
        char* Getaccount_card() { return account_card; }
        /** Set account_card
         * \param val New value to set
         */
        void Setaccount_card(char* val) { strcpy(account_card,val); }
        /** Access account_type
         * \return The current value of account_type
         */
        char* Getaccount_type() { return account_type; }
        /** Set account_type
         * \param val New value to set
         */
        void Setaccount_type(char* val) { strcpy(account_type,val); }
        /** Access opening_date
         * \return The current value of opening_date
         */
        char* Getopening_date() { return opening_date; }
        /** Set opening_date
         * \param val New value to set
         */
        void Setopening_date() { strcpy(opening_date,getTime()); }
        /** Access status
         * \return The current value of status
         */
        bool Getstatus() { return status; }
        /** Set status
         * \param val New value to set
         */
        void Setstatus(bool val) { status = val; }
        /** Access balance
         * \return The current value of balance
         */
        long double Getbalance() { return balance; }
        /** Set balance
         * \param val New value to set
         */
        void Setbalance(long double val) { balance = val; }
        /** Access min_balance
         * \return The current value of min_balance
         */
        long double Getmin_balance() { return min_balance; }
        /** Set min_balance
         * \param val New value to set
         */
        void Setmin_balance(long double val) { min_balance = val; }
        /** Access rate
         * \return The current value of rate
         */
        float Getrate() { return rate; }
        /** Set rate
         * \param val New value to set
         */
        void Setrate(float val) { rate = val; }
        /** Access transaction_id
         * \return The current value of transaction_id
         */
        char* Gettransaction_id() { return transaction_id; }
        /** Set transaction_id
         * \param val New value to set
         */
        void Settransaction_id(char* val) { strcpy(transaction_id,val); }
        /** Access transfer
         * \return The current value of transfer
         */
        int Gettransfer_tag() { return transfer_tag; }
        /** Set transfer
         * \param val New value to set
         */
        void Settransfer_tag(int val) { transfer_tag = val; }
        /** Access withdraw
         * \return The current value of withdraw
         */
        int Getwithdraw_tag() { return withdraw_tag; }
        /** Set withdraw
         * \param val New value to set
         */
        void Setwithdraw_tag(int val) { withdraw_tag = val; }
        /** Access deposit
         * \return The current value of deposit
         */
        int Getdeposit_tag() { return deposit_tag; }
        /** Set deposit
         * \param val New value to set
         */
        void Setdeposit_tag(int val) { deposit_tag = val; }

        /** Set Account Regime
         * \parameterized of account type using "account_type"
         */
        void SetRegime();

        /** Activate Fully the Account*/
        void Activate_Account();

        /***    TRANSACTIONS     **/
        void deposit(long double _money)
        {
            this->balance += _money;
        }
        void withdraw(long double _money)
        {
            this->balance -= _money;
        }
        void transfer(long double _money)
        {
            withdraw(_money);
        }

        /***    aUTO-GENERATION     ***/
        void generate_Acc_Number();
        void generate_Acc_Card();
        void generate_Trans_ID();

        /** Display Account Info's **/
        void display_Acc_Info();

        int difference(double val)
        {
            if(balance < val)
                return -1;
            else if(balance - val < min_balance)
                return 0;
            else
                return 1;
        }

        /**     Judge to whom to send Money */
        bool judgment(account *acc_test)
        {
            switch(this->Gettransfer_tag())
            {
            case 2:
                return true;
            case 1:
                if(acc_test == NULL)
                    return true;
                else if(acc_test->Gettransfer_tag()==2)
                    return false;
                else
                    return true;
            case 0:
                return false;
            }
            return false;
        }

        void disable_account(int option); //!-- 1 = completely || 2 = partially


    protected:

    private:
        char account_number[20]; //!< Member variable "account_number"
        char account_card[20]; //!< Member variable "account_card"
        char account_type[5]; //!< Member variable "account_type"
        char opening_date[100]; //!< Member variable "opening_date"
        bool status; //!< Member variable "status"
        long double balance; //!< Member variable "balance"
        long double min_balance; //!< Member variable "min_balance"
        float rate; //!< Member variable "rate" it content the interest rate for each type of account
        char transaction_id[20]; //!< Member variable "transaction_id" = "TRANS-XXXX" it contains the ID of the transaction in the transaction class
        int transfer_tag; //!< Member variable "transfer" constraints on transfer option (0,1,2) --> 0=not possible, 1=possible,2=universal
        int withdraw_tag; //!< Member variable "withdraw" constraints on withdraw option (0,1)
        int deposit_tag; //!< Member variable "deposit" constraints on deposit option (0,1)
};

#endif // ACCOUNT_H
