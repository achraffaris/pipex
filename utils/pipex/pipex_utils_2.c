/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:20:30 by afaris            #+#    #+#             */
/*   Updated: 2022/04/07 15:30:59 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_exit(char	*err_msg)
{
	if (err_msg)
		perror(err_msg);
	else
		perror(0);
	exit(0);
}

void	close_fds(int **fd, int i)
{
	int	j;

	j = 0;
	while (j <= i - 1)
	{
		close(fd[j][0]);
		close(fd[j][1]);
		j++;
	}
}

int	on_success(int id)
{
	if (id == -1)
		ft_exit(0);
	return (id);
}

int	**allocate_fds(int npipes)
{
	int **fd;
	int i;
	
	i = 0;
	fd = malloc(sizeof(int *) * (npipes));
	if (!fd)
		ft_exit(0);
	i = 0;
	while (i < npipes)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
		i++;
	}
	return (fd);
}

void	close_free_fds(int **fd, int npipes)
{
	int i;

	i = 0;
	while (i < npipes)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
		i++;
	}
	free(fd);
}