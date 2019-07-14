/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/15 02:35:41 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options	*ft_parse_options(int argc, char **argv)
{
	t_options	*options;
	t_flags		*flags;
	int			i;

	options = (t_options*)malloc(sizeof(t_options) + 1);
	flags = (t_flags*)malloc(sizeof(t_flags) + 1);
	ft_memset(&flags, 0, sizeof(flags));
	options->flags = flags;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_add_options(argv[i], options);
		else if (ft_is_file_or_dir(argv[i]) == 1)
			ft_add_filename(argv[i], options);
		else if (ft_is_file_or_dir(argv[i]) == 2)
			ft_add_dirname(argv[i], options);
	}
	if (!options->files && !options->dirs)
		ft_add_dir(".", options)
	ft_lstreverse(options->files);
	ft_lstreverse(options->dirs);
	ft_sort(options);
	return (options);
}

int			main(int argc, char **argv)
{
	t_options	*options;

	options = ft_parse_options(argc, argv);
	ft_print_all(options);
	ft_free_list(options->files);
	ft_free_list(options->dirs);
	ft_memdel((void**)&options->path);
	ft_memdel((void**)&options->flags);
	ft_memdel((void**)&options);
	return (0);
}
