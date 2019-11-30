/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:23:10 by vzomber           #+#    #+#             */
/*   Updated: 2019/11/23 15:23:11 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "md5") == 0)
			ft_md5Init(ac, av);
		else if (ft_strcmp(av[1], "sha256") == 0)
			;//ft_sha256Init(ac, av);
		else
			ft_putstr("Cannot identify command, try one of \"md5\" or \"sha256\" \n");
	}
	else
		ft_putstr("usage: ./ft_ssl [md5|sha256]");
	return (0);
}
