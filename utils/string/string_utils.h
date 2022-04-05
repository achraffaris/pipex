# ifndef STRING_UTILS_H
# define STRING_UTILS_H

#include "../utils.h"

int     get_length(char *str, char c);
int     word_count(char *str, char sep);
char    **ft_split(char *str, char sep);
int     start_with(char *str, char *ptr);
char    *ft_strjoin(char *s1, char *s2);

# endif