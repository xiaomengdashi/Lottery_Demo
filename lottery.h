//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#define MAX 20

class Lottery
{
public:
    void select(int *people,int count);
    static void show(int *show,int count);
    int lottery();

private:
    int FLAG[MAX];
    int count;
};


#endif //LOTTERY_LOTTERY_H
