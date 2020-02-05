//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include <random>
#include <set>
#include "Lottery.h"

using namespace std;

Lottery::Lottery()
{
    int ch;
    ch = std::cin.get();
    while (ch) // 回车继续增加，输入其他则停止增加
    {
        if (ch == '\n')
        {
            lottery_staff_.Add(); // 例如：1 王 一部 mcp
            lottery_staff_num_ ++;
        }
        else
            break;
        ch = std::cin.get();
        // cout << "当前员工数量" << lottery_staff_num_ << endl;
    }
}

Lottery::~Lottery()
{

}

void Lottery::AllStaffLottery()
{
    int range;
    while(cout << "输入随机数的范围 : ", cin >> range)
    {
        int ch;
        ch = cin.get();
        while (ch)
        {
            if (ch == '\n')
            {
                std::random_device rd;
                std::default_random_engine gen = std::default_random_engine(rd());
                std::uniform_int_distribution<int> dis(1, lottery_staff_num_);

                std::cout << "random number between 1 and range is: ";
                std::cout << dis(gen) << " " << std::endl;
            }
            else
                break;
            ch = cin.get();
        }
    }
}

void Lottery::NotRepeatLottery()
{
    lottery_staff_num_ = lottery_staff_.GetLotteryStaff(); // 全体抽奖员工数量
    int range;
    set<int> random_nums;
    while(cout << "输入随机数的范围 : ", cin >> range)
    {
        int ch = cin.get();
        while (ch)
        {
            if (ch == '\n')
            {
                std::random_device rd;
                std::default_random_engine gen = std::default_random_engine(rd());
                std::uniform_int_distribution<int> dis(1, range);

                std::cout << "random number between 1 and range is: ";
                int random_num = dis(gen);

                if (random_nums.find(random_num) == random_nums.end())
                {
                    std::cout << random_num << " " << std::endl;
                    random_nums.insert(random_num);

                    if (random_nums.size() == range)
                    {
                        std::cout << "全体员工都中奖了" << std::endl;
                        break;
                    }
                }
            }
            else
                break;
            ch = cin.get();
        }
    }
}

void Lottery::DepartmentLottery(const string& department)
{

}

void Lottery::TeamLottery(const string& team)
{

}

void Lottery::LotteryStart(bool flag, const string& department, const string& team)
{
    if (!flag)
    {
        this->AllStaffLottery();
    }
    else if (!department.empty())
    {
        this->DepartmentLottery(department);
    }
    else if (!team.empty())
    {
        this->TeamLottery(team);
    }
    else
        this->NotRepeatLottery();
}

