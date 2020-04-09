/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:14:41 by delacourt         #+#    #+#             */
/*   Updated: 2020/03/13 15:27:48 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 32
#include "get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

int cd(char **tab);
int pwd();
int echo(char **tab);
void end(char **tab);
void	*free_arr(char **tab, int j);
char	**ft_enhanced_split(char const *str);
void sighandler(int signum);
void print_new_line();
int exec_prog(char *line, char **argv, char **envp);
int search_and_exec(char **tab, char **envp);
char **split_semi_colon(char *line);
char **new_env(char **envp);
int env_len(char **env);

#endif
