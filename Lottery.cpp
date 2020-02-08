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
    for (auto & it : staff_)
    {
        cout << it.id << " "<< it.job_number << " "<< it.name << " "
             << it.department << " "<< it.team << " "<< it.is_win << endl;
    }
}

string Lottery::AllStaffLottery()
{
    int random_id = GetRandomNum(staff_num_);
    for (auto & it : staff_)
    {
        if(it.id == random_id)
        {
            cout << "随机数为:"<< random_id <<" " << "中奖员工为：" <<  it.name<< endl;
            it.is_win = true;
            return it.name;
        }
    }
    return "";
}

string Lottery::NotRepeatLottery()
{
    int random_id = GetRandomNum(staff_num_);
    for (auto & it : staff_)
    {
        if(it.id == random_id)
        {
            if (!it.is_win)
            {
                cout << "随机数为:"<< random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                return it.name;
            }
            else
            {
                return this->NotRepeatLottery();
            }
        }
    }
    return "";
}

string Lottery::DepartmentLottery(const string& department)
{
    int random_id = GetRandomNum(staff_num_);
    for (auto & it : staff_)
    {
        if (it.id == random_id)
        {
            if (it.department == department && !it.is_win)
            {
                cout << "随机数为:" << random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                return it.name;
            }
            else
            {
                return this->DepartmentLottery(department);
            }
        }
    }
    return "";
}

string Lottery::TeamLottery(const string& team)
{
    int random_id = GetRandomNum(staff_num_);
    for (auto &it : staff_)
    {
        if (it.id == random_id) {
            if (it.team == team && !it.is_win)
            {
                cout << "随机数为:" << random_id <<" " << "中奖员工为：" <<  it.name<< endl;
                it.is_win = true;
                return it.name;
            }
            else
            {
                return this->TeamLottery(team);
            }
        }
    }
    return "";
}

void Lottery::DobuleStaff(const string& name)
{
    int num  = staff_num_;
    for (int i = 0; i<num; i++)
    {
        if (staff_[i].name == name)
        {
            staff_.push_back(staff_[i]);
            staff_num_++;
            staff_[staff_num_-1].id = ++id;
        }
    }
}


void Lottery::DobuleTeam(const string& team)
{
    int num  = staff_num_;
    for (int i = 0; i<num; i++)
    {
        if (staff_[i].team == team)
        {
            staff_.push_back(staff_[i]);
            staff_num_++;
            staff_[staff_num_-1].id = ++id;
        }
    }
}

string Lottery::LotteryStart(bool flag, const string& department, const string& team)
{
    if (!flag && department.empty() && team.empty())
    {
        return this->AllStaffLottery();
    }
    else if (!department.empty())
    {
        return this->DepartmentLottery(department);
    }
    else if (!team.empty())
    {
        return this->TeamLottery(team);
    }
    else
        return this->NotRepeatLottery();
}

void Lottery::AddStaff(int job_number, string name, string department, string team)
{
    sta staff;
    staff.id = ++id;
    staff.job_number = job_number;
    staff.name = std::move(name);
    staff.department = std::move(department);
    staff.team = std::move(team);

    staff_.push_back(staff);
    staff_num_++;
}

void Lottery::DeleteStaff(const string& name)
{
    for(auto it = staff_.begin(); it != staff_.end(); it++)
    {
        if(it->name == name)
        {
            it = staff_.erase(it);
            if(it == staff_.end()) break;
        }
    }
}

