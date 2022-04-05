#include "string_utils.h"

char    *allocate_str(char **arr, char *str, char sep)
{
    char *tmp;
    int i;

    i = 0;
    tmp = malloc(sizeof(char) * get_length(str, sep) + 1);
    if (!tmp)
    {
        free_2d_array(arr);
        return (0);
    }
    while (str[i] != sep && str[i])
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char **ft_split(char *str, char sep)
{
    char **arr;
    var v;

    v.i = 0;
    v.j = 0;
    v.len = word_count(str, sep);
    v.pos = 0;
    arr = malloc(sizeof(char *) * (v.len + 1));
    if (!arr || !str)
        return (0);
    arr[v.len] = NULL;
    while (str[v.i] && v.j < v.len)
    {
        if (str[v.i] == sep || str[v.i + 1] == '\0')
        {
            arr[v.j] = allocate_str(arr, &str[v.pos], sep);
            v.j++;
            v.pos = v.i + 1;
        }
        v.i++;
    }
    return (arr);
}