/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:51:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/06/07 04:28:42 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

/*
** full flag list: adfGglRrtu
*/

typedef struct	s_file
{
	mode_t	mode;
	nlink_t	n_links;
	uid_t	user_id;
	gid_t	group_id;
	off_t	size;
	time_t	atime;
	time_t	mtime;
	char	*name;
	char	*path;
	t_file	*next;
}				t_file;

int[10]	ft_parse_options(int argc, char **argv);

#endif
