/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:01:28 by clingier          #+#    #+#             */
/*   Updated: 2018/11/27 10:39:47 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	r_maj_flag(t_file file, unsigned char flags)
{
	DIR *dir;

	if (S_ISDIR(file.stats.st_mode) && !S_ISLNK(file.stats.st_mode)
		&& !ft_strequ(file.fname, ".") && !ft_strequ(file.fname, ".."))
	{
		ft_putstr("\n");
		ft_putstr(file.fpath);
		ft_putendl(":");
		dir = opendir(file.fpath);
		if (errno != 0)
		{
			ft_putstr_fd("ls: ", 2);
			perror(file.fname);
			errno = 0;
			return ;
		}
		closedir(dir);
		ft_ls(file.fpath, flags);
	}
}

void	ft_ls(char *directory, unsigned char flags)
{
	t_file	*files;
	int		i;

	i = 0;
	if (!(files = readfiles(directory, flags)))
		return ;
	if (flags & L_FLAG)
		lflag(files, flags);
	while (i < files->len && !(flags & L_FLAG))
		ft_putendl(files[i++].fname);
	if (flags & R_FLAG)
	{
		i = 0;
		if (!(flags & L_FLAG))
			getstats(files, R_FLAG);
		while (i < files->len)
			r_maj_flag(files[i++], flags);
	}
	freefiles(files);
}
