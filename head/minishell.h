/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:14:41 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/14 13:30:51 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 32
#include "get_next_line.h"
#include "structures.h"
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
int pwd(int fd);
int echo(char **tab, int fd);
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
int split_r_output(char *line, t_r_output *out);
void    close_output(t_r_output *out);

#endif
