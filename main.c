/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:35:43 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/20 10:38:01 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_pro(int *fd, int f1, char **av, char **envp)
{
	close (fd[0]);
	dup2(f1, STDINPUT_FILE);
	dup2(fd[1], STDOUT_FILE);
	close (f1);
	pars_exec_cmd1(av, envp);
}

void	child2_pro(int *fd, int f2, char **av, char **envp)
{
	close (fd[1]);
	dup2(fd[0], STDINPUT_FILE);
	dup2(f2, STDOUT_FILE);
	close (f2);
	pars_exec_cmd2(av, envp);
}

int	check_access(char *av, char **envp)
{
	char	**spltd_paths;
	char	**cmd_options;
	char	*access_par;
	int		i;
	int		ret;

	cmd_options = ft_split(av, ' ');
	spltd_paths = spltd(envp);
	i = 0;
	while (spltd_paths[i++])
	{
		access_par = ft_strjoin(spltd_paths[i], cmd_options[0]);
		ret = access(access_par, X_OK);
		if (ret == 0)
			return (0);
	}
	return (1);
}

void	pipex(int f1, int f2, char **av, char **envp)
{
	int	fd[2];
	int	pid;
	int	pid1;

	pipe(fd);
	if (check_access(av[2], envp) || check_access(av[3], envp))
		return (perror("command not found: "));
	pid = fork();
	if (pid == -1)
		return (perror("Fork: "));
	if (pid == 0)
		child1_pro(fd, f1, av, envp);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Fork: "));
	if (pid1 == 0)
		child2_pro(fd, f2, av, envp);
	close (fd[0]);
	close (fd[1]);
	waitpid (pid, NULL, 0);
	waitpid (pid1, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	if (ac > 2)
	{
		f1 = open(av[1], O_RDONLY);
		f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 < 0 || f2 < 0)
			return (0);
		pipex(f1, f2, av, envp);
		return (0);
	}
	else
		return (-1);
}
