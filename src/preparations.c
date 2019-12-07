/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:37:20 by vzomber           #+#    #+#             */
/*   Updated: 2019/11/30 14:37:21 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	full_init(t_md5 *o)
{
	o->h[0] = 0x67452301;
	o->h[1] = 0xefcdab89;
	o->h[2] = 0x98badcfe;
	o->h[3] = 0x10325476;
	o->newLen = ((((ft_strlen(o->input) + 8) / 64) + 1) * 64) - 8;
	o->msg = ft_memalloc(o->newLen + 64);
}

void	p_flag(void)
{
	t_md5 another;

	ft_bzero(&another, sizeof(another));
	another.input = get_input(0);
	full_init(&another);
	ft_md5((uint8_t *)another.input, ft_strlen(another.input), &another);
	ft_printf("%s\n", another.input);
	print_hash_md5(&another, 1);
}
/*
void	md5_flags_executor(t_md5 *o)
{
	char *input;

	if (o->q)
	{
		print_hash_md5(o, 1);
		return ;
	}
	if (o->p)
		p_flag();
	if (o->isStr || o->isFile)
	{
		o->isFile ? (input = o->file_name) :
			(input = o->input);
		if (o->r)
		{
			print_hash_md5(o, 0);
			ft_printf(" %s\n", input);
		}
		else
		{
			ft_printf("MD5 (%s) = ", input);
			print_hash_md5(o, 1);
		}
	}
	else
		print_hash_md5(o, 1);
}

void	check_flags_md5(int ac, char **av, t_md5 *o)
{
	int	i;

	i = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-r") == 0)
			o->r = 1;
		else if (ft_strcmp(av[i], "-q") == 0)
			o->q = 1;
		else if (ft_strcmp(av[i], "-p") == 0)
			o->p = 1;
		else if (ft_strcmp(av[i], "-s") == 0 && ac >= i + 1)
		{
			o->input = av[i + 1];
			o->isStr = 1;
			++i;
		}
		else
		{
			if (!try_open(av[i], o))
				break ;
		}
	}
}
*/
// 1) -p add stdin to stdout
// 2) -s add string as input
// 3) -q prints only hashes
// 4) -r reverse output, beated by -q

void	ft_md5_init(int ac, char **av)
{
	t_md5	o;
	char	buff[2];

	ft_bzero(&o, sizeof(o));
	check_flags_md5(ac, av, &o);
	if (!o.isStr && !o.isFile)
		o.input = get_input(0);
	if (ft_strlen(o.input))
	{
		full_init(&o);
		ft_md5((uint8_t *)o.input, ft_strlen(o.input), &o);
		md5_flags_executor(&o);
	}
	else
		ft_printf("Got no input.\n");
}
