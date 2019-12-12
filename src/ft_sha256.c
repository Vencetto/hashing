
#include "ft_sha256.h"



void	sha256_update(t_sha256 *o, const unsigned char data[], size_t len)
{
	uint32_t i;

	i = -1;
	while (++i < len)
	{
		o->data[o->datalen] = data[i];
		o->datalen++;
		if (o->datalen == 64)
		{
			sha256_transform(o, o->data);
			o->bitlen += 512;
			o->datalen = 0;
		}
	}
}

void	save_vars_final(t_sha256 *o)
{
	o->bitlen += o->datalen * 8;
	o->data[63] = o->bitlen;
	o->data[62] = o->bitlen >> 8;
	o->data[61] = o->bitlen >> 16;
	o->data[60] = o->bitlen >> 24;
	o->data[59] = o->bitlen >> 32;
	o->data[58] = o->bitlen >> 40;
	o->data[57] = o->bitlen >> 48;
	o->data[56] = o->bitlen >> 56;
	sha256_transform(o, o->data);
}

void	save_hash_final(t_sha256 *o, unsigned char *hash[])
{
	uint32_t i;

	i = -1;
	while (++i < 4)
	{
		(*hash)[i]      = (o->state[0] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 4]  = (o->state[1] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 8]  = (o->state[2] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 12] = (o->state[3] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 16] = (o->state[4] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 20] = (o->state[5] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 24] = (o->state[6] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 28] = (o->state[7] >> (24 - i * 8)) & 0x000000ff;
	}
}

void	sha256_final(t_sha256 *o, unsigned char hash[])
{
	uint32_t i;

	i = o->datalen;
	if (o->datalen < 56)
	{
		o->data[i++] = 0x80;
		while (i < 56)
			o->data[i++] = 0x00;
	}
	else
	{
		o->data[i++] = 0x80;
		while (i < 64)
			o->data[i++] = 0x00;
		sha256_transform(o, o->data);
		ft_memset(o->data, 0, 56);
	}
	save_vars_final(o);
	save_hash_final(o, &hash);
}
