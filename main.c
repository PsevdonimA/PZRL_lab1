#include <stdio.h>
#include <string.h>
#include "lab1.h"

int main(int argc, char** argv)
{
    int len = 0;
    for (int i = 1; i < argc; i++)
    {
        len = strlen(argv[i]);
        printf("%d\n", type_check(argv[i], len));
    }
    return 0;
}
