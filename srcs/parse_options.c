/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:48:52 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 10:52:57 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_add_file(char *filename, t_options *options)
{
    t_list  *new;

    new = ft_lstnew(filename, sizeof(filename));
    if (!options->files)
        options->files = new;
    else
        ft_lstadd(options->files, new);
}

void    ft_add_dir(char *filename, t_options *options)
{
    t_list  *new;

    new = ft_lstnew(filename, sizeof(filename));
    if (!options->dirs)
        options->dirs = new;
    else
        ft_lstadd(options->dirs, new);
}

int     ft_get_index(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i
        i++;
    }
    return (-1);
}

void    ft_add_options(char *flags, t_options *options)
{
    int i;
    int index;

    i = 1;
    while (flags[i])
    {
        index = ft_get_index("lRartufgdG", flags[i]);
        if (index == -1)
            ft_options_error(flags[i]);
        options->flags[index] = 1;
        i++;
    }
}
