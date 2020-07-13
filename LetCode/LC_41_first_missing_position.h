#ifndef LC_41_FIRST_MISSING_POSITION_H
#define LC_41_FIRST_MISSING_POSITION_H

#include <stdlib.h>
#include <stdio.h>

/*
���������е�һ��ȱʧ������λ��
*/

int firstMissingPosition(int* numList, int numSize)
{
        for (int i = 0; i < numSize; ++i)
        {
                while (numList[i] >= 1 && numList[i] <= numSize && numList[i] != numList[numList[i] - 1])
                {//Ŀ���ǽ�ֵ�ŵ���iֵ���1��λ����
                        int tmp = numList[i];
                        numList[i] = numList[tmp - 1];
                        numList[tmp - 1] = tmp;
                }
        }
        int isNum = numSize + 1;
        for (int i = 0; i < numSize; ++i)
        {
                if (numList[i] != i + 1)
                {
                        isNum = i + 1;
                        break;
                }
        }
        return isNum;
}

void test41(void)
{
        int numList[] = { 1, 5, 7, 4, -6, 9, 0, 3, 4 };
        int isNum = firstMissingPosition(numList, 9);
        printf("The isNum is: %d\n", isNum);
}

#endif