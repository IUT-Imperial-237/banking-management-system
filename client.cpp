#include "client.h"

client::client()
{
    //ctor

}

client::client(const client& other)
{
    //copy ctor
}

client& client::operator=(const client& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    //assignment operator
    return *this;
}

/** Default Setter for Person Information of a client */
void client::SetDefaultPerson_()
{
    Setname("Name");
    SetbirhtInfos("birhtInfos");
    Setaddress("address");
    Setphone("phone");
    Setcountry("country");
    SetparentInfo("parentInfo");
    Setgender("gender");
    Setemail("email");
    Setprofession("profession");
}

/** Default Setter for Account Details of a client  */
void client::SetDefaultAccount()
{
    Setaccount_num("XXX-XXXX-XXX");
    Setaccount_card("XXX-XXXX");
    Setaccount_pin("XXXX");
    Setbalance(1000.00);
    Setstatus(false);
    Sett_amount(0.00);
}
