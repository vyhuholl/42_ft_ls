/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:15:45 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 10:30:17 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_all(t_options *options)
{
    t_list  *ptr;

	ft_print_files(options->files, options->flags);
    ptr = options->dirs;
    while (ptr)
    {
        ft_print_dir(ptr->content);
        ptr = ptr->next;
    }
}
