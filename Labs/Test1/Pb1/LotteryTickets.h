//
// Created by cosmi on 3/25/2024.
//
#include "Date.h"
#include <iostream>
#ifndef TEST1_LOTTERYTICKETS_H
#define TEST1_LOTTERYTICKETS_H

class LotteryTickets{
private:
    static const int Numbers = 6;
    unsigned short numbers[Numbers];
    Date date;
    void generateRandomN();
    static Date extractionDate;
public:
    LotteryTickets();
    LotteryTickets(unsigned short numbers[], Date d);
    void display()const;

    static void ExtractionDate(Date d);
};
#endif //TEST1_LOTTERYTICKETS_H
