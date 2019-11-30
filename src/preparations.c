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

char	*ft_reverse(char **strToReverse)
{
	char	*tempStr;
	int		i;
	int		len;

	ft_printf("%s %p\n", *strToReverse, *strToReverse);
	tempStr = ft_strdup(*strToReverse);
	ft_printf("%s %p\n", tempStr, tempStr);
	len = ft_strlen(*strToReverse);
	i = 0;
	while (i < len)
	{
		(*strToReverse)[i] = tempStr[len - i + 1];
		(*strToReverse)[i + 1] = tempStr[len - i + 2];
		i += 2;
	}
	free(tempStr);
	system("leaks ./ft_ssl");
	return (*strToReverse);
}

void	md5Executor(t_md5 *o)
{
	char	*output;

	output = ft_md5((uint8_t *)o->input, strlen(o->input));
	if (o->q)
	{
		ft_printf("%s\n", output);
		return ;
	}
	if (o->p)
		ft_printf("%s\n", o->input);
	if (o->r){
		ft_printf("%s %p\n", output, output);
		output = ft_reverse(&output);
		ft_printf("%s %p\n", output, output);
	}
	if (o->s)
		ft_printf("MD5 (\"%s\") = ", output);
	else
		ft_printf("%s\n", output);
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
			o.s = 1;
		}
	}
	md5Executor(&o);
}
