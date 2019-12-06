/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:25:32 by vzomber           #+#    #+#             */
/*   Updated: 2019/11/23 17:25:40 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	printHashMD5(t_md5 *o, int newLine)
{
	int i;

	i = -1;
	while (++i < 4)
		ft_printf("%2.2x%2.2x%2.2x%2.2x", o->output[i][0],
		o->output[i][1], o->output[i][2], o->output[i][3]);
	if (newLine)
		ft_printf("\n");
}



char	*ft_md5(uint8_t *initial_msg, size_t initial_len, t_md5 *o)
{
	int		new_len;
	uint32_t	bits_len;
	uint32_t	i;
	int		offset;

	new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
	o->msg = ft_memalloc(new_len + 64);
	ft_memcpy(o->msg, initial_msg, initial_len);
	o->msg[initial_len] = 128;
	bits_len = 8*initial_len;
	ft_memcpy(o->msg + new_len, &bits_len, 4);

	offset = 0;
	while (offset < new_len)
	{

		uint32_t *w = (uint32_t *) (o->msg + offset);
		uint32_t a = o->h[0];
		uint32_t b = o->h[1];
		uint32_t c = o->h[2];
		uint32_t d = o->h[3];

		i = -1;
		while (++i < 64)
		{
			uint32_t f, g;

			if (i < 16)
			{
				f = (b & c) | ((~b) & d);
				g = i;
			}
			else if (i < 32)
			{
				f = (d & b) | ((~d) & c);
				g = (5*i + 1) % 16;
			}
			else if (i < 48)
			{
				f = b ^ c ^ d;
				g = (3*i + 5) % 16;
			}
			else
			{
				f = c ^ (b | (~d));
				g = (7*i) % 16;
			}

			uint32_t temp = d;
			d = c;
			c = b;
			b = b + LEFTROTATE((a + f + g_k[i] + w[g]), g_r[i]);
			a = temp;

		}
		o->h[0] += a;
		o->h[1] += b;
		o->h[2] += c;
		o->h[3] += d;
		offset += (512/8);
	}
	free(o->msg);

	int c = -1;
	while (++c < 4)
		o->output[c] = (uint8_t *) & o->h[c];
}
