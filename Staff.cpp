//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include "Staff.h"

static int id = 0;

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
        staff.id = ++id;
        staff.job_number = job_number;
        staff.name = name;
        staff.department = department;
        staff.team = team;
        staff_.push_back(staff);
    }
}