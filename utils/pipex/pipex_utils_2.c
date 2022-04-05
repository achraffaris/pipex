/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:20:30 by afaris            #+#    #+#             */
/*   Updated: 2022/04/05 10:20:37 by afaris           ###   ########.fr       */
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
