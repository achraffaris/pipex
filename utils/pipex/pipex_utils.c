#include "pipex_utils.h"

char    *get_path_or_none(char **paths, char *cmd)
{
    var v;

    v.i = 0;
    if (!cmd)
        return (NULL);
    v.tmp = ft_strjoin("/", cmd);
    while(paths[v.i])
    {
        if (command_exists(paths[v.i], v.tmp))
            return (ft_strjoin(paths[v.i], v.tmp));
        v.i++;
    }
    return (NULL);
}

char    **get_paths(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (start_with("PATH=", env[i]))
            return (ft_split(&env[i][5], ':'));
        i++;
    }
    return 0;
}

int command_exists(char *path, char *cmd)
{
    char    *cmd_path;

    cmd_path = ft_strjoin(path, cmd);
    if (access(cmd_path, X_OK) == 0)
        return (1);
    return (0);
}

void    set_args(t_args *a, char **av, char **env)
{
    a->av = av;
    a->env = env;
    a->env_paths = get_paths(env);
    if (!a->env_paths)
        ft_exit("ENV PATH DOES NOT EXISTS");
}

void    set_cmdinfo(t_cmdinfo *ci, t_args a, int pos)
{
    ci->cmds = ft_split(a.av[pos], ' ');
    ci->cmd = ft_strjoin(ci->cmds[0], "");
    ci->path = get_path_or_none(a.env_paths, ci->cmd);
    if (!ci->path)
        ft_exit("COMMAND NOT FOUND!");
}