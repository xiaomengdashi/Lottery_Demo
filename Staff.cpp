//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include "Staff.h"

Staff::Staff()
{

}

Staff::~Staff()
{

}

void Staff::Add()
{
    sta staff;
    int job_number;
    string name;
    string department;
    string team;

    std::cout << "请输入员工的工号，姓名，部门，团队: ";
    std::cin >> job_number >> name >> department >> team;
    if (job_number != 0)
    {
        staff.job_number = job_number;
        staff.name = name;
        staff.department = department;
        staff.team = team;
        staff_.push_back(staff);
    }
}

int Staff::GetLotteryStaff(string department, string team)
{
    int size = 0;
    //  for(std::vector<sta>::iterator it=v.begin();it!=v.end();it++)
    for (auto & it : staff_)
    {
        if (!it.is_win)
        {
            std::cout << it.job_number << " " << it.name << " "
                      << it.department << " " << it.team << " " << std::endl;
            size++;
        }
    }
    return size;
}