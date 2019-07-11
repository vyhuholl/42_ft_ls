/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/11 23:22:53 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
