//
// Created by kolane on 2020/2/3.
//

#ifndef staff_H
#define staff_H

#include <string>
#include <vector>

using namespace std;

enum class Awards
{
    first_prize = 1,
    second_prize,
    third_prize,
    common_prize,
};

struct sta
{
    int job_number = 0;
    string name = "";
    string department = "";
    string team = "";
    bool is_win = false;  // 是否曾经中奖
    int weight = 1;
    vector<Awards> award;
};
#endif //staff_H