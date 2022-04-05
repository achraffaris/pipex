/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:24:33 by afaris            #+#    #+#             */
/*   Updated: 2022/04/05 10:24:53 by afaris           ###   ########.fr       */
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
