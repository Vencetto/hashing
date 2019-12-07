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
	o->new_len = ((((ft_strlen(o->input) + 8) / 64) + 1) * 64) - 8;
	o->msg = ft_memalloc(o->new_len + 64);
}

void	check_flags_md5(int ac, char **av, t_flags *f)
{
	int	i;

	i = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-r") == 0)
			f->r = 1;
		else if (ft_strcmp(av[i], "-q") == 0)
			f->q = 1;
		else if (ft_strcmp(av[i], "-p") == 0)
			f->p = 1;
	}
}

void	ft_md5_init(int ac, char **av)
{
	t_flags	f;
	char	buff[2];
	int		i;

	ft_bzero(&f, sizeof(f));
	check_flags_md5(ac, av, &f);
	i = 1;
	while (++i < ac)
	{
		if (f.p)
			p_flag_md5(&f, get_input(0));
		if (ft_strcmp(av[i], "-s") == 0 && ac > i)
			string_md5(&f, av[++i]);
		else if (!ft_strequ(av[i], "-r") && !ft_strequ(av[i], "-q")
			&& !ft_strequ(av[i], "-p"))
			file_md5(&f, av[i]);
	}
	if (!f.read_try)
		stdin_md5(&f);
}
