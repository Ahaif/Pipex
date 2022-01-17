/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:54:23 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/20 10:40:02 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_path(char **envp)
{
	char	*path_from_envp;
	int		i;

	i = 0;
	while (envp[i])
	{
		path_from_envp = ft_strnstr(envp[i], "PATH=", 6);
		if (!path_from_envp)
			i++;
		else
		{
			path_from_envp
				= ft_substr(path_from_envp, 5, ft_strlen(path_from_envp) - 5);
			break ;
		}
	}
	return (path_from_envp);
}

void	pars_exec_cmd2(char **av, char **envp)
{
	char	*path_from_envp;
	char	**spltd_paths;
	char	**cmd_options;
	char	*execve_par;
	int		i;

	path_from_envp = get_path(envp);
	cmd_options = ft_split(av[3], ' ');
	spltd_paths = ft_split(path_from_envp, ':');
	i = 0;
	while (spltd_paths[i++])
	{
		execve_par = ft_strjoin(spltd_paths[i], cmd_options[0]);
		execve(execve_par, cmd_options, envp);
		free (execve_par);
	}
	return (perror ("execve error: "));
}

void	pars_exec_cmd1(char **av, char **envp)
{
	char	*path_from_envp;
	char	**spltd_paths;
	char	**cmd_options;
	char	*execve_par;
	int		i;

	path_from_envp = get_path(envp);
	cmd_options = ft_split(av[2], ' ');
	spltd_paths = ft_split(path_from_envp, ':');
	i = 0;
	while (spltd_paths[i++])
	{
		execve_par = ft_strjoin(spltd_paths[i], cmd_options[0]);
		execve(execve_par, cmd_options, envp);
		free (execve_par);
	}
	return (perror ("execve error: "));
}

char	**spltd(char **envp)
{
	char	*path_from_envp;
	char	**spltd;

	path_from_envp = get_path(envp);
	spltd = ft_split(path_from_envp, ':');
	return (spltd);
}
