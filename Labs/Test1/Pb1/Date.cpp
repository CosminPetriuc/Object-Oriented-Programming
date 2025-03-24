#include "Date.h"
#include <iostream>

Date::Date(): year(1970), month(1), day(1){}

Date::Date(int y,int m, int d): year(y), month(m), day(d) {}

int Date ::getYear() const {return year; }
int Date ::getMonth() const {return month;}
int Date ::getDay() const {return day;}

void Date::setYear(int y) {year = y;}
void Date::setMonth(int m) {
    if(month >= 1 && month <=12)
        month = m;
    else
        std::printf("Invalid number");
}
void Date::setDay(int d) {
    if(day >=1 && day <= 31)
        day = d;
    else
        std::printf("Invalid number");
}

void Date::display() const {
    std::cout << "Date:" <<year << "-" << month <<"-"<< day << std::endl;

}


int Date::diffrenceDay(const Date &other) const {
    int thisDay = year*365 + month*30 + day;
    int otherDay = other.getYear()*365 + other.getMonth()*30 + other.getDay();

    return abs(thisDay - otherDay);
}
