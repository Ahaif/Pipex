/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:44:49 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/12/17 12:08:10 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define STDOUT_FILE 1
# define STDINPUT_FILE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

void	child1_pro(int *fd, int f1, char **av, char **envp);
void	child2_pro(int *fd, int f2, char **av, char **envp);
void	pars_exec_cmd2(char **av, char **envp);
void	pars_exec_cmd1(char **av, char **envp);
void	pipex(int f1, int f2, char **av, char **envp);
char	*get_path(char **envp);
char	**spltd(char **envp);
#endif
