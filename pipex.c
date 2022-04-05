#include "pipex.h"

void    first_execution(var *v, int **fd, int infile)
{
    dup2(infile, 0);
    dup2(fd[v->i][1], 1);
    close(fd[v->i][0]);
}

void    last_execution(t_args a, var *v, int **fd, int ac)
{
    close(fd[v->i -1][1]);
    dup2(fd[v->i-1][0], 0);
    dup2(on_success(open(a.av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0777)), 1);
}

void    mid_executions(var *v, int **fd)
{
    dup2(fd[v->i][1], 1);
    close(fd[v->i][0]);
    close(fd[v->i - 1][1]);
    dup2(fd[v->i - 1][0], 0);
}

void    normal_execution(t_args a, int **fd, int ac)
{
    t_cmdinfo   ci;
    var         v;

    v.pos = 2;
    v.i = 0;
    v.j = on_success(open(a.av[1], O_RDONLY));
    while (v.pos < ac - 1)
    {
        set_cmdinfo(&ci, a, v.pos);
        if (fork() == 0)
        {
            if (v.pos - 1 == 1)
                first_execution(&v, fd, v.j);
            else if (v.pos + 1 == ac - 1)
                last_execution(a, &v, fd, ac);
            else
                mid_executions(&v, fd);
            execve(ci.path, ci.cmds, a.env);
        }
        close_fds(fd, v.i);
        v.i++;
        v.pos++;
    }
}

int main(int ac, char **av, char **env)
{
    t_args  args;
    var     v;
    int     **fd;

    fd = malloc(sizeof(int *) * (ac - 3));
    v.i = 0; 
    while (v.i < ac - 3)
    {
        fd[v.i] = malloc(sizeof(int) * 2);
        pipe(fd[v.i]);
        v.i++;
    }
    set_args(&args, av, env);
    normal_execution(args, fd, ac);
    v.i = 0;
    wait(NULL);
    while (v.i < ac - 3)
    {
        close(fd[v.i][0]);
        close(fd[v.i][1]);
        v.i++;
    }
}