
#include "ft_sha256.h"

void	save_vars(t_sha256 *o, t_sha_vars *v)
{
	v->a = o->state[0];
	v->b = o->state[1];
	v->c = o->state[2];
	v->d = o->state[3];
	v->e = o->state[4];
	v->f = o->state[5];
	v->g = o->state[6];
	v->h = o->state[7];
}

void	mix_vars(t_sha256 *o, t_sha_vars *v)
{
	uint32_t i;

	i = -1;
	while (++i < 64)
	{
		v->t1 = v->h + EP1(v->e) + CH(v->e, v->f, v->g) + g_kk[i] + v->m[i];
		v->t2 = EP0(v->a) + MAJ(v->a, v->b, v->c);
		v->h = v->g;
		v->g = v->f;
		v->f = v->e;
		v->e = v->d + v->t1;
		v->d = v->c;
		v->c = v->b;
		v->b = v->a;
		v->a = v->t1 + v->t2;
	}
}

void	record_result(t_sha256 *o, t_sha_vars *v)
{
	o->state[0] += v->a;
	o->state[1] += v->b;
	o->state[2] += v->c;
	o->state[3] += v->d;
	o->state[4] += v->e;
	o->state[5] += v->f;
	o->state[6] += v->g;
	o->state[7] += v->h;
}

void	sha256_transform(t_sha256 *o, const unsigned char data[])
{
	t_sha_vars v;
	uint32_t i;
	uint32_t j;

	ft_bzero(&v, sizeof(v));
	i = -1;
	j = 0;
	while (++i < 16)
	{
		v.m[i] = (data[j] << 24) | (data[j + 1] << 16) |
			 (data[j + 2] << 8) | (data[j + 3]);
		j += 4;
	}
	while (i < 64)
	{
		v.m[i] = SIG1(v.m[i - 2]) + v.m[i - 7]
			+ SIG0(v.m[i - 15]) + v.m[i - 16];
		i++;
	}
	save_vars(o, &v);
	mix_vars(o, &v);
	record_result(o, &v);
}
