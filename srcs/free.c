/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:11 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 11:22:16 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_free_list(t_list *list)
{
    t_list  *ptr;

    while (list)
    {
        ptr = list->next;
        ft_memdel((void**)&list->content);
        ft_memdel((void**)&list);
        list = ptr;
    }
}
