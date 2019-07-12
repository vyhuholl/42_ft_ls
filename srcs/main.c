/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 08:51:08 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags		ft_parse_flags(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	ft_memset(&flags, 0, sizeof(flags));
	i = 0;
	while (i < argc)
	{
		if argv[i][0] == '-':
			ft_add_params(argv[i], flags);
		else if (ft_is_file(argv[i]) == 1)
			ft_add_file(argv[i], flags);
		else if (ft_is_dir(argv[i]) == 1)
			ft_add_dir(argv[i], flags);
		i++;
	}
	return (flags);
}

int			main(int argc, char **argv)
{
	t_flags	flags;

	flags = ft_parse_flags(argc, argv)
	return (0);
}
