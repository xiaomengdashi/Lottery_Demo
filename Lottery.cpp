//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include "Lottery.h"
#include <ctime>
#include <random>

using namespace std;

static int id = 0;
static int m = 0, n = 0, j = 0,p=0;


Lottery::Lottery()= default;

Lottery::~Lottery()= default;

int Lottery::GetRandomNum()
{
    int sum = 0;
    vector<int> w(staff_num_);
    vector<int> vec_sum(0);

    for (int i=0; i<staff_num_; i++)
    {
        w[i] = staff_[i].weight;
    }

    for (int i=0; i<staff_num_; i++)
    {
        sum += staff_[i].weight;
        vec_sum.push_back(sum);
    }
    static std::default_random_engine e(time(NULL));
    static std::uniform_int_distribution<int> u(0, sum-1);
    int target = u(e);
    int s = target;


    int k=0;
    for(;k<vec_sum.size();++k)
    {
        if(s<vec_sum[k])
        {
            break;
        }
    }
    return k;
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
    string staff_name{};
    int random_id = GetRandomNum();
    staff_[random_id].is_win = true;
    staff_name =  staff_[random_id].name;

    if (staff_name == "小明")
    {
        m++;
    } else if (staff_name=="小红")
    {
        n++;
    } else if (staff_name == "小李")
    {
        j++;
    }
    p++;
    std::cout << double (m)/double(p) <<"  "<< double (n)/double(p) << "  " << double (j)/double(p) << "   "  << p << std::endl;

    return staff_name;
}

string Lottery::NotRepeatLottery()
{
    string staff_name{};
    int random_id = GetRandomNum();

    if (!staff_[random_id].is_win)
    {
        staff_[random_id].is_win = true;
        staff_name = staff_[random_id].name;
        return staff_name;
    }
    else
    {
        return this->NotRepeatLottery();
    }
}

void Lottery::GobackLottery()
{
    for (auto &it : staff_)
    {
        it.is_win = false;
    }
}

string Lottery::DepartmentLottery(const string& department)
{
    string staff_name{};
    int random_id = GetRandomNum();

    if (staff_[random_id].department == department && !staff_[random_id].is_win)
    {
        staff_[random_id].is_win = true;
        staff_name = staff_[random_id].name;
        return staff_name;
    }
    else
    {
        return this->DepartmentLottery(department);
    }
}

string Lottery::TeamLottery(const string& team)
{
    string staff_name{};
    int random_id = GetRandomNum();

    if (staff_[random_id].team == team && !staff_[random_id].is_win)
    {
        staff_[random_id].is_win = true;
        staff_name = staff_[random_id].name;
        return staff_name;
    }
    else
    {
        return this->DepartmentLottery(team);
    }
}

void Lottery::DobuleStaff(const string& name)
{
    int num  = staff_num_;
    for (int i = 0; i<num; i++)
    {
        if (staff_[i].name == name)
        {
            staff_[i].weight = 2;
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
            staff_[i].weight = 2;
        }
    }
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
            staff_num_ -= 1;
            if (it == staff_.end()) break;
        }
    }
}

