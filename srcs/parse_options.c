/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:48:52 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 14:12:12 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_add_filename(char *filename, t_options *options)
{
    t_list  *new;

    new = ft_lstnew(filename, sizeof(filename));
    if (!options->files)
        options->files = new;
    else
        ft_lstadd(options->files, new);
}

void    ft_add_dirname(char *filename, t_options *options)
{
    t_list  *new;

    new = ft_lstnew(filename, sizeof(filename));
    if (!options->dirs)
        options->dirs = new;
    else
        ft_lstadd(options->dirs, new);
}

void    	ft_add_option(char c, t_flags *flags)
{
    if (c == 'l')
        flags->long_format = 1;
    else if (c == 'R')
        flags->recursive = 1;
    else if (c == 'a')
        flags->all_files = 1;
    else if (c == 'r')
        flags->reversed = 1;
    else if (c == 't')
        flags->time_m = 1;
    else if (c == 'u')
        flags->time_a = 1;
    else if (c == 'f')
        flags->unsorted = 1;
    else if (c == 'g')
        flags->groupname = 1;
    else if (c == 'd')
        flags->dirs_as_files = 1;
    else if (c == 'G')
        flags->colors = 1;
    else
        ft_options_error(c);
}

void    ft_add_options(char *flags, t_options *options)
{
    int i;
    int index;

    i = 1;
    while (flags[i])
    {
        ft_add_option(flags[i], options->flags);
        i++;
    }
}
