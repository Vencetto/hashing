/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:26:07 by vzomber           #+#    #+#             */
/*   Updated: 2019/12/07 19:26:11 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "ft_md5.h"

#include <openssl/opensslconf.h>

#include <stdlib.h>
#include <string.h>

#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/opensslv.h>

void			ft_sha256_init(int ac, char **av);
unsigned char	*SHA256(const unsigned char *d, size_t n, unsigned char *md);

#endif
