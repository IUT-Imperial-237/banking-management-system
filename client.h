#ifndef CLIENT_H
#define CLIENT_H

#include <person.h>
#include <account.h>


class client : public person, public account
{
    public:
        /** Default constructor */
        client();
        /** Copy constructor
         *  \param other Object to copy from
         */
        client(const client& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        client& operator=(const client& other);

        /** Access next
         * \return The current value of next
         */
        client* Getnext() { return next; }
        /** Set next
         * \param val New value to set
         */
        void Setnext(client* val) { next = val; }
        /** Access prev
         * \return The current value of prev
         */
        client* Getprev() { return prev; }
        /** Set prev
         * \param val New value to set
         */
        void Setprev(client* val) { prev = val; }

        /** Default Setter for Person Information of a client */
        void SetDefaultPerson_();

        /** Default Setter for Account Details of a client  */
        void SetDefaultAccount();


    protected:

    private:
        client* next; //!< Member variable "next"
        client* prev; //!< Member variable "prev"
};

#endif // CLIENT_H
