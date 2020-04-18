
 // Created by kolane on 2020/2/6.

#include "Lottery.h"
#include "gtest/gtest.h"

 TEST(LettryTest, AddStaffTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, DeleteStaffTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.AddStaff(1002, "小红", "二部", "son");
     lottery.DeleteStaff("小明");
     EXPECT_TRUE("小红" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, DoubleTeamTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.DoubleTeam("mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, DoubleStaffTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.DoubleStaff("小明");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, NoGobackTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.LotteryStart("first_prize");
     lottery.GobackLottery();
     lottery.AddStaff(1001, "小红", "二部", "mcp");
     EXPECT_TRUE("小红" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, AllGobackTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.LotteryStart("first_prize");
     lottery.GobackLottery("AllGoback");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, SuperPrizeGobackTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.LotteryStart("common_prize");
     lottery.GobackLottery("SuperPrizeGoback");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, DepartmentTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.LotteryStart("common_prize");
     lottery.GobackLottery("SuperPrizeGoback");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, TeamTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     lottery.LotteryStart("common_prize");
     lottery.GobackLottery("SuperPrizeGoback");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, FirstPrizeTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

 TEST(LettryTest, SecondPrizeTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("second_prize"));
 }

 TEST(LettryTest, ThirdPrizeTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("third_prize"));
 }

 TEST(LettryTest, CommonPrizeTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("common_prize"));
 }

 TEST(LettryTest, SuperPrizeTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("super_prize"));
 }