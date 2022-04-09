/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:21:55 by afaris            #+#    #+#             */
/*   Updated: 2022/04/07 13:15:24 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*get_path_or_none(char **paths, char *cmd)
{
	t_var	v;
	char	*re;
	char	*tmp;

	v.i = 0;
	if (!cmd)
		return (NULL);
	tmp = ft_strjoin("/", cmd);
	while (paths[v.i])
	{
		if (command_exists(paths[v.i], tmp))
		{
			re = ft_strjoin(paths[v.i], tmp);
			free_array(tmp);
			return (re);
		}
		v.i++;
	}
	
	free_array(tmp);
	return (NULL);
}

char	**get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (start_with("PATH=", env[i]))
			return (ft_split(&env[i][5], ':'));
		i++;
	}
	return (0);
}

int	command_exists(char *path, char *cmd)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(path, cmd);
	if (access(cmd_path, X_OK) == 0)
	{
		free_array(cmd_path);
		return (1);
	}
	free_array(cmd_path);
	return (0);
}

void	set_args(t_args *a, char **av, char **env)
{
	a->av = av;
	a->env = env;
	a->env_paths = get_paths(env);
	if (!a->env_paths)
		ft_exit("ENV PATH DOES NOT EXISTS");
}

void	set_cmdinfo(t_cmdinfo *ci, t_args a, int pos)
{
	ci->cmds = ft_split(a.av[pos], ' ');
	ci->cmd = ft_strjoin(ci->cmds[0], 0);
	ci->path = get_path_or_none(a.env_paths, ci->cmd);
	
	if (!ci->path)
		ft_exit("COMMAND NOT FOUND!");
}
