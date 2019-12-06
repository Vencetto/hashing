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
	char *input;

	ft_md5((uint8_t *)o->input, ft_strlen(o->input), o);
	if (o->q)
	{
		printHashMD5(o, 1);
		return ;
	}
	if (o->p && !o->isFile)
		ft_printf("%s\n", o->input);
	if (o->isStr || o->isFile)
	{
		o->isFile ? (input = o->fileName) : (input = o->input);
		if (o->r)
		{
			printHashMD5(o, 0);
			ft_printf(" %s\n", input);
		}
		else
		{
			ft_printf("MD5 (%s) = ", input);
			printHashMD5(o, 1);
		}
	}
	else
		printHashMD5(o, 1);
}

int	tryOpen(char *fileName, t_md5 *o)
{
	int	fd;

	if ((fd = open(fileName, O_RDONLY)) < 0)
	{
		ft_printf("%s: No such file or directory\n", fileName);
		return (0);
	}
	o->input = getInput(fd);
	o->fileName = fileName;
	o->isFile = 1;
	close(fd);
	return (1);
}

void	checkFlagsMD5(int ac, char **av, t_md5 *o)
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
		else { printf(" open block");
			if (!tryOpen(av[i], o))
				break;}
	}
}

void	fullInit(t_md5 *o)
{
	o->h[0] = 0x67452301;
	o->h[1] = 0xefcdab89;
	o->h[2] = 0x98badcfe;
	o->h[3] = 0x10325476;
	o->newLen = ((((ft_strlen(o->input) + 8) / 64) + 1) * 64) - 8;
	o->msg = ft_memalloc(o->newLen + 64);
}

void	ft_md5Init(int ac, char **av)
{
	t_md5	o;

	ft_bzero(&o, sizeof(o));
	checkFlagsMD5(ac, av, &o);
	if (!o.isStr && !o.isFile)
		o.input = getInput(0);
	if (ft_strlen(o.input))
	{
		fullInit(&o);
		md5Executor(&o);
	}
	else
		ft_printf("Got no input.\n");
}
