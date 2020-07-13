#ifndef SUM_OF_TWO_NUM_H
#define SUM_OF_TWO_NUM_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NumIdxVal
{
public:
        int index;
        int value;
};

int* TestSumOfTwoNumber(int* numbers, int num_len, int target, int* ret_size);

int test(void);

#endif