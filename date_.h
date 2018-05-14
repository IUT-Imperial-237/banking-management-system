#ifndef DATE__H
#define DATE__H

#define DEFAULT "UNDER CONSTRUCTION !!!"

#include <ctime>
#include <iostream>
using namespace std;

class date_
{
    public:
        /** Default constructor */
        date_();
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        date_& operator=(const date_& other);

        ///* compute and set the actual date using SYS-TIME
        void compute_actual_TIME();

        /** Access dd
         * \return The current value of dd
         */
        int Getdd() const{ return dd; }
        /** Set dd
         * \param val New value to set
         */
        void Setdd(int val) { dd = val; }
        /** Access mm
         * \return The current value of mm
         */
        int Getmm() const{ return mm; }
        /** Set mm
         * \param val New value to set
         */
        void Setmm(int val) { mm = val; }
        /** Access yyyy
         * \return The current value of yyyy
         */
        int Getyyyy() const{ return yyyy; }
        /** Set yyyy
         * \param val New value to set
         */
        void Setyyyy(int val) { yyyy = val; }
        /** Access day
         * \return The current value of day
         */
        string Getday() const{ return day; }
        /** Set day
         * \param val New value to set
         */
        void Setday(string val) { day = val; }
        /** Access month
         * \return The current value of month
         */
        string Getmonth() const{ return month; }
        /** Set month
         * \param val New value to set
         */
        void Setmonth(string val) { month = val; }
        /** Access year
         * \return The current value of year
         */
        string Getyear() const{ return year; }
        /** Set year
         * \param val New value to set
         */
        void Setyear(string val) { year = val; }
        /** Access Time
         * \return The current value of Time
         */
        string GetTime() const{ return Time; }
        /** Set Time
         * \param val New value to set
         */
        void SetTime(string val) { Time = val; }

    protected:

    private:
        int dd; //!< Member variable "dd"
        int mm; //!< Member variable "mm"
        int yyyy; //!< Member variable "yyyy"
        string day; //!< Member variable "day"
        string month; //!< Member variable "month"
        string year; //!< Member variable "year"
        string Time; //!< Member variable "Time"
};

#endif // DATE__H
