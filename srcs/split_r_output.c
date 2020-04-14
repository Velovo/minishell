/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_r_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:35:57 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/14 13:30:35 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minishell.h"

int     ft_strlen_redirect(char *line, char red)
{
    int i;

    i = 0;
    while (line[i] && line[i] != red)
        i++;
    return (i);
}

void    close_output(t_r_output *out)
{
    if (out->fd != 1)
        close(out->fd);
    free(out->ret);
}

char    *get_file_name(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] == ' ')
        i++;
    return (&str[i]);
}

int     split_r_output(char *line, t_r_output *out)
{
    int i;
    int j;
    int quotes;

    i = 0;
    j = 0;
    quotes = 0;
    out->fd = 1;
    out->ret = malloc(sizeof(char) * ft_strlen_redirect(line, '>'));
    while (line[i])
    {
        out->ret[j++] = line[i];

        if (line[i] == '\"' && quotes == 0)
            quotes++;
        else if (line[i] == '\"' && quotes == 1)
            quotes--;
        else if (line[i + 1] == '>' && line[i] != '\\' && quotes == 0 && line[i + 2] != '>')
        {
            out->fd = open(get_file_name(&line[i + 2]), O_WRONLY | O_TRUNC);
            break;
        }
        else if (line[i + 1] == '>' && line[i] != '\\' && quotes == 0 && line[i + 2] == '>')
        {
            out->fd = open(get_file_name(&line[i + 3]), O_WRONLY | O_APPEND);
            break;
        }
        i++;
    }
    return (out->fd);
}
