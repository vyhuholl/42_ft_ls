/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:25:17 by sghezn            #+#    #+#             */
/*   Updated: 2019/07/14 15:43:56 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_swap_files(t_file *file_1, t_file *file_2)
{
    t_file  *temp;

    temp->name = file_1->name;
    temp->path = file_1->path;
    temp->username = file_1->username;
    temp->groupname = file_1->groupname;
    temp->stat = file_1->stat;
    file_1->name = file_2->name;
    file_1->path = file_2->path;
    file_1->username = file_2->username;
    file_1->groupname = file_2->groupname;
    file_1->stat = file_2->stat;
    file_2->name = temp->name;
    file_2->path = temp->path;
    file_2->username = temp->username;
    file_2->groupname = temp->groupname;
    file_2->stat = temp->stat;
}
