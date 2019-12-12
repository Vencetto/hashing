/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionalmd5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:02:12 by vzomber           #+#    #+#             */
/*   Updated: 2019/12/07 15:02:13 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void	all_files(t_flags *f, char **av, int i, int ac)
{
	while (i < ac)
	{
		if (ft_strequ(av[1], "md5"))
			file_md5(f, av[i]);
		else if (ft_strequ(av[1], "sha256"))
			file_sha256(f, av[i]);
		i++;
	}
}

void	print_hash_md5(t_md5 *o, int new_line)
{
	int i;

	i = -1;
	while (++i < 4)
		ft_printf("%2.2x%2.2x%2.2x%2.2x", o->output[i][0],
		o->output[i][1], o->output[i][2], o->output[i][3]);
	if (new_line)
		ft_printf("\n");
}

void	print_hash_sha256(t_sha256 *o, int new_line)
{
	int i;

	i = -1;
	while (++i < 32)
		ft_printf("%2.2x", o->output[i]);
	if (new_line)
		ft_printf("\n");
}

int		try_open(char *file_name, char *input)
{
	int	fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_printf("%s: No such file or directory\n", file_name);
		return (0);
	}
	input = get_input(fd);
	close(fd);
	return (1);
}

char	*get_input(int fd)
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
