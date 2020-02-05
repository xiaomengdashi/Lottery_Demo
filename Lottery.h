//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#include "Staff.h"

class Lottery
{
public:
    Lottery();
    ~Lottery();

    void not_repeat_lottery();
    void all_lottery();
    void department_lottery();
    void team_lottery();

private:
    Staff staff;
};
#endif //LOTTERY_LOTTERY_H
