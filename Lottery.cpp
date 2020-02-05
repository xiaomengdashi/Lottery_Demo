//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include <random>
#include <set>
#include "Lottery.h"

using namespace std;

int GetRandomNum(int num_max)
{
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(1, num_max);

    return dis(gen);
}

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
    }
    lottery_staff_num_--;
}

Lottery::~Lottery()
{

}

void Lottery::PrintStaff()
{
//    lottery_staff_.PrintAllStaff();
    for (auto & it : lottery_staff_.staff_)
    {
        cout << it.id << " "<< it.job_number << " "<< it.name << " "
             << it.department << " "<< it.team << " "<< it.is_win << endl;
    }
}

void Lottery::AllStaffLottery()
{
    int random_id = GetRandomNum(lottery_staff_num_);
//    set<int> random_num_set;
//    random_num_set.insert(random_id);
    for (auto & it : lottery_staff_.staff_)
    {
        if(it.id == random_id)
        {
            cout << "随机数为:"<< random_id <<" " << "中奖员工为：" <<  it.name<< endl;
            it.is_win = true;
            break;
        }
    }
}

void Lottery::NotRepeatLottery()
{
    int random_id = GetRandomNum(lottery_staff_num_);
    for (auto & it : lottery_staff_.staff_)
    {
        if(it.id == random_id)
        {
            if (!it.is_win)
            {
                cout << "随机数为:"<< random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                break;
            }
            else
            {
                // random_id = dis(gen);
            }
        }
    }
}

void Lottery::DepartmentLottery(const string& department)
{
    int random_id = GetRandomNum(lottery_staff_num_);
    for (auto & it : lottery_staff_.staff_)
    {
        if (it.id == random_id)
        {
            if (it.department == department && !it.is_win)
            {
                cout << "随机数为:" << random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                break;
            }
            else
            {
                // random_id = dis(gen);
            }
        }
    }
}

void Lottery::TeamLottery(const string& team)
{
    int random_id = GetRandomNum(lottery_staff_num_);
    for (auto &it : lottery_staff_.staff_)
    {
        if (it.id == random_id) {
            if (it.team == team && !it.is_win)
            {
                cout << "中奖员工为：" << it.name << endl;
                it.is_win = true;
                break;
            } else
            {
//                random_id = dis(gen);  // 如果id
            }
        }
    }
}

void Lottery::LotteryStart(bool flag, const string& department, const string& team)
{
    if (!flag && department.empty() && team.empty())
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

