/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:33:57 by afaris            #+#    #+#             */
/*   Updated: 2022/02/23 12:26:08 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffers(char **rest)
{
	if (rest)
	{
		free(*rest);
		*rest = 0;
	}
}

void	save_rest_st(char **rest, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (get_length(&rest[0][pos], 0) + 1));
	while (*rest && rest[0][pos])
		tmp[i++] = rest[0][pos++];
	tmp[i] = '\0';
	free_buffers(&(*rest));
	*rest = tmp;
}

void	save_rest(char **rest, char *buff, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	free_buffers(&(*rest));
	tmp = malloc(sizeof(char) * (get_length(&buff[pos], 0) + 1));
	while (buff && buff[pos])
		tmp[i++] = buff[pos++];
	tmp[i] = '\0';
	*rest = tmp;
}

char	*join_buffers(char **rest, char *buff)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buff && !*rest)
		return (0);
	tmp = malloc(sizeof(char) * (get_length(*rest, 0)
				+ get_length(buff, 0) + 1));
	if (!tmp)
		return (0);
	while (*rest && (*rest)[i])
	{
		tmp[i] = (*rest)[i];
		i++;
	}
	while (buff && buff[j])
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	free_buffers(&(*rest));
	return (tmp);
}
