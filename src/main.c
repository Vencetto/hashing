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
	if (ac >= 3 && ac <= 4)
	{
		if (ft_strcmp(av[1], "md5") == 0)
			ft_md5((uint8_t*)av[ac - 1], strlen(av[ac - 1]));
		//else if (ft_strcmp(av[1], "sha256") == 0)
			//ft_sha256(av[ac - 1], sizeof(av[ac - 1]));
		else
			ft_putstr("Cannot identify command, try one of \"md5\" or \"sha256\" \n");
	}
	else
		ft_putstr("usage: ./ft_ssl [md5|sha256] \"string\"\n");
	return (0);
}
