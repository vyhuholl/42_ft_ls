/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:09:49 by tsimonis          #+#    #+#             */
/*   Updated: 2019/06/06 18:11:49 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchr_index(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (i);
	}
	if (s[i] == '\0' && c == '\0')
		return (i);
	return (-1);
}
