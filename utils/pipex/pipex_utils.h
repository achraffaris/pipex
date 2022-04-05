#ifndef PIPEX_UTILS_H
#define PIPEX_UTILS_H

#include "../utils.h"

char    **get_paths(char **env);
int     command_exists(char *path, char *cmd);
char    *get_path_or_none(char **paths, char *cmd);
void    close_fds(int **fd, int i);
int     on_success(int id);
void    set_args(t_args *a, char **av, char **env);
void    set_cmdinfo(t_cmdinfo *ci, t_args a, int pos);
void    ft_exit(char *err_msg);

#endif