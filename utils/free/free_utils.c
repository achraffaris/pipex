/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:11:56 by afaris            #+#    #+#             */
/*   Updated: 2022/04/07 12:28:57 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_utils.h"

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
}

void	free_array(char *arr)
{
	if (arr)
	{
		free(arr);
		arr = 0;
	}
}

void	free_cmdinfo(t_cmdinfo *ci)
{
	free_2d_array(ci->cmds);
	free_array(ci->cmd);
	free_array(ci->path);
}