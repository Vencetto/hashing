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

#include "ft_sha256.h"

void	string_sha256(t_flags *f, char *input)
{
	t_sha256	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	o.input = input;
	sha256_init(&o);
	sha256_update(&o, o.input, ft_strlen(o.input));
	sha256_final(&o, o.output);
	if (!f->q && f->r)
	{
		print_hash_sha256(&o, 0);
		ft_printf(" \"%s\"\n", o.input);
	}
	else if (!f->q)
	{
		ft_printf("SHA256 (\"%s\") = ", o.input);
		print_hash_sha256(&o, 1);
	}
	else
		print_hash_sha256(&o, 1);
}

void	p_flag_sha256(t_flags *f, char *input)
{
	t_sha256	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	o.input = input;
	sha256_init(&o);
	sha256_update(&o, o.input, ft_strlen(o.input));
	sha256_final(&o, o.output);
	if (o.input[ft_strlen(o.input) - 1] == '\n')
		ft_printf("%s", o.input);
	else
		ft_printf("%s\n", o.input);
	print_hash_sha256(&o, 1);
	f->p = 0;
}

void	file_sha256(t_flags *f, char *file_name)
{
	t_sha256	o;

	f->read_try = 1;
	ft_bzero(&o, sizeof(o));
	sha256_init(&o);
	sha256_update(&o, o.input, ft_strlen(o.input));
	sha256_final(&o, o.output);
	if (!try_open(file_name, o.input))
		return ;
	if (!f->q && f->r)
	{
		print_hash_sha256(&o, 0);
		ft_printf(" %s\n", file_name);
	}
	else if (!f->q)
	{
		ft_printf("SHA256 (%s) = ", file_name);
		print_hash_sha256(&o, 1);
	}
	else
		print_hash_sha256(&o, 1);
}

void	stdin_sha256(t_flags *f)
{
	t_sha256	o;

	ft_bzero(&o, sizeof(o));
	o.input = get_input(0);
	sha256_init(&o);
	sha256_update(&o, o.input, ft_strlen(o.input));
	sha256_final(&o, o.output);
	if (!f->q && f->r)
	{
		print_hash_sha256(&o, 0);
		ft_printf(" %s\n", "*stdin");
	}
	else if (!f->q)
	{
		ft_printf("(stdin) = ");
		print_hash_sha256(&o, 1);
	}
	else
		print_hash_sha256(&o, 1);
}

