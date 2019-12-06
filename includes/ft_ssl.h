/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:21:38 by vzomber           #+#    #+#             */
/*   Updated: 2019/11/23 15:21:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct	s_md5
{
	int			r;
	int			isStr;
	int			p;
	int			q;
	int			isFile;
	char			*fileName;
	char			*input;
	int			output[16];
}				t_md5;

void	ft_md5Init(int ac, char **av);
char	*ft_md5(uint8_t *initial_msg, size_t initial_len);
void	ft_sha256(char *inputStr);
char	*getInput(int fd);

#endif
