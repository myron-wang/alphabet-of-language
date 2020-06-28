#include <stdlib.h>
#include <stdio.h>
#include "LC_141_circle_list.h"

using namespace std;

struct test 
{
        int a;
        int b[0];
};

int main(int argc, char** argv)
{
        int arr[16] = { 0 };
        struct test *temp = (struct test*)arr;
        temp->a = 1;
        temp->b[0] = 2;
        temp->b[1] = 3;
        //temp.b = arr;
        test141();
}