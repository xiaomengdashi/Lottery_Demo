//
// Created by kolane on 2020/2/3.
//

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "lottery.h"

void Lottery::select(int *people,int count)
{
    int i=0,num;
    while(i<count)
    {
        num=rand()%MAX;
        if(FLAG[num] != 1)
        {
            printf("%d:%d  ",num+1,people[num]);
            FLAG[num] = 1;
            i++;
        }
    }
    putchar('\n');
}

void Lottery::show(int *show,int count)
{
    int i;
    for(i=0;i<count;i++)
    {
        printf("%-6d  ",show[i]);
        if(i%10 == 9)
            putchar('\n');
    }
    if(i%10 != 0)
        putchar('\n');
    putchar('\n');
}

int Lottery::lottery()
{
    int people[MAX],i;
    srand((unsigned int)time(NULL));
    for(i=0;i<MAX;i++)
    {
        people[i] = rand();
    }
    show(people,MAX);
    printf("\ninput the size you want to pick in %d people([ctr+z] to quit):",MAX-count);
    while(scanf("%d",&i) == 1)
    {
        if(i > MAX-count)i = MAX-count;
        select(people,i);
        count += i;
        if(count < MAX)
            printf("\ninput the size you want to pick in %d people([ctr+z] to quit):",MAX-count);
        else
            break;
    }
    putchar('\n');
    return 0;
}