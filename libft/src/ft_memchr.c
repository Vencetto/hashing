/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:24 by vzomber           #+#    #+#             */
/*   Updated: 2017/11/21 17:41:03 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*new;
	unsigned char	sym;

	new = (unsigned char*)s;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (new[i] == sym)
			return (&new[i]);
		i++;
	}
	return (NULL);
}
