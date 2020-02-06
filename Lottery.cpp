//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include <random>
#include <set>
#include <utility>
#include "Lottery.h"

using namespace std;

static int id = 0;

int GetRandomNum(int num_max)
{
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(1, num_max);

    return dis(gen);
}

Lottery::Lottery()
{

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
                //TODO 当前随机数所在的员工不符合要求，需要再次得到随机数。
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
                cout << "随机数为:" << random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                break;
            }
            else
            {
//                random_id = dis(gen);  // 如果id
            }
        }
    }
}

void Lottery::DobuleStaff(const string& name)
{
    int num  = lottery_staff_num_;
    for (int i = 0; i<num; i++)
    {
        if (lottery_staff_.staff_[i].name == name)
        {
            lottery_staff_.staff_.push_back(lottery_staff_.staff_[i]);
            lottery_staff_num_++;
            //TODO 修改增加的员工id
            lottery_staff_.staff_[lottery_staff_num_-1].id = ++id;
        }
    }
}


void Lottery::DobuleTeam(const string& team)
{
    int num  = lottery_staff_num_;
    for (int i = 0; i<num; i++)
    {
        if (lottery_staff_.staff_[i].team == team)
        {
            lottery_staff_.staff_.push_back(lottery_staff_.staff_[i]);
            lottery_staff_num_++;
            lottery_staff_.staff_[lottery_staff_num_-1].id = ++id;
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

void Lottery::AddStaff(int job_number, string name, string department, string team)
{
    sta staff;
    staff.id = ++id;
    staff.job_number = job_number;
    staff.name = std::move(name);
    staff.department = std::move(department);
    staff.team = std::move(team);

    lottery_staff_.Add(staff);
    lottery_staff_num_++;
}

void Lottery::DeleteStaff(string name)
{

}

