/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:38:46 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/22 16:41:47 by sghezn           ###   ########.fr       */
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

int		ft_max_name_len(t_file **files)
{
	int	len;

	len = 0;
	while ((*files)->next)
	{
		if ((int)ft_strlen((*files)->name) > len)
			len = (int)ft_strlen((*files)->name);
		*files = (*files)->next;
	}
	return (len);
}

/*
** A function that prints all output one entry per line.
*/

void	ft_print_one_per_line(t_file **files)
{
	while ((*files)->next)
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

void	ft_print_columns(t_file *files, t_point index, int max_len)
{
	t_file	*temp;
	int		row;
	int		col;
	int		i;

	i = index.col;
	while (files && i > 0)
	{
		col = index.row;
		temp = files->next;
		while (files && col--)
		{
			ft_printf("%s", files->name);
			if (col)
				ft_print_spaces(max_len - (int)ft_strlen(files->name));
			row = index.col;
			while (files && row--)
				files = files->next;
		}
		ft_putchar('\n');
		files = temp;
		i--;
	}
}

/*
** A function that prints all output in short format.
** Bonus: management of the columns without the option -l.
*/

void	ft_print_short(t_file *files, int flags)
{
	t_tysize	tty_size;
	t_point		index;
	t_file		*ptr;
	int			max_len;

	if (flags & 256)
		ft_print_one_per_line(&files);
	else
	{
		max_len = ft_max_name_len(&files) + 4;
		ioctl(0, TIOCGWINSZ, &tty_size);
		index.row = tty_size.ts_cols / max_len;
		index.col = 0;
		ptr = files;
		while (ptr)
		{
			index.col++;
			ptr = ptr->next;
		}
		ft_print_columns(files, index, max_len);
	}
}
