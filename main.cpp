#include "Lottery.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main()
{
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "son");
    lottery.AddStaff(1003, "小李", "三部", "ci");
//    lottery.AddStaff(1004, "小刚", "一部", "son");
//    lottery.AddStaff(1005, "小玉", "二部", "ci");
//    lottery.AddStaff(1006, "小马", "三部", "mcp");
//    lottery.AddStaff(1007, "小刘", "一部", "ci");
//    lottery.AddStaff(1008, "小白", "二部", "tool");

    lottery.DobuleStaff("小明");
    lottery.DobuleTeam("mcp");
//    lottery.DeleteStaff("小王");

//    cout << lottery.AllStaffLottery() << endl;
//    cout << lottery.NotRepeatLottery() << endl;
//    cout << lottery.DepartmentLottery("一部") << endl;
//    cout << lottery.TeamLottery("mcp") << endl;
//
//    lottery.PrintStaff();

    int r=0,w=0,e=0;
    for (int i=0; i<1000; i++)
    {
        string s = lottery.AllStaffLottery();
        if (s == "小明")
        {
            r++;
        } else if (s == "小红")
        {
            w++;
        } else if (s == "小李")
            e++;
        }
    cout << r <<"  "<< w << "  " << e<< endl;
    return 0;
}
