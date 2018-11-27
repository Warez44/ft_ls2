/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:39:10 by clingier          #+#    #+#             */
/*   Updated: 2018/11/27 09:52:37 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <lflag.h>

void	putlink(t_file file)
{
	char	buf[file.stats.st_size];
	char	buf2[255];
	int		ret;

	buf2[254] = '\0';
	ft_putstr(" -> ");
	if (file.stats.st_size == 0)
	{
		ret = readlink(file.fpath, buf2, 254);
		buf2[ret] = '\0';
		ft_putstr(buf2);
		return ;
	}
	ret = readlink(file.fpath, buf, file.stats.st_size);
	buf[ret] = '\0';
	ft_putstr(buf);
}

int		ft_minor(dev_t st_dev)
{
	return (((unsigned int)(st_dev & 0xFF)));
}

int		ft_major(dev_t st_dev)
{
	return ((int)(((unsigned)(st_dev) >> 24) & 0xFF));
}

void	putstr_format(char *str, int format)
{
	int len;

	len = ft_strlen(str);
	while (format - len > 0)
	{
		ft_putstr(" ");
		len++;
	}
	ft_putstr(str);
}
