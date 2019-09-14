/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:55:52 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 13:54:32 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** A function that calculates column width
** and total number of blocks for long display.
*/

int		ft_get_width(t_file *files, int tab[7])
{
	int blocks;

	blocks = 0;
	while (files)
	{
		tab[0] = ft_max(ft_nbrlen(files->stats.st_blocks), tab[0]);
		tab[1] = ft_max(ft_nbrlen(files->stats.st_nlink), tab[1]);
		tab[2] = ft_max(ft_strlen(getpwuid(files->stats.st_uid)->pw_name),
		tab[2]);
		tab[3] = ft_max(ft_strlen(getgrgid(files->stats.st_gid)->gr_name),
		tab[3]);
		if (!S_ISCHR(files->stats.st_mode))
			tab[4] = ft_max(ft_nbrlen(files->stats.st_size), tab[4]);
		else
		{
			tab[5] = ft_max(ft_nbrlen(major(files->stats.st_rdev)), tab[5]);
			tab[6] = ft_max(ft_nbrlen(minor(files->stats.st_rdev)), tab[6]);
			tab[4] = ft_max(tab[5] + tab[6] + 2, tab[4]);
		}
		blocks += files->stats.st_blocks;
		files = files->next;
	}
	tab[5] = ft_max(tab[4] - tab[6] - 1, tab[5]);
	return (blocks);
}

/*
** A function that gets file type and
** returns the corresponding char.
*/

char	ft_filetype(t_file *file)
{
	if (S_ISBLK(file->stats.st_mode))
		return ('b');
	else if (S_ISCHR(file->stats.st_mode))
		return ('c');
	else if (S_ISDIR(file->stats.st_mode))
		return ('d');
	else if (S_ISFIFO(file->stats.st_mode))
		return ('p');
	else if (S_ISLNK(file->stats.st_mode))
		return ('l');
	else if (S_ISSOCK(file->stats.st_mode))
		return ('s');
	return ('-');
}

/*
** A function that prints file permissions.
*/

void	ft_print_chmod(t_file *file)
{
	ft_putchar(ft_filetype(file));
	ft_putchar((file->stats.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file->stats.st_mode & S_IWUSR) ? 'w' : '-');
	if (file->stats.st_mode & S_ISUID)
		ft_putchar((file->stats.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((file->stats.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((file->stats.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file->stats.st_mode & S_IWGRP) ? 'w' : '-');
	if (file->stats.st_mode & S_ISGID)
		ft_putchar((file->stats.st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((file->stats.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((file->stats.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file->stats.st_mode & S_IWOTH) ? 'w' : '-');
	if (file->stats.st_mode & S_ISVTX)
		ft_putchar((file->stats.st_mode & S_IXOTH) ? 's' : 'S');
	else
		ft_putchar((file->stats.st_mode & S_IXUSR) ? 'x' : '-');
}

/*
** A function that prints one line of the output in long format.
*/

void	ft_print_long_one(t_file *file, int flags, int width[7])
{
	char	link[256];

	ft_print_chmod(file);
	ft_printf("  %*d %-*s  %-*s",
	width[1], file->stats.st_nlink,
	width[2], getpwuid(file->stats.st_uid)->pw_name,
	width[3], getgrgid(file->stats.st_gid)->gr_name);
	if (!(S_ISBLK(file->stats.st_mode) || S_ISCHR(file->stats.st_mode)))
		ft_printf("  %*d", width[4], file->stats.st_size);
	else
		ft_printf(" %*d, %*d", width[5], major(file->stats.st_rdev),
								width[6], minor(file->stats.st_rdev));
	ft_print_time(file, flags);
	if (!S_ISLNK(file->stats.st_mode))
		ft_printf(" %s", file->name);
	else
	{
		ft_bzero(link, 256);
		readlink(file->path, link, 255);
		ft_printf(" %s -> %s\n", file->name, link);
	}
}

/*
** A function that prints all output in long format.
*/

void	ft_print_long(t_file *files, int flags)
{
	int width[7];
	int blocks;

	ft_bzero(width, sizeof(width));
	width[5] = 3;
	width[6] = 3;
	blocks = ft_get_width(files, width);
	if (files->next)
		ft_printf("total %d\n", blocks);
	while (files)
	{
		ft_print_long_one(files, flags, width);
		if (files->next)
			ft_putchar('\n');
		files = files->next;
	}
}
