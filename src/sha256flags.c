/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:16:22 by vzomber           #+#    #+#             */
/*   Updated: 2019/12/07 20:16:23 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
/*
void	string_md5(t_flags *f, char *input)
{
	t_md5	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	o.input = input;
	full_init(&o);
	ft_md5((uint8_t *)o.input, ft_strlen(o.input), &o);
	if (!f->q && f->r)
	{
		print_hash_md5(&o, 0);
		ft_printf(" \"%s\"\n", o.input);
	}
	else if (!f->q)
	{
		ft_printf("MD5 (\"%s\") = ", o.input);
		print_hash_md5(&o, 1);
	}
	else
		print_hash_md5(&o, 1);
}

void	p_flag_md5(t_flags *f, char *input)
{
	t_md5	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	o.input = input;
	full_init(&o);
	ft_md5((uint8_t *)o.input, ft_strlen(o.input), &o);
	if (o.input[ft_strlen(o.input) - 1] == '\n')
		ft_printf("%s", o.input);
	else
		ft_printf("%s\n", o.input);
	print_hash_md5(&o, 1);
	f->p = 0;
}

void	file_md5(t_flags *f, char *file_name)
{
	t_md5	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	if (!try_open(file_name, &o))
		return ;
	full_init(&o);
	ft_md5((uint8_t *)o.input, ft_strlen(o.input), &o);
	if (!f->q && f->r)
	{
		print_hash_md5(&o, 0);
		ft_printf(" %s\n", file_name);
	}
	else if (!f->q)
	{
		ft_printf("MD5 (%s) = ", file_name);
		print_hash_md5(&o, 1);
	}
	else
		print_hash_md5(&o, 1);
}

void	stdin_md5(t_flags *f)
{
	t_md5	o;

	ft_bzero(&o, sizeof(o));
	o.input = get_input(0);
	full_init(&o);
	ft_md5((uint8_t *)o.input, ft_strlen(o.input), &o);
	if (!f->q && f->r)
	{
		print_hash_md5(&o, 0);
		ft_printf(" %s\n", "*stdin");
	}
	else if (!f->q)
		print_hash_md5(&o, 1);
	else
		print_hash_md5(&o, 1);
}
*/