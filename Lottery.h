//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#include <string>
#include "Staff.h"

class Lottery
{
public:
    Lottery();
    ~Lottery();
    void PrintStaff();  // 打印全体员工信息
    void LotteryStart(bool flag = false, const string& department = "", const string& team= "");
    friend int GetRandomNum(int num_max);

private:
    void NotRepeatLottery();
    void AllStaffLottery();
    void DepartmentLottery(const string& department);
    void TeamLottery(const string& team);

    Staff lottery_staff_;
    int lottery_staff_num_ = 0;
};
#endif //LOTTERY_LOTTERY_H
