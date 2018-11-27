/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:02:51 by clingier          #+#    #+#             */
/*   Updated: 2018/11/27 14:53:03 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	malcheck(void *ptr)
{
	if (!ptr)
	{
		ft_putendl_fd("Not enough memory...", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_flagerror(char t)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(t, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
	exit(EXIT_FAILURE);
}
