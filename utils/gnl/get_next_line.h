/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:55:14 by afaris            #+#    #+#             */
/*   Updated: 2022/04/09 15:22:17 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 11

void	free_buffers(char **rest);
int		get_length(char *str, char c);
char	*join_buffers(char **rest, char *buff);
void	save_rest(char **rest, char *buff, int pos);
void	save_rest_st(char **rest, int pos);
char	*get_next_line(int fd);

#endif
