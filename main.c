#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab1.h"

int main(int argc, char** argv)
{
    int arg_len = argc - 1; // number of useful arguments
    int* types = (int*)malloc(arg_len * sizeof(int)); // array of types for arguments

    int len = 0; // buffer
    for (int i = 0; i < arg_len; i++)
    {
        len = strlen(argv[i+1]);
        types[i] = type_check(argv[i+1], len);
    }
    int ans_len = order_check(types, arg_len); // number of answers
    if (ans_len == -1)
    {
        printf("Incorrect arguments or their number!\n");
        printf("Correct example:\n41 + 33 111 - 8 22 \\* 5 221 %c 111 -k 2\n", '%');
        printf("Write \\ before *!\n");
    }
    else if (ans_len == 0)
    {
        printf("Arguments correct, but there is 0 questions.\n");
    }
    else
    {
        int key = atoi(argv[arg_len]);
        int* ans_arr = (int*)malloc(ans_len * sizeof(int));
        int pos = 0; // position of index
        for (int i = 0; i < ans_len; i++)
        {
            pos = (3 * i) + 1;
            ans_arr[i] = get_ans(atoi(argv[pos]), argv[pos+1][0], atoi(argv[pos+2]));
            printf("Ответ №%d: %d\n", i+1, ans_arr[i]);
        }
        print_result(ans_arr, ans_len, key);
        free(ans_arr);
    }
    free(types);
    return 0;
}
