#include "lab1.h"

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
