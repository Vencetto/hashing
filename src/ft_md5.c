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

void	local_init(uint8_t *initial_msg, size_t initial_len, t_md5 *o)
{
	uint32_t	bits_len;

	ft_memcpy(o->msg, initial_msg, initial_len);
	o->msg[initial_len] = 128;
	bits_len = 8 * initial_len;
	ft_memcpy(o->msg + o->new_len, &bits_len, 4);
}

void	those_formulas(t_vars *v, int i)
{
	if (i < 16)
	{
		v->f = (v->b & v->c) | ((~v->b) & v->d);
		v->g = i;
	}
	else if (i < 32)
	{
		v->f = (v->d & v->b) | ((~v->d) & v->c);
		v->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		v->f = v->b ^ v->c ^ v->d;
		v->g = (3 * i + 5) % 16;
	}
	else
	{
		v->f = v->c ^ (v->b | (~v->d));
		v->g = (7 * i) % 16;
	}
}

void	all_the_math(t_vars *v, t_md5 *o)
{
	int			i;
	uint32_t	temp;

	v->w = (uint32_t*)(o->msg + v->offset);
	v->a = o->h[0];
	v->b = o->h[1];
	v->c = o->h[2];
	v->d = o->h[3];
	i = -1;
	while (++i < 64)
	{
		those_formulas(v, i);
		temp = v->d;
		v->d = v->c;
		v->c = v->b;
		v->b = v->b + LEFTROTATE((v->a + v->f + g_k[i] + v->w[v->g]), g_r[i]);
		v->a = temp;
	}
	o->h[0] += v->a;
	o->h[1] += v->b;
	o->h[2] += v->c;
	o->h[3] += v->d;
	v->offset += (512 / 8);
}

void	save_result(t_md5 *o)
{
	int	i;

	i = -1;
	while (++i < 4)
		o->output[i] = (uint8_t *)&o->h[i];
}

void	ft_md5(uint8_t *initial_msg, size_t initial_len, t_md5 *o)
{
	uint32_t	i;
	t_vars		v;

	local_init(initial_msg, initial_len, o);
	v.offset = 0;
	while (v.offset < o->new_len)
		all_the_math(&v, o);
	free(o->msg);
	save_result(o);
}
