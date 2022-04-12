/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:25:40 by afaris            #+#    #+#             */
/*   Updated: 2022/04/09 15:18:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include "../utils.h"

int		get_length(char *str, char c);
int		word_count(char *str, char sep);
char	**ft_split(char *str, char sep);
int		start_with(char *str, char *ptr);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

#endif