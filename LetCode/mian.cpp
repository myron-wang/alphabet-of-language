#include <stdlib.h>
#include <stdio.h>
#include "LC_119_pascals_triangle.h"
#include <iostream>

using namespace std;

struct test 
{
        int a;
        int b[0];
};
class test0
{
public:
        int a;
        static int b;
};
int test0::b = 0;
int main(int argc, char** argv)
{
        int arr[16] = { 0 };
        struct test *temp = (struct test*)arr;
        temp->a = 1;
        temp->b[0] = 2;
        temp->b[1] = 3;
        //temp.b = arr;
        test119();
        test0 num_a, num_b;
        num_a.a = 0;
        num_a.b = 0;
        num_b.a = 0;
        num_b.b = 0;
        num_a.b++;
        num_b.b++;
        printf("a:%d\tb:%d\n", num_a.b, num_b.b);

}