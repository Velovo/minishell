/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:07:39 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/13 15:46:54 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STURCURES_H
#define STURCURES_H

    typedef struct  s_semi_colons
    {
        int     i;
        int     j;
        int     k;
        int     l;
        int     m;
        int     q;
        char    **tab;
    }               t_semi_colons;

    typedef struct  s_r_output
    {
        int fd;
        char *ret;
    }               t_r_output;
#endif
