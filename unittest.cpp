
 // Created by kolane on 2020/2/6.


#include "Lottery.h"
#include "/usr/local/include/gtest/gtest.h"

TEST(AllStaffTest, AddTest)
{
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    EXPECT_TRUE("小明" == lottery.AllStaffLottery());
}

TEST(AllStaffTest, DeleteTest)
{
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "mcp");
    EXPECT_TRUE("小明" == lottery.AllStaffLottery());
    lottery.DeleteStaff("小红");
    EXPECT_TRUE("小明" == lottery.AllStaffLottery());
 }


 TEST(AllStaffTest, DepartmentTest)
 {
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "mcp");
    EXPECT_TRUE("小明" == lottery.DepartmentLottery("一部"));
 }

 TEST(AllStaffTest, TeamTest)
 {
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "son");
     EXPECT_TRUE("小红" == lottery.TeamLottery("son"));
 }

 TEST(NotRepeatTest, AddTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.NotRepeatLottery());
     lottery.AddStaff(1002, "小红", "二部", "mcp");
     EXPECT_TRUE("小红" == lottery.NotRepeatLottery());
 }

 TEST(NotRepeatTest, DepartmentTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.NotRepeatLottery());
     lottery.AddStaff(1002, "小红", "二部", "mcp");
     lottery.AddStaff(1003, "小刚", "一部", "mcp");
     EXPECT_TRUE("小刚" == lottery.DepartmentLottery("一部"));
 }

 TEST(NotRepeatTest, TeamTest)
 {
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    EXPECT_TRUE("小明" == lottery.NotRepeatLottery());
    lottery.AddStaff(1002, "小红", "二部", "son");
    lottery.AddStaff(1002, "小白", "二部", "mcp");
    EXPECT_TRUE("小白" == lottery.TeamLottery("mcp"));
 }

 TEST(DobuleTest, TeamTest)
 {
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "son");
    lottery.AddStaff(1002, "小白", "二部", "mcp");
    lottery.DobuleStaff("小白");
    EXPECT_TRUE("小白" == lottery.AllStaffLottery());
 }

 TEST(DobuleTest, StaffTest)
 {
    Lottery lottery;
    lottery.AddStaff(1001, "小明", "一部", "mcp");
    lottery.AddStaff(1002, "小红", "二部", "son");
    lottery.AddStaff(1002, "小白", "二部", "mcp");
    lottery.DobuleTeam("son");
    EXPECT_TRUE("小白" == lottery.AllStaffLottery());
 }


 int main(int argc, char **argv)
 {
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
 }