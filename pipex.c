/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:28:49 by afaris            #+#    #+#             */
/*   Updated: 2022/04/12 12:21:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_execution(t_var *v, int **fd, int infile)
{
	dup2(infile, 0);
	dup2(fd[v->i][1], 1);
	close(fd[v->i][0]);
}

void	last_execution(t_args a, t_var *v, int **fd, int ac)
{
	close(fd[v->i - 1][1]);
	dup2(fd[v->i - 1][0], 0);
	dup2(on_success(open(a.av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0777)), 1);
}

void	mid_executions(t_var *v, int **fd)
{
	dup2(fd[v->i][1], 1);
	close(fd[v->i][0]);
	close(fd[v->i - 1][1]);
	dup2(fd[v->i - 1][0], 0);
}

void	normal_execution(t_args a, int **fd, int ac)
{
	t_cmdinfo	ci;
	t_var		v;

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
		free_cmdinfo(&ci);
		v.i++;
		v.pos++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_args	args;
	int		**fd;
	int		i;

	i = 2;
	fd = allocate_fds(ac - 4);
	if (ac != 5)
		return (0);
	set_args(&args, av, env);
	normal_execution(args, fd, ac);
	while (i < ac - 1)
	{
		wait(0);
		i++;
	}
	close_free_fds(fd, ac - 4);
	free_2d_array(args.env_paths);
}
