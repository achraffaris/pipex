/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:24:33 by afaris            #+#    #+#             */
/*   Updated: 2022/04/07 12:38:28 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

int	get_length(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != c && str[i])
		i++;
	return (i);
}

int	word_count(char *str, char sep)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (str && str[i])
	{
		if (str[i] == sep)
			c++;
		i++;
	}
	return (c);
}

int	start_with(char *str, char *ptr)
{
	int	i;
	int	str_len;

	str_len = get_length(str, '\0');
	i = 0;
	while (ptr[i] == str[i])
		i++;
	if (i == str_len)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * get_length(s1, 0) + get_length(s2, 0) + 1);
	if (!tmp || !s1)
		return (0);
	while (s1 && s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
