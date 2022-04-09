/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:14:57 by afaris            #+#    #+#             */
/*   Updated: 2022/04/08 10:10:58 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct cmdinfo{
	char	**cmds;
	char	*path;
	char	*cmd;
}	t_cmdinfo;

typedef struct args{
	char	**env_paths;
	char	**av;
	char	**env;
}	t_args;

typedef struct var{
	char	*tmp;
	int		i;
	int		j;
	int		npipe;
	int		ncmd;
	int		len;
	int		pos;
	int		infile;
	int		outfile;
	int		pre_arg;
}	t_var;

#endif