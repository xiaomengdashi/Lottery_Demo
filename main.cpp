#include "Lottery.h"

int main()
{
    Lottery lottery;

    // 第一次输入前需要回车，当显示 "请输入员工的工号，姓名，部门，团队: "，后输入员工信息，
    // 输入完后，再次回车，如果还有员工，继续输入，
    // 当输入员工信息为 "q"时，结束输入。
    lottery.LotteryStart(false, "", ""); //全体员工抽奖
//    lottery.LotteryStart(true, "", "mcp"); // 抽取未中奖员工
//    lottery.LotteryStart(false, "一部", ""); // 抽取一部员工
//    lottery.LotteryStart(false, "", "mcp"); // 抽取mcp团队

    return 0;
}
