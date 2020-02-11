//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#include <string>
#include <vector>
#include "Staff.h"

using namespace std;

class Lottery
{
public:
    Lottery();
    ~Lottery();
    void AddStaff(int job_number, string name, string department, string team);  // 增加员工
    void DeleteStaff(const string& name);    // 剔除指定员工
    void PrintStaff();    // 打印全体员工信息
    int GetRandomNum();   // 根据权重获取随机数
    void GobackLottery();   // 中奖人员回归奖池

    string AllStaffLottery();  // 全体员工抽奖
    string NotRepeatLottery();  // 还未中奖员工抽奖
    string DepartmentLottery(const string& department);  // 指定部门抽奖
    string TeamLottery(const string& team);              // 指定团队抽奖

    void DobuleStaff(const string& name="");    // 优秀个人翻倍抽奖
    void DobuleTeam(const string& team="");     // 优秀团队翻倍抽奖

private:
    vector<sta> staff_;
    int staff_num_ = 0;
};
#endif //LOTTERY_LOTTERY_H
