#include "Lottery.h"
#include <iostream>
using namespace std;

int main()
{
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "son");
    lottery.AddStaff(1003, "小李", "三部", "mcp");
    lottery.AddStaff(1004, "小刚", "一部", "son");
    lottery.AddStaff(1005, "小玉", "二部", "ci");
    lottery.AddStaff(1006, "小马", "三部", "mcp");
    lottery.AddStaff(1007, "小刘", "一部", "ci");
    lottery.AddStaff(1008, "小白", "二部", "tool");

//    lottery.AddStaff(1009, "小天", "二部", "mcp");
//    lottery.DeleteStaff("小玉");
//    lottery.DoubleTeam("mcp");
//    lottery.DoubleStaff("小红");

    lottery.GobackLottery("NoGoback");

//    for (int i = 0; i < 100; ++i)
//    {
//        cout << endl;
//        cout << i << endl;
        cout << lottery.LotteryStart("first_prize", "一部", "") << endl;
        cout << lottery.LotteryStart("common_prize", "", "mcp") << endl;
        cout << lottery.LotteryStart("second_prize", "", "mcp") << endl;
        lottery.PrintStaff();
        lottery.GobackLottery("AllGoback");
//    }
    return 0;
}
