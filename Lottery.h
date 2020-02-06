//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#include <string>
#include <vector>

using namespace std;

struct sta
{
    int id = 0;   // 编号
    int job_number = 0;
    string name = "";
    string department = "";
    string team = "";
    bool is_win = false;  // 是否曾经中奖
};

class Lottery
{
public:
    Lottery();
    ~Lottery();
    void AddStaff(int job_number, string name, string department, string team);
    void DeleteStaff(string name);
    void PrintStaff();    // 打印全体员工信息
    void LotteryStart(bool flag, const string& department="", const string& team="");

    void AllStaffLottery();  // 全体员工抽奖
    void NotRepeatLottery();  // 还未中奖员工抽奖
    void DepartmentLottery(const string& department);  // 指定部门抽奖
    void TeamLottery(const string& team);              // 指定团队抽奖

    void DobuleStaff(const string& name="");    // 优秀个人翻倍抽奖
    void DobuleTeam(const string& team="");     // 优秀团队翻倍抽奖

    friend int GetRandomNum(int num_max);

private:
    vector<sta> staff_;
    int staff_num_ = 0;
};
#endif //LOTTERY_LOTTERY_H
