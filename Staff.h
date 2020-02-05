//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_STAFF_H
#define LOTTERY_STAFF_H

#include <string>
#include <vector>

using namespace std;

struct sta
{
    int job_number;
    string name = "";
    string department = "";
    string team = "";
    bool is_win = false;  // 是否曾经中奖
};



class Staff
{
public:
    Staff();
    ~Staff();
    void Add();
    void PrintAllStaff();

private:
    vector<sta> v;
};
#endif //LOTTERY_STAFF_H