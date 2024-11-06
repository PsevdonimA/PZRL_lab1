#include "lab1.h"
#include <stdio.h>

const char signs[4] = {'+', '-', '*', '%'};
const char numbs[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int number_check(const char* str, const int len) // 0 - not number   1 - is number
{
    int next = 0; // ready to check next symbol
    for (int i = 0; i < len; i++)
    {
        next = 0;
        for (int j = 0; j < 10; j++)
        {
            if (str[i] == numbs[j])
            {
                next = 1;
                break;
            }
        }
        if (next == 0)
        {
            return 0;
        }
    }
    return 1;
}

int type_check(const char* str, const int len) // 0-unknown 1-number 2-sign 3-flag
{
    if (len == 2)
    {
        if (str[0] == '-' && str[1] == 'k')
        {
            return 3;
        }
    }
    else if (len == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (str[0] == signs[i])
            {
                return 2;
            }
        }
    }
    if (number_check(str, len) == 1)
    {
        return 1;
    }
    return 0;
}

int order_check(const int* mass, const int len) // if in right order returns number of answers, else return -1 
{
    if (len < 2 || ((len - 2) % 3 != 0))
    {
        return -1;   
    }
    if (mass[len-2] != 3 || mass[len-1] != 1)
    {
        return -1;
    }
    int c = 0; // counter
    for (int i = 0; i < len - 2; i += 3)
    {
        if (mass[i] == 1 && mass[i+1] == 2 && mass[i+2] == 1)
        {
            c += 1;
        }
        else
        {
            return -1;
        }
    }
    return c;
}

int get_ans(const int a, const char sign, const int b) // return answer
{
    if (sign == '+')
    {
        return a + b;
    }
    else if (sign == '-')
    {
        return a - b;
    }
    else if (sign == '*')
    {
        return a * b;
    }
    else if (sign == '%')
    {
        if (b == 0)
        {
            return 0;
        }
        return a % b;
    }
    return 0;
}

void print_result(const int* mass, const int len, const int key) // print result string
{
    int ch_num = 0; // number of char in ascii
    printf("Результирующая строка: ");
    for (int i = 0; i < len; i++)
    {
        ch_num = mass[i] - key;
        if (ch_num >= 0 && ch_num <= 255)
        {
            printf("%c", (char)ch_num);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}
