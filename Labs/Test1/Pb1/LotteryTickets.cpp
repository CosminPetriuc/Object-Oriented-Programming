#include "LotteryTickets.h"
#include <iostream>
#include <cstdlib>
LotteryTickets::LotteryTickets() {
    generateRandomN();
    date.day = 25;
    date.month = 3;
    date.year = 2024;
}
LotteryTickets::LotteryTickets(unsigned short *numbers, Date d) {
    for(int i = 0; i < 6; i++){
        this->numbers[i] = numbers[i];
    }
    date = d;
}

void LotteryTickets::generateRandomN() {
    for(int i = 0; i< 6; i++) {
        bool duplicate;
        int num;
        do {
            duplicate = false;
            num = 1 + rand() % 49;
            for (int j = 0; j < i; j++) {
                if (numbers[j] == num) {
                    duplicate = true;
                    break;
                }
            }
        }while(duplicate);
        numbers [i] = num;
    }
}

void LotteryTickets::display() const {
    std::cout <<"Lottery numbers:";
    for(int i=0; i<6; i++) {
        std::cout<<numbers[i]<<"-";
    }
}
Date LotteryTickets::extractionDate = {0,0,0};

void LotteryTickets::ExtractionDate(Date d) {
    extractionDate = d;
}


