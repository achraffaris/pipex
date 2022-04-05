# ifndef STRUCT_VARIABLES_H
# define STRUCT_VARIABLES_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct cmdinfo{
    char **cmds;
    char *path;
    char *cmd;
} t_cmdinfo;

typedef struct args{
    char **env_paths;
    char **av;
    char **env;
} t_args;

typedef struct var{
    char *tmp;
    int i;
    int j;
    int npipe;
    int ncmd;
    int len;
    int pos;
} var;

# endif