#include "pipex.h"
/*
void    set_args(t_args *a, char **av, char **env)
{
    a->av = av;
    a->env = env;
    a->env_paths = get_paths(env);
}

void    set_cmdinfo(t_cmdinfo *ci, t_args a, int pos)
{
    ci->cmds = ft_split(a.av[pos], ' ');
    ci->cmd = ft_strjoin(ci->cmds[0], "");
    ci->path = get_path_or_none(a.env_paths, ci->cmd);
}

int is_here_doc(char *str)
{
    char *tmp;
    int i;

    i = 0;
    tmp = "here_doc";
    while (str[i])
    {
        if (str[i] != tmp[i])
            return (0);
        i++;
    }
    return (1);
}

int on_success(int id)
{
    if (id == -1)
    {
        perror(0);
        exit(0);
    }
    return (id);
}

void    first_execution(t_args a, var *v, int **fd, int in)
{
    dup2(in, 0);
    dup2(fd[v->i][1], 1);
    close(fd[v->i][0]);
}

void    last_execution(t_args a, var *v, int **fd, int ac)
{
    close(fd[v->i -1][1]);
    dup2(fd[v->i-1][0], 0);
    dup2(on_success(open(a.av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0777)), 1);
}

void    mid_executions(t_args a, var *v, int **fd)
{
    dup2(fd[v->i][1], 1);
    close(fd[v->i][0]);
    close(fd[v->i - 1][1]);
    dup2(fd[v->i - 1][0], 0);
}

void    close_fds(int **fd, int i)
{
    int j;

    j = 0;
    while (j <= i - 1)
    {
        close(fd[j][0]);
        close(fd[j][1]);
        j++;
    }
}

void    normal_execution(t_args a, int **fd, int ac, int in)
{
    t_cmdinfo   ci;
    var         v;

    v.pos = 2;
    v.i = 0;
    while (v.pos < ac - 1)
    {
        set_cmdinfo(&ci, a, v.pos);
        if (fork() == 0)
        {
            if (v.pos - 1 == 1)
                first_execution(a, &v, fd, in);
            else if (v.pos + 1 == ac - 1)
                last_execution(a, &v, fd, ac);
            else
                mid_executions(a, &v, fd);
            execve(ci.path, ci.cmds, a.env);
        }
        close_fds(fd, v.i);
        v.i++;
        v.pos++;
    }
}

void    here_doc(t_args a, int **fd, int ac)
{
    int in;
    char *tmp;
    int fdt[2];
    int i;

    i = 0;
    pipe(fdt);
    if (fork() == 0)
    {
        tmp = get_next_line(0);
        while(strcmp(tmp, a.av[2]) && i++ < 5)
        {
            tmp = get_next_line(0);
            write(fdt[1], tmp, get_length(tmp, 0));
        }
        close(fdt[0]);
        exit(0);
    }
    close(fdt[1]);
    in = fdt[0];
    
    normal_execution(a, fd, ac, in);
}

int main(int ac, char **av, char **env)
{
    t_args  args;
    var     v;
    int     **fd;
    int     in;
    fd = malloc(sizeof(int *) * (ac - 3));
    v.i = 0; 
    while (v.i < ac - 3)
    {
        fd[v.i] = malloc(sizeof(int) * 2);
        pipe(fd[v.i]);
        v.i++;
    }
    set_args(&args, av, env);
    if (is_here_doc(av[1]))
        here_doc(args, fd, ac);
    else
    {
        in = open(av[1], O_RDONLY);
        normal_execution(args, fd, ac, in);
    }
        
    v.i = 0;
    wait(NULL);
    while (v.i < ac - 3)
    {
        close(fd[v.i][0]);
        close(fd[v.i][1]);
        v.i++;
    }
}
*/