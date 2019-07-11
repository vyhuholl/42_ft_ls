/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <tsimonis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:30:08 by bsprigga          #+#    #+#             */
/*   Updated: 2019/04/19 20:04:41 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = -1;
	if (!dst && !src)
		return (dst);
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
