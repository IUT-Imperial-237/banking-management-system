#include "date_.h"
#include<cstdlib>

date_::date_()
{
    //ctor
    this->dd = 13;
    this->mm = 5;
    this->yyyy = 18;
    this->day = "Sunday";
    this->month = "May";
    this->year = "2018";
    this->Time = "02:54:30"; //HH:MIN:SS
}

date_& date_::operator=(const date_& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->dd = rhs.Getdd();
    this->mm = rhs.Getmm();
    this->yyyy = rhs.Getyyyy();
    this->day = rhs.Getday();
    this->month = rhs.Getmonth();
    this->year = rhs.Getyear();
    this->Time = rhs.GetTime();
    return *this;
}

void date_::compute_actual_TIME()
{
    ///----UNDER CONSTRUCTION;
    cout<<DEFAULT;
    exit(1);
    /// COMPUTE ACTUAL OR PRESENT TIME && DAY USING "TIME.H"
}
