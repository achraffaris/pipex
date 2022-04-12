/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:20:45 by afaris            #+#    #+#             */
/*   Updated: 2022/04/09 15:12:19 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include "../utils.h"

char	**get_paths(char **env);
int		command_exists(char *path, char *cmd);
char	*get_path_or_none(char **paths, char *cmd);
void	close_fds(int **fd, int i);
int		on_success(int id);
void	set_args(t_args *a, char **av, char **env);
void	set_cmdinfo(t_cmdinfo *ci, t_args a, int pos);
void	ft_exit(char *err_msg);
int		**allocate_fds(int npipes);
void	close_free_fds(int **fd, int npipes);
int		is_here_doc(char *str);
int		here_doc(t_args a);
t_var	setup_variables(t_args a, int ac);

#endif