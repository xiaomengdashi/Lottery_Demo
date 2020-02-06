//
// Created by kolane on 2020/2/3.
//

#include "Staff.h"

Staff::Staff()
{

}

Staff::~Staff()
{

}

void Staff::Add(const sta& staff)
{
    staff_.push_back(staff);
}

void Staff::Delete(const string& name)
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