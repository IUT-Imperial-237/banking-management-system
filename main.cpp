#include <iostream>
#include "client.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    person obj1;
    client obj2(obj1);
    obj2.Setcurrent_account(new account);
    obj2.Getcurrent_account()->Getopening_date().compute_actual_TIME();
    person obj3("AMADOU OLABI");
    client obj4(obj3);
    cout << "WORK !!!!!" << endl;
    return 0;
}
