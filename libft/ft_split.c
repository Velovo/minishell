/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:40:48 by avan-pra          #+#    #+#             */
/*   Updated: 2020/04/09 16:28:20 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_arr(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static int	is_charset(char myl, char c)
{
	if (myl == c)
		return (1);
	return (0);
}

static int	count_split(const char *str, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (is_charset(str[i], c) == 1)
		i++;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], c) == 1)
		{
			ret++;
			while (is_charset(str[i], c) == 1)
				i++;
		}
		else
			i++;
	}
	if (i > 0 && is_charset(str[i - 1], c) == 1)
		ret--;
	return (ret);
}

static int	count_words(const char *str, char c)
{
	int ret;

	ret = 0;
	while (is_charset(str[ret], c) == 0 && str[ret] != '\0')
		ret++;
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = malloc((count_split(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_split(s, c) && s[0] != '\0' && s != NULL)
	{
		k = 0;
		while (is_charset(s[i], c) == 1)
			i++;
		if (!(tab[j] = malloc((count_words(&s[i], c) + 1) * sizeof(char))))
			return (free_arr(tab, j));
		while (s[i] != '\0' && is_charset(s[i], c) == 0)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
