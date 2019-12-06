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

char	*getInput(int fd)
{
	char	buff[2];
	char	*res;
	char	*tmp;

	ft_memset(buff, 0, 2);
	res = ft_strdup("");
	while (read(fd, buff, 1) > 0)
	{
		tmp = res;
		res = ft_strjoin(res, buff);
		free(tmp);
	}
	return (res);
}

void	md5Executor(t_md5 *o)
{
	ft_md5((uint8_t *)o->input, ft_strlen(o->input));
	return ;

	if (o->q)
	{
		ft_md5((uint8_t *)o->input, ft_strlen(o->input));
		ft_printf("\n");
		return ;
	}
	if (o->p && !o->isFile)
		ft_printf("%s\n", o->input);
	if (o->isStr || o->isFile)
		stringFileCase(o);
	else
	{
		ft_md5((uint8_t *)o->input, ft_strlen(o->input));
		ft_printf("\n");
	}
}

int	tryOpen(char *fileName, t_md5 *o)
{
	int	fd;

	if (fd = open(fileName, O_RDONLY) <= 0)
	{
		ft_printf("%s: No such file or directory\n", fileName);
		return (0);
	}
	o->input = getInput(fd);
	o->isFile = 1;
	close(fd);
	return (1);
}

void	ft_md5Init(int ac, char **av)
{
	int		i;
	t_md5	o;

	i = 1;
	if (ac == 2)
		o.input = getInput(0);
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-r") == 0)
			o.r = 1;
		else if (ft_strcmp(av[i], "-q") == 0)
			o.q = 1;
		else if (ft_strcmp(av[i], "-p") == 0)
			o.p = 1;
		else if (ft_strcmp(av[i], "-s") == 0 && ac >= i + 1)
		{
			o.input = av[i + 1];
			o.isStr = 1;
		}
		else
			if (!tryOpen(av[i], &o))
				break;
	}
	md5Executor(&o);
}
