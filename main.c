#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab1.h"

int main(int argc, char** argv)
{
    int arg_len = argc - 1;
    int* types = (int*)malloc(arg_len * sizeof(int));

    int len = 0; // buffer
    for (int i = 0; i < arg_len; i++)
    {
        len = strlen(argv[i+1]);
        types[i] = type_check(argv[i+1], len);
        printf("%d\n", types[i]);
    }
    printf("%d\n", order_check(types, arg_len));
    free(types);
    return 0;
}
