#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define QUOTIETY 4
using namespace std;
int cnt = 1;
void multiply(const int index, int *result)
{
    int product = 0;
    int carry = 0;
    int remainder = 0;
    int i = 0;
    for (i = 0; i < cnt; ++i)
    {
        product = result[i] * index + carry;
        carry = product / 10;
        remainder = product % 10;
        result[i] = remainder;
    }
    if (carry != 0)
    {
        while (carry / 10 != 0)
        {
            result[cnt] = carry % 10;
            carry /= 10;
            ++cnt;
        }
        result[cnt++] = carry;
    }
}
int main()
{
    int index = 0;
    int input = 0;
    int *result = NULL;
    scanf("%d", &input);
    result = new int [sizeof(int) * input * QUOTIETY];
    memset(result, 0, sizeof(int) * input * QUOTIETY);
    result[0] = 1;
    for (index = 1; index <= input; ++index)
        multiply(index, result);
    for (index = cnt - 1; index >= 0L; --index)
        printf("%d", result[index]);
    delete []result;
    system("pause");
    return 0;
}