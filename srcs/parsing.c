/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:56:24 by tsimonis         ###   ########.fr       */
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
