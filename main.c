/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:09:19 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/01 10:12:29 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_new_line()
{
	char c[] = "&> ";

	write(1, c, 3);
}

int exec_prog(char *line, char **argv, char **envp)
{
	pid_t pid;

    pid = fork();
    if (pid == 0)
        execve(line, argv, envp);
    else
        wait(&pid);
    return (0);
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

int isbuiltin(char *line)
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
	if (ft_strncmp(tab[0], "echo", 4) == 0 || ft_strncmp(tab[0], "cd", 2) == 0 || ft_strncmp(tab[0], "pwd", 3) == 0
	|| ft_strncmp(tab[0], "export", 6) == 0 || ft_strncmp(tab[0], "unset", 5) == 0 || ft_strncmp(tab[0], "env", 3) == 0
	|| ft_strncmp(tab[0], "exit", 2) == 0)
	{
		if (ft_strncmp("echo", tab[0], 5) == 0)
			echo(&tab[1]);
		else if (ft_strncmp("pwd", tab[0], 3) == 0)
			pwd();
		else if (ft_strncmp("exit", tab[0], 4) == 0)
			end(tab);
		free_arr(tab, i);
	}
	else
	{
		if (ft_strncmp("./", tab[0], 2) == 0)
		{
			exec_prog(tab[0], &tab[1], NULL);
		}
	}
	return (i);
}

int main(int argc, char **argv, char **envp)
{
	int i;
    int sc;
    char *line;
	char *path;
    char **tab;

    print_new_line();
	signal(SIGINT, sighandler);
	while (1)
    {
        i = get_next_line(0, &line);
        tab = split_semi_colon(line);
        while (*tab)
        {
            if (isbuiltin(*tab) == 1)
                ;
            else
                ;//exec_prog(line, NULL, envp);
            if (i == 0)
                return (0);
            tab++;
        }
        print_new_line();

    }
    return (0);
}
