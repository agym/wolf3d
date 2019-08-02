#include "prototypes.h"

t_vect2d	ft_vector(double x, double y)
{
	t_vect2d v;

	v.x = x;
	v.y = y;
}

t_point		ft_point(int x, int y)
{
	t_point v;

	v.x = x;
	v.y = y;
	return (v);
}


void		ft_setvector(t_vect2d *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

