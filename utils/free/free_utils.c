#include "free_utils.h"

void    free_2d_array(char **arr)
{
    int i;

    i = 0;
    while (arr && arr[i])
    {
        free(arr[i]);
        arr[i] = 0;
        i++;
    }
}

void    free_array(char *arr)
{
    if (arr)
    {
        free(arr);
        arr = 0;
    }
}
