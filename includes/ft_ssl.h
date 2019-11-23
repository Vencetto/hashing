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

# include "../libft/get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))


void	ft_md5(uint8_t *initial_msg, size_t initial_len);


#endif
