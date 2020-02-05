//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include <string>
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
    std::cout << "请输入员工的工号，姓名，部门，团队" << std::endl;
    std::cin>>job_number>>name>>department>>team;
    staff.job_number = job_number;
    staff.name = name;
    staff.department = department;
    staff.team = team;
    v.push_back(staff);
}

void Staff::PrintAllStaff()
{
//  for(std::vector<sta>::iterator it=v.begin();it!=v.end();it++)
    for(auto & it : v)
    {
        std::cout<<it.job_number<<" "<<it.name<<" "<<it.department<<" "<<it.team<<std::endl;
    }
}