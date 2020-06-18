#ifndef SUM_OF_N_H
#define SUM_OF_N_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
求取1到n的和，不用乘除，循环和判断
*/

typedef unsigned int(*fun)(unsigned int);

unsigned int Solution_Terminator(unsigned int n)
{
        return 0;
}

unsigned int Sum_Solution(unsigned int n)
{
        static fun f[2] = { Solution_Terminator, Sum_Solution };
        return n + f[!!n](n - 1);
}

void test_n(void)
{
        int result = Sum_Solution(4);
        printf("result is: %d", result);
}
#endif