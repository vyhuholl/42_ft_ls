/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:38:46 by sghezn            #+#    #+#             */
/*   Updated: 2019/09/14 14:47:50 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Auxillary function used to print n spaces.
*/

void	ft_print_spaces(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

/*
** Auxillary function that finds the length
** of the longest filename in a list of files.
*/

int		ft_max_name_len(t_file *files)
{
	int	len;

	len = 0;
	while (files)
	{
		if ((int)ft_strlen(files->name) > len)
			len = (int)ft_strlen(files->name);
		files = files->next;
	}
	return (len);
}

/*
** A function that prints all output one entry per line.
*/

void	ft_print_one_per_line(t_file **files)
{
	while ((*files))
	{
		ft_printf("%s\n", (*files)->name);
		*files = (*files)->next;
	}
}

/*
** A function that prints columns in short format.
** Like in system ls, columns are formed from file list
** top to bottom AND THEN left to right.
*/

void	ft_print_columns(t_file *files, t_point max_len, t_point index)
{
	t_file	*ptr;
	int		temp_row;
	int		temp_col;
	int		i;

	i = index.y;
	while (files && i--)
	{
		temp_col = index.x;
		ptr = files->next;
		while (files && temp_col--)
		{
			ft_printf("%s", files->name);
			if (temp_col && max_len.x > (int)ft_strlen(files->name))
				ft_print_spaces(max_len.x - (int)ft_strlen(files->name));
			temp_row = index.y;
			while (files && temp_row--)
				files = files->next;
		}
		ft_putchar('\n');
		files = ptr;
	}
}

/*
** A function that prints all output in short format.
** Bonus: management of the columns without the option -l.
*/

void	ft_print_short(t_file *files, int flags)
{
	t_tysize	tty_size;
	t_point		max_len;
	t_point		index;
	t_file		*ptr;

	if (flags & 256)
		ft_print_one_per_line(&files);
	else
	{
		max_len.x = ft_max_name_len(files) + 1;
		max_len.y = 0;
		ioctl(0, TIOCGWINSZ, &tty_size);
		index.x = tty_size.ts_cols / max_len.x;
		index.y = 0;
		ptr = files;
		while (ptr)
		{
			index.y++;
			ptr = ptr->next;
		}
		index.y = (index.y % index.x ? 1 : 0) + index.y / index.x;
		ft_print_columns(files, max_len, index);
	}
}
