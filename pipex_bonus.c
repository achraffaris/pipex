/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:29:58 by afaris            #+#    #+#             */
/*   Updated: 2022/04/09 10:12:42 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_return(int re)
{
    if (re == -1)
        ft_exit(0);
}

void	first_execution(t_var *v, int **fd)
{
	check_return(dup2(v->infile, 0));
	check_return(dup2(fd[v->i][1], 1));
	close(fd[v->i][0]);
}

void	last_execution(t_var *v, int **fd)
{
	close(fd[v->i - 1][1]);
	dup2(fd[v->i - 1][0], 0);
	dup2(v->outfile, 1);
}

void	mid_executions(t_var *v, int **fd)
{
	dup2(fd[v->i][1], 1);
	close(fd[v->i][0]);
	close(fd[v->i - 1][1]);
	dup2(fd[v->i - 1][0], 0);
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

int    here_doc(t_args a)
{
    char *tmp;
    int fd[2];

    pipe(fd);
    if (fork() == 0)
    {
        tmp = get_next_line(0);
        while(1)
        {
            write(fd[1], tmp, get_length(tmp, 0));
            if (strcmp(tmp, ft_strjoin(a.av[2], "\n")) == 0)
                break ;
            tmp = get_next_line(0);
        }
        close(fd[0]);
        exit(0);
    }
    wait(0);
    close(fd[1]);
    return (fd[0]);
}

t_var    setup_variables(t_args a, int ac)
{
    t_var v;
    
    
    if (is_here_doc(a.av[1]))
    {
        v.infile = here_doc(a);
        v.outfile = on_success(open(a.av[ac - 1], O_CREAT | O_APPEND | O_RDWR, 0644));
        v.pos = 3;
        v.npipe = ac - 5;
        v.ncmd = ac - 4;
        v.pre_arg = 2;
    }
    else
    {
        v.infile = on_success(open(a.av[1], O_RDONLY));
        v.outfile = on_success(open(a.av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0644));
        v.pos = 2;
        v.npipe = ac - 4;
        v.ncmd = ac - 3;
        v.pre_arg = 1;
    }
    return v;
}

void	normal_execution(t_args a, int **fd, int ac, t_var *v)
{
	t_cmdinfo	ci;
    int         pos;

    pos = v->pos;
    v->i = 0;
	while (pos < ac - 1)
	{
		set_cmdinfo(&ci, a, pos);
		if (fork() == 0)
		{
			if (pos - 1 == v->pre_arg)
				first_execution(v, fd);
			else if (pos + 1 == ac - 1)
				last_execution(v, fd);
			else
				mid_executions(v, fd);
			execve(ci.path, ci.cmds, a.env);
		}
		close_fds(fd, v->i);
		free_cmdinfo(&ci);
		v->i++;
		pos++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_args	args;
	int		**fd;
    t_var	v;
	
    fd = 0;
    set_args(&args, av, env);
    v = setup_variables(args, ac);
	fd = allocate_fds(v.npipe);
    normal_execution(args, fd, ac, &v);
    v.pos = 2;
    while (v.pos < ac - 1)
    {
        wait(0);
        v.pos++;
    }
	close_free_fds(fd, v.npipe);
	free_2d_array(args.env_paths);
}
