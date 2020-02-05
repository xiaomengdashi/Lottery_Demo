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

}

Lottery::~Lottery()
{

}

void Lottery::all_lottery()
{
    int range;
    set<int> random_nums;
    while(cout << "输入随机数的范围 : ", cin >> range)
    {
        int ch;
        while (ch = cin.get())
        {
            if (ch == '\n')
            {
                std::random_device rd;
                std::default_random_engine gen = std::default_random_engine(rd());
                std::uniform_int_distribution<int> dis(1, range);

                std::cout << "random number between 1 and range is: ";
                std::cout << dis(gen) << " " << std::endl;
            }
            else
                break;
        }
    }
}

void Lottery::not_repeat_lottery()
{
    int range;
    set<int> random_nums;
    while(cout << "输入随机数的范围 : ", cin >> range)
    {
        int ch;
        while (ch = cin.get())
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
        }
    }
}

void Lottery::department_lottery()
{

}

void Lottery::team_lottery()
{

}


