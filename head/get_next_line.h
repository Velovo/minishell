/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:27 by avan-pra          #+#    #+#             */
/*   Updated: 2020/03/13 15:26:04 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
