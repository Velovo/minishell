/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delacourt <delacourt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:08:55 by delacourt         #+#    #+#             */
/*   Updated: 2020/04/09 16:08:55 by delacourt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minishell.h"

void sighandler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	print_new_line();
}
