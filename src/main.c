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

void	ft_print_commands(void)
{
	ft_printf("%s\n\n%s\n%s\n%s\n\n%s\n", "Standart commands:",
	"Message Digest commands:", "md5", "sha256", "Cipher commands:");
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "md5") == 0)
			ft_md5_init(ac, av);
		else if (ft_strcmp(av[1], "sha256") == 0)
			;//ft_sha256Init(ac, av);
		else
			ft_print_commands();
	}
	else
		ft_putstr("usage: ./ft_ssl command [command opts] [command args]\n");
	return (0);
}
