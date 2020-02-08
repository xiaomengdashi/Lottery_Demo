#include <iostream>
#include "Lottery.h"

using namespace std;

int main()
{
    Lottery lottery;
    lottery.AddStaff(111, "小明", "一部", "mcp");
    lottery.AddStaff(222, "小红", "二部", "son1");
    lottery.AddStaff(333, "小李", "三部", "mcp");
    lottery.AddStaff(444, "小刚", "一部", "son2");
    lottery.AddStaff(555, "小玉", "二部", "ci");
    lottery.AddStaff(666, "小马", "三部", "mcp");
    lottery.AddStaff(777, "小刘", "二部", "ci");
    lottery.AddStaff(888, "小白", "一部", "tool");
    lottery.AddStaff(999, "小王", "二部", "son");


//    lottery.DobuleStaff("小明");
//    lottery.DobuleTeam("mcp");
//    lottery.DeleteStaff("小王");

    lottery.LotteryStart(false, "", "");
    lottery.LotteryStart(true, "", "");
    lottery.LotteryStart(false, "一部", "");
    lottery.LotteryStart(false, "", "mcp");


    lottery.PrintStaff();

    return 0;
}
