/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:28:25 by vzomber           #+#    #+#             */
/*   Updated: 2017/11/23 19:32:21 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*res;
	unsigned char		*fg;
	unsigned char		sym;

	sym = (unsigned char)c;
	fg = (unsigned char*)src;
	res = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		res[i] = fg[i];
		if (fg[i] == sym)
			return (void*)(&dst[i + 1]);
		i++;
	}
	return (void*)(NULL);
}
