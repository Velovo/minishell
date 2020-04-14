/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semi_colon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 11:05:15 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/09 16:38:02 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minishell.h"

int count_semi_colon(char *line)
{
    int sc;
    int i;
    int q;

    i = 0;
    q = 0;
    sc = 0;
    while (line[i])
    {
        if (line[i] == '\"' && q == 0)
            q++;
        else if (line[i] == '\"' && q == 1)
            q--;
        else if (line[i + 1] == ';' && line[i] != '\\' && q == 0)
            sc++;
        i++;
    }
    return (sc);
}

char **split_semi_colon(char *line)
{
    t_semi_colons iter;

    iter.q = 0;
    iter.i = 0;
    iter.j = 0;
    iter.k = 0;
    iter.l = 0;
    iter.m = 0;
    iter.tab = malloc(sizeof(char *) * (count_semi_colon(line) + 2));
    while (line[iter.i])
    {
        if (line[iter.i] == '\"' && iter.q == 0)
            iter.q++;
        else if (line[iter.i] == '\"' && iter.q == 1)
            iter.q--;
        else if (line[iter.i + 1] == ';' && line[iter.i] != '\\' && iter.q == 0)
        {
            iter.tab[iter.k] = malloc(sizeof(char) * iter.j + 2);
            while (iter.l <= iter.i)
            {
                iter.tab[iter.k][iter.m] = line[iter.l];
                iter.l++;
                iter.m++;
            }
            iter.tab[iter.k][iter.m] = '\0';
            iter.m = 0;
            iter.j = -1;
            iter.k++;
            iter.l++;
            iter.i++;
        }
        iter.j++;
        iter.i++;
    }
    iter.j--;
    iter.tab[iter.k] = malloc(sizeof(char) * iter.j + 2);
    while (iter.l < iter.i)
    {
        iter.tab[iter.k][iter.m] = line[iter.l];
        iter.l++;
        iter.m++;
    }
    iter.tab[iter.k][iter.m] = '\0';
    iter.k++;
    iter.tab[iter.k] = NULL;
    return (iter.tab);
}
