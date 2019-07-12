/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:48:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/12 10:49:34 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options	*ft_parse_options(int argc, char **argv)
{
	t_options	*options;
	int			i;

	options = (t_options*)malloc(sizeof(t_options) + 1)
	return (options);
}

int			main(int argc, char **argv)
{
	t_options	*options;

	options = ft_parse_options(argc, argv);
	return (0);
}
