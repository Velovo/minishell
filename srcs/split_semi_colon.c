/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semi_colon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 11:05:15 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/01 09:55:31 by delacourt        ###   ########.fr       */
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
    int i;
    int j;
    int k;
    int l;
    int m;
    int q;
    char **tab;
    q = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    tab = malloc(sizeof(char *) * (count_semi_colon(line) + 2));
    while (line[i])
    {
        if (line[i] == '\"' && q == 0)
            q++;
        else if (line[i] == '\"' && q == 1)
            q--;
        else if (line[i + 1] == ';' && line[i] != '\\' && q == 0)
        {
            tab[k] = malloc(sizeof(char) * j + 2);
            while (l <= i)
            {
                tab[k][m] = line[l];
                l++;
                m++;
            }
            tab[k][m] = '\0';
            m = 0;
            j = -1;
            k++;
            l++;
            i++;
        }
        j++;
        i++;
    }
    j--;
    tab[k] = malloc(sizeof(char) * j + 2);
    while (l < i)
    {
        tab[k][m] = line[l];
        l++;
        m++;
    }
    tab[k][m] = '\0';
    k++;
    tab[k] = NULL;
    return (tab);
}
