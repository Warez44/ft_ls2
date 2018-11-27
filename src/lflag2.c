/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:11:08 by clingier          #+#    #+#             */
/*   Updated: 2018/11/24 15:15:02 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <lflag.h>

char	*uidname(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		return (NULL);
	return (pwd->pw_name);
}

void	getlenlnk(t_file *files)
{
	unsigned int	max;
	int				i;
	int				len;

	max = 0;
	i = 0;
	len = 0;
	while (i < files->len)
	{
		if ((unsigned int)files[i].stats.st_nlink > max)
			max = (unsigned int)files[i].stats.st_nlink;
		i++;
	}
	if (max == 0)
		len = 1;
	while (max)
	{
		len++;
		max /= 10;
	}
	i = 0;
	while (i < files->len)
		files[i++].lenlnk = len;
}

int		ft_betterstrlen(char *str)
{
	if (str == NULL)
		return (0);
	return (ft_strlen(str));
}

void	getmaxstr(t_file *files)
{
	int i;
	int max[2];
	int len1;
	int len2;

	i = 0;
	max[0] = 0;
	max[1] = 0;
	while (i < files->len)
	{
		len1 = ft_betterstrlen(uidname(files[i].stats.st_uid));
		len2 = ft_betterstrlen(gidname(files[i].stats.st_gid));
		if (len1 > max[0])
			max[0] = len1;
		if (len2 > max[1])
			max[1] = len2;
		i++;
	}
	i = 0;
	while (i < files->len)
	{
		files[i].lenuid = max[0];
		files[i].lengid = max[1];
		i++;
	}
}

void	getlensiz(t_file *files)
{
	unsigned long	max;
	int				i;
	int				len;

	i = 0;
	max = 0;
	len = 0;
	while (i < files->len)
	{
		if ((unsigned long)files[i].stats.st_size > max)
			max = (unsigned long)files[i].stats.st_size;
		i++;
	}
	if (max == 0)
		len = 1;
	while (max)
	{
		len++;
		max /= 10;
	}
	i = 0;
	while (i < files->len)
		files[i++].lensiz = len;
}
