/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 08:59:36 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options	*ft_parse_options(int argc, char **argv)
{
	t_options	*options;
	int			*flags;
	int			i;

	options = (t_options*)malloc(sizeof(t_options) + 1);
	flags = (int*)malloc(sizeof(int) * 10 + 1);
	options->flags = flags;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_add_options(argv[i], options);
		else if (ft_is_file(argv[i]) == 1)
			ft_add_file(argv[i], options);
		else if (ft_is_dir(argv[i]) == 1)
			ft_add_dir(argv[i], options);
	}
	return (options);
}

int			main(int argc, char **argv)
{
	t_options	*options;

	options = ft_parse_options(argc, argv);
	return (0);
}
