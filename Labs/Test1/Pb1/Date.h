#ifndef TEST1_Date_H
#define TEST1_Date_H

class Date{
public:
    int year;
    int month;
    int day;


    Date();
    Date(int year, int month, int day);

    int getYear()const;
    int getMonth()const;
    int getDay()const;

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    void display()const;

    int diffrenceDay(const Date& other)const;

};
#endif //TEST1_Date_H