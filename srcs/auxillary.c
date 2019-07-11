/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:28:42 by tsimonis         ###   ########.fr       */
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
