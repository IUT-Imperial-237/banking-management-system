#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "client.h"

class transaction
{
    public:
        /** Default constructor */
        transaction();



        void set_transaction(account acc_, char* nature,char* to_acc, long double Amount_);
        void display_transaction();     /**Display one by one trans..*/

        /** Access transaction_ID[20]
         * \return The current value of transaction_ID[20]
         */
        char* Gettransaction_ID() { return transaction_ID; }
        /** Set transaction_ID[20]
         * \param val New value to set
         */
        void Settransaction_ID(char* val) { strcpy(transaction_ID, val); }
        /** Access transaction_nature[20]
         * \return The current value of transaction_nature[20]
         */
        char* Gettransaction_nature() { return transaction_nature; }
        /** Set transaction_nature[20]
         * \param val New value to set
         */
        void Settransaction_nature(char* val) { strcpy(transaction_nature, val); }
        /** Access transaction_date[50]
         * \return The current value of transaction_date[50]
         */
        char* Gettransaction_date() { return transaction_date; }
        /** Set transaction_date[50]
         * \param val New value to set
         */
        void Settransaction_date() { strcpy(transaction_date, getTime()); }
        /** Access Acc_No[20]
         * \return The current value of Acc_No[20]
         */
        char* GetAcc_No() { return Acc_No; }
        /** Set Acc_No[20]
         * \param val New value to set
         */
        void SetAcc_No(char* val) { strcpy(Acc_No, val); }
        /** Access To_Acc_No[20]
         * \return The current value of To_Acc_No[20]
         */
        char* GetTo_Acc_No() { return To_Acc_No; }
        /** Set To_Acc_No[20]
         * \param val New value to set
         */
        void SetTo_Acc_No(char* val) { strcpy(To_Acc_No, val); }
        /** Access Amount
         * \return The current value of Amount
         */
        long double GetAmount() { return Amount; }
        /** Set Amount
         * \param val New value to set
         */
        void SetAmount(long double val) { Amount = val; }
        /** Access balance
         * \return The current value of balance
         */
        long double Getbalance() { return balance; }
        /** Set balance
         * \param val New value to set
         */
        void Setbalance(long double val) { balance = val; }
        /** Access customer_name[255]
         * \return The current value of customer_name[255]
         */
        char* Getcustomer_name() { return customer_name; }
        /** Set customer_name[255]
         * \param val New value to set
         */
        void Setcustomer_name(char* val) { strcpy(customer_name, val); }

        void save();

        transaction* next;
        transaction* previous;

    protected:

    private:
        char transaction_ID[20]; //!< Member variable "transaction_ID[20]"
        char transaction_nature[20]; //!< Member variable "transaction_nature[20]"
        char transaction_date[50]; //!< Member variable "transaction_date[50]"
        char Acc_No[20]; //!< Member variable "Acc_No[20]"
        char To_Acc_No[20]; //!< Member variable "To_Acc_No[20]"
        long double Amount; //!< Member variable "Amount"
        long double balance; //!< Member variable "balance"
        char customer_name[255]; //!< Member variable "customer_name[255]"
};


#endif // TRANSACTION_H
