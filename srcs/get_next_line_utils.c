/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:20 by avan-pra          #+#    #+#             */
/*   Updated: 2020/03/13 15:24:02 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minishell.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
