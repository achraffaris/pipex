#include "string_utils.h"

int	get_length(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != c && str[i])
		i++;
	return (i);
}

int word_count(char *str, char sep)
{
    int i;
    int c;

    i = 0;
    c = 1;
    while (str && str[i])
    {
        if (str[i] == sep)
            c++;
        i++;
    }
    return (c);
}