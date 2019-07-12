/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 04:56:17 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** An auxillary function for indexing.
*/

int ft_index(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

/*
** A function to handle errors.
** Prints usage if an invalid option was used
** and error message otherwise.
*/

int ft_raise_error(char *str, int error)
{
    if (error == USAGE)
    {
        ft_putstr("ft_ls: illegal option -- ");
        ft_putchar(*str);
        ft_putchar('\n');
        ft_putstr("usage: ft_ls [-adfGglRrtu] [file ...]");
    }
    else
    {
        ft_putstr(str);
        ft_putstr(": ");
        ft_putstr(strerror(errno));
    }
    exit(EXIT_FAILURE);
    return (0);
}

/*
** Finds all flags.
*/

int *ft_parse_options(int argc, char **argv)
{
    int *flags;
    int i;
    int index;

    i = 1;
    flags = (char*)malloc(sizeof(char) * 10 + 1);
    while (i < argc && argv[i][0] == '-')
    {
        while (*(++argv[i]))
        {
            if ((index = ft_index(*argv[i], "adfGglRrtu")) == -1)
                ft_raise_error(argv[i], USAGE);
            flags[index] = 1;
        }
        i++;
    }
    return (flags)
}
