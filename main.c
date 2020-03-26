/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:09:19 by delacourt         #+#    #+#             */
/*   Updated: 2020/03/13 17:26:18 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_new_line()
{
	char c[] = "&> ";
	char *str;
	int i;
	int j;

	write(1, c, 3);
	str = getcwd(NULL, 0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			++j;
		++i;
	}
	if (j > 1)
	{
		while (str[i] != '/' && i >= 0)
			--i;
		++i;
		ft_putstr_fd("\033[1;36m", 1);
		write(1, &str[i], ft_strlen(&str[i]));
		ft_putstr_fd("\033[0m", 1);
		write(1, ": ", 2);
	}
	else
	{
		ft_putstr_fd("\033[1;31m", 1);
		write(1, str, ft_strlen(str));
		ft_putstr_fd("\033[0m", 1);
		write(1, ": ", 2);
	}
	free(str);
}

int is_broken_quote(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
		{
			++i;
			while (line[i] != '\"' && line[i] != '\0')
			{
				if (line[i] == '\\')
					++i;
				++i;
			}
		}
		else if (line[i] == '\'')
		{
			++i;
			while (line[i] != '\'' && line[i] != '\0')
			{
				
				if (line[i] == '\\' && line[i + 1] != '\'')
					++i;
				++i;
			}
		}
		else if (line[i] == '\\')
			++i;
		if (line[i] == '\0')
			return (1);
		++i;
	}
	return (0); // a changer
}

int parse_exec(char *line)
{
	char **tab;
	int i;

	i = is_broken_quote(line);
	if (i != 0)
	{
		printf("broken pipe\n");
		return (i);
	}
	tab = ft_enhanced_split(line);
	if (ft_strncmp(tab[0], "echo", 5) == 0 || ft_strncmp(tab[0], "cd", 3) == 0 || ft_strncmp(tab[0], "pwd", 4) == 0
	|| ft_strncmp(tab[0], "export", 7) == 0 || ft_strncmp(tab[0], "unset", 6) == 0 || ft_strncmp(tab[0], "env", 4) == 0
	|| ft_strncmp(tab[0], "exit", 5) == 0 || ft_strncmp(tab[0], "cd", 3) == 0)
	{
		if (ft_strncmp("echo", tab[0], 5) == 0)
			echo(&tab[1]);
		else if (ft_strncmp("pwd", tab[0], 4) == 0)
			pwd();
		else if (ft_strncmp("exit", tab[0], 5) == 0)
			end(tab);
		else if (ft_strncmp("cd", tab[0], 3) == 0)
			cd(&tab[1]);
	}
	else
	{
		search_and_exec(tab);
	}
	free_arr(tab, i);
	return (i);
}

int main(int argc, char **argv, char **envp)
{
	int i;
    char *line;
	char *path;

	signal(SIGINT, sighandler);
    print_new_line();
	while (1)
    {
        i = get_next_line(0, &line);
		if (i >= 0 && line[0] == 0) //pour pas segfault plus loin !!!!!!NE GERE PAS LE CTRLD
			;
		else if (parse_exec(line) == 1)
			;
		print_new_line();
	}
    return (0);
}
