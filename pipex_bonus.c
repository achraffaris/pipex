/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:29:58 by afaris            #+#    #+#             */
/*   Updated: 2022/04/12 10:56:58 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_execution(t_var *v, int **fd)
{
	dup2(v->infile, 0);
	dup2(fd[v->i][1], 1);
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

void	normal_execution(t_args a, int **fd, int ac, t_var *v)
{
	t_cmdinfo	ci;
	int			pos;

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
	if (ac < 5)
		return (0);
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
