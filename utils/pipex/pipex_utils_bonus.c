/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:03:25 by afaris            #+#    #+#             */
/*   Updated: 2022/04/12 12:39:58 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	is_here_doc(char *str)
{
	char	*tmp;
	int		i;

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

int	here_doc(t_args a)
{
	char	*tmp;
	int		fd[2];

	pipe(fd);
	if (fork() == 0)
	{
		tmp = get_next_line(0);
		while (1)
		{
			write(fd[1], tmp, get_length(tmp, 0));
			if (ft_strcmp(tmp, ft_strjoin(a.av[2], "\n")) == 0)
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

t_var	setup_variables(t_args a, int ac)
{
	t_var	v;

	if (is_here_doc(a.av[1]))
	{
		v.infile = here_doc(a);
		v.outfile = on_success(open(a.av[ac - 1],
					O_CREAT | O_APPEND | O_RDWR, 0644));
		v.pos = 3;
		v.npipe = ac - 5;
		v.ncmd = ac - 4;
		v.pre_arg = 2;
	}
	else
	{
		v.infile = on_success(open(a.av[1], O_RDONLY));
		v.outfile = on_success(open(a.av[ac - 1],
					O_CREAT | O_TRUNC | O_RDWR, 0644));
		v.pos = 2;
		v.npipe = ac - 4;
		v.ncmd = ac - 3;
		v.pre_arg = 1;
	}
	return (v);
}
