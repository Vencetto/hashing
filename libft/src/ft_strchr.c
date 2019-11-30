/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:18:26 by vzomber           #+#    #+#             */
/*   Updated: 2018/12/27 18:22:06 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sym;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	sym = (char)c;
	while (s[i] != sym)
		if (s[i++] == '\0')
			return (NULL);
	return (char*)(&s[i]);
}
