#include "Date.h"
#include <iostream>
#include "LotteryTickets.h"

int main(){
    Date date1;
    Date date2(2002,12,3);
    Date date3(2002,12,4);
    std::cout<<"Date1";
    date1.display();
    std::cout<<"Date2";
    date2.display();
    std::cout<<"Date3";
    date3.display();

    int differnce = date2.diffrenceDay(date3);
    std::cout<<"Differnce:" <<differnce <<std::endl;

}