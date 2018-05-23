#ifndef __MECHANISM_HEADER_
#define __MECHANISM_HEADER_

#define _ERROR 0
#define SUCCESS 1

//#include <iostream>
#include "client.h"
#include "admin.h"
#include "staff.h"
#include "menu.h"

using namespace std;

client* Create_New_User(client* );
admin* Create_New_User(admin* );
staff* Create_New_User(staff* );

client* Delete_New_User(client* );
admin* Delete_New_User(admin* );
staff* Delete_New_User(staff* );

client* Search_User(client* );
admin* Search_User(admin* );
staff* Search_User(staff* );



#endif // __MECHANISM_HEADER_
