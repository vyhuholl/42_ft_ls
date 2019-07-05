/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:17:52 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:09:29 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// t_list		*ft_read_dir(char *filepath, struct stat buf)
// {
// 	DIR				*dir;
// 	t_list			*list;
// 	t_file			*curr;
// 	struct dirent	*entry;

// 	dir = opendir(filepath);
// 	list = NULL;
// 	curr = (t_file*)ft_memalloc(sizeof(t_file));
// 	while ((entry = readdir(dir)))
// 	{
// 		if (input->flags_a == 1 || entry->d_name[0] != '.')
// 		{
// 			curr->name = ft_strdup(entry->d_name);
// 			curr->pathname = ft_strdup(filepath);
// 			stat(ft_strjoin(curr->name, curr->pathname), &curr->stats);
// 			ft_lstadd(list, ft_lstnew(curr, sizeof(t_file)));
// 		}
// 	}
// 	free(curr);
// 	closedir(dir);
// 	return (list);
// }
