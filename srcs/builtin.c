/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:08:36 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/09 16:08:36 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minishell.h"

int echo(char **tab, int fd)
{
	int i;
	int is_n;

	i = 0;
	is_n = 0;
	if (ft_strncmp(tab[0], "-n", 2) == 0)
	{
		is_n = 1;
		i = 1;
	}
	while (tab[i] != NULL)
	{
		write(fd, tab[i], ft_strlen(tab[i]));
		++i;
		if (tab[i] != NULL)
			write(fd, " ", 1);
	}
	if (is_n == 0)
	write(fd, "\n", 1);
	return (0);
}

int pwd(int fd)
{
	char *str;

	str = getcwd(NULL, 0);
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
	free(str);
	return (1);
}

void end(char **tab)
{
	int i;

	i = 0;
	while(tab[i] != NULL)
		++i;
	free_arr(tab, i);
	exit(0);
}

int cd(char **tab)
{
	int i;

	i = chdir(tab[0]);
	if (i == -1)
	{
		write(1, "mash: cd: ", 10);
		write(1, tab[0], ft_strlen(tab[0]));
		write(1, ": No such file or directory\n", 28);
	}
	return (1);
}
