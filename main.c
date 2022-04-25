//111111111
//100000001
//100000001
//100000001
//100000001
//100000001
//100000001
//111111111


//HACER LAS FUNCIONES QUE MANAGEEN EN MEMORIA LOS PATH Y LOS COLORES EN MLX
#include "./cub3d.h"

int	resolution_Y = 320;
int	resolution_X = 530;
int R;
int G;
int B;

int main()
{
	v_global	vars;

	vars.position_X = 2.1;
	vars.position_Y = 2.1;
	vars.pi = M_PI;
	vars.one_rad = M_PI / 180;
	vars.dir =M_PI * 1.5;
	vars.fov = 100;
	vars.image = 0;
	vars.ray_dir = 0;
	//vars_initialize(vars);
	vars.mlx_int = mlx_init();
	vars.screen = mlx_new_window(vars.mlx_int, resolution_X, resolution_Y, "screen");
	//move(&vars);
	vars.map = ft_cut_map(
	   "111111111\n111111111\n11010000011\n11000000011\n11001100011\n11000000011\n11000000011\n11000000011\n111111111\n111111111");
	mlx_hook(vars.screen, 2, 1L<<0, deal_keys, &vars);
	//mlx_hook(vars.screen, 3, 1L<<1, deal_key_release, &vars);
	//mlx_loop_hook(vars.mlx_int, drawray_3D, &vars);
	mlx_loop(vars.mlx_int);
}

void	*canvas(char *img_data, int R, int G, int B, int i, int j)
{
	int x;
	int y;

	y = j;
	while (++y < resolution_Y)
	{
		x = 0;
		while (x < (resolution_X * 4))
		{
			img_data[y * (i * 4) + x] = B;//blue
			x++;
			img_data[y * (i * 4) + x] = G;//green
			x++;
			img_data[y * (i * 4) + x] = R;//red
			x = x + 2;
		}
	}
	return(0);
}

void	*wall(char *img_data, int R, int G, int B, int i, int j)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < j)
	{
		x = 0;
		while (x < (i * 4))
		{
			img_data[y * (i * 4) + x] = B;//blue
			x++;
			img_data[y * (i * 4) + x] = G;//green
			x++;
			img_data[y * (i * 4) + x] = R;//red
			x++;
			img_data[y * (i * 4) + x] = 1;//T
			x++;
		}
	}
	return(0);
}

int		deal_keys(int key, v_global *vars)
{
	mlx_clear_window(vars->mlx_int, vars->screen);
	if(key == 0)
		vars->dir += vars->pi / 18;
	if(key == 1)
	{
		if(vars->map[(int)(vars->position_Y)]
			[(int)(vars->position_X - (cos(vars->dir) / 10))] == '0')
			vars->position_X -= (cos(vars->dir) / 10);
		if(vars->map[(int)(vars->position_Y + (sin(vars->dir) / 10))]
			[(int)(vars->position_X)] == '0')
			vars->position_Y += (sin(vars->dir) / 10);
	}	
	if(key == 2)
		vars->dir -= vars->pi / 18;
	if(key == 13)
	{
		if(vars->map[(int)(vars->position_Y)]
			[(int)(vars->position_X + (cos(vars->dir) / 10))] == '0')
			vars->position_X += (cos(vars->dir) / 10);
		if(vars->map[(int)(vars->position_Y - (sin(vars->dir) / 10))]
			[(int)(vars->position_X)] == '0')
			vars->position_Y -= (sin(vars->dir) / 10);
	}	
	if(key == 53)
		mlx_destroy_window(vars->mlx_int, vars->screen);
	if(vars->dir > (2 * vars->pi))
		vars->dir = 0;
	if(vars->dir < 0)
		vars->dir = (2 * vars->pi);
	drawray_3D(vars);
	//ft_printf("x=%i,y=%i,dir=%i\n", (int)vars->position_X, (int)vars->position_Y, (int)vars->dir);
	return (0);
}

char		**ft_cut_map(char *map)
{
	char	**cut_map;	
	int	a;
	int	b;
	int	c;
	
	c = 0;
	b = 0;
	a = 0;
	cut_map = 0;
	while(map[a] != '\0')
	{
		if (map[a] == '\n' && map[a + 1] != '\0')
			b++;	
		a++;
	}
	b++;
	if(!(cut_map = (char**)malloc(sizeof(char*) * b)))
		return(0);
	a = 0;
	while(c != b)
	{
		if (map[a] == '\n' || map[a] == '\0')
		{
			cut_map[c] = ft_strldup(map, a - 1);
			map += a + 1;
			a = 0;
			c++;
		}
		a++;
	}
	/*a = -1;
	while(cut_map[a++])
		ft_printf("%c\n%i\n", cut_map[a]);*/
	return(cut_map);
}

char	*ft_strldup(const char *s, int i)
{
	char	*str;

	if (!(str = malloc(i + 2)))
		return (0);
	str[i + 1] = '\0';
	if (str != 0)
	{
		while (i >= 0)
		{
			str[i] = s[i];	
			i--;
		}
	}	
	return (str);
}

void rgb_set_vertical(v_global *vars)
{
	if (vars->ray_dir > (M_PI / 2) && vars->ray_dir < (M_PI * 1.5))
	{
		R = 252;
		G = 3;
		B = 3;
	}
	if (vars->ray_dir < (M_PI / 2) || vars->ray_dir > (M_PI * 1.5))
	{
		R = 252;
		G = 252;
		B = 3;
	}
}

void rgb_set_horizontal(v_global *vars)
{
	if (vars->ray_dir < M_PI && vars->ray_dir > 0)
	{
		R = 36;
		G = 252;
		B = 3;
	}
	else
	{
		R = 3;
		G = 252;
		B = 236;
	}
}

int horizontal_coll(v_global *vars)
{
	double ray_x;
	double ray_y;

	ray_x = vars->position_X;
	ray_y = vars->position_Y;
	if (vars->ray_dir > 0 && vars->ray_dir < vars->pi)
		ray_y =  (int)ray_y - 0.00000000001;
	else
		ray_y =  (int)ray_y + 1;
	ray_x += (vars->position_Y - ray_y) / (tan(vars->ray_dir) + 0.00000001);
	//necesito el tamaño del mapa para esta parte
	while ((int)ray_y <= 9 && (int)ray_x <= 10 && (int)ray_y >= 0 && (int)ray_x >= 0)
	{
		if (vars->map[(int)ray_y][(int)ray_x] == '1')
			return (calc_dist(ray_x, ray_y, vars));
		if (vars->ray_dir > 0 && vars->ray_dir < vars->pi)
			ray_y -= 1.00000000001;
		else
			ray_y += 1;
		if (vars->ray_dir > 0 && vars->ray_dir < vars->pi)
			ray_x += 1 / tan(vars->ray_dir);
		else
			ray_x -= 1 / tan(vars->ray_dir);
	}
	return (-1);
}

int vertical_coll(v_global *vars)
{
	double ray_x;
	double ray_y;

	ray_x = vars->position_X;
	ray_y = vars->position_Y;
	if (vars->ray_dir < vars->pi / 2 || vars->ray_dir > vars->pi * 1.5)
		ray_x = 1 + (int)ray_x;
	else
		ray_x = (int)(ray_x) - 0.00000000001;
	ray_y += (vars->position_X - ray_x) * tan(vars->ray_dir);
	//necesito el tamaño del mapa para esta parte
	while ((int)ray_y <= 9 && (int)ray_x <= 10 && (int)ray_y >= 0 && (int)ray_x >= 0)
	{
		if (vars->map[(int)ray_y][(int)ray_x] == '1')
			return (calc_dist(ray_x, ray_y, vars));
		if (vars->ray_dir < vars->pi / 2 || vars->ray_dir > vars->pi * 1.5)
			ray_x += 1;
		else
			ray_x -= 1.00000000001;
		if (vars->ray_dir < vars->pi / 2 || vars->ray_dir > vars->pi * 1.5)
			ray_y -= tan(vars->ray_dir);
		else
			ray_y += tan(vars->ray_dir);
	}
	return (-1);
}

float to_degree(float angle)
{
	return (angle * 180 / M_PI);
}

int	drawray_3D(v_global *vars)
{
	int	nbr_ray;
	int dist;
	int dist2;	

	nbr_ray = 0;
	dist = 0;
	dist2 = 0;
	create_img(vars);
	while(nbr_ray < resolution_X)
	{
		vars->ray_dir = vars->dir - atan(tan((M_PI / 2) / 2.0) * (2.0 * nbr_ray / resolution_X - 1.0));
		vars->ray_dir = vars->ray_dir < 0 ? (M_PI * 2) + vars->ray_dir : vars->ray_dir;
		vars->ray_dir = vars->ray_dir > (M_PI * 2) ? vars->ray_dir - (M_PI * 2) : vars->ray_dir;
		if (vars->ray_dir == M_PI || vars->ray_dir == 0 || vars->ray_dir == (M_PI * 1.5) || vars->ray_dir == (M_PI / 2))
			vars->ray_dir += 0.0000001;
		dist = vertical_coll(vars);
		dist2 = horizontal_coll(vars);
		if ((dist < dist2 && dist2 > 0) || dist < 0)
		{
			if (dist != dist2)
				rgb_set_horizontal(vars);
			draw_vertical(vars, nbr_ray, dist2);
		}
		else
		{
			if (dist != dist2)
				rgb_set_vertical(vars);
			draw_vertical(vars, nbr_ray, dist);
		}
		nbr_ray += 1;
	}
	mlx_put_image_to_window(vars->mlx_int, vars->screen, vars->image, 0, 0);
	return(0);
}

int	calc_dist(double ray_x, double ray_y, v_global *vars)
{
	double	dist;
	double	seg_x;
	double	seg_y;
	int	i;
	double not_feye;
	
	not_feye = vars->dir - vars->ray_dir;
	i = 0;
	seg_x = (ray_x - vars->position_X);
	seg_y = (ray_y - vars->position_Y);
	dist = sqrt((seg_x * seg_x) + (seg_y * seg_y));
	if (not_feye < 0)
		not_feye += 2 * vars->pi;
	if (not_feye > (2 * vars->pi))
		not_feye -= 2 * vars->pi;
	dist = dist * cos(not_feye);
	return ((resolution_Y)/(dist));
}

int	draw_pixel(char *img_addr, int r, int g, int b)
{
	img_addr[0] = b;
	img_addr[1] = g;
	img_addr[2] = r;
	return (4);
}

int	draw_vertical(v_global *vars, int x, int dist)
{
	int i;
	char *pixel_addr;

	pixel_addr = vars->img_data + (x * 4);
	if (dist > resolution_Y || dist <= 0)
		dist = resolution_Y - 1;
	i = dist;
	pixel_addr = pixel_addr + ((((resolution_Y - i) / 2) * ((resolution_X) * 4)));
	while(i > 0)
	{
		draw_pixel(pixel_addr, R, G, B);
		i--;
		pixel_addr += (resolution_X * 4);
		if (!pixel_addr)
			break;
	}
	return(1);
}

int	create_img(v_global *vars)
{
	int			bpp;
	int			size_line;
	int			endian;
	
	if(vars->image != 0)
		mlx_destroy_image(vars->mlx_int, vars->image);
	mlx_clear_window(vars->mlx_int, vars->screen);
	vars->image = mlx_new_image(vars->mlx_int, resolution_X, resolution_Y);	
	vars->img_data = mlx_get_data_addr(vars->image, &bpp, &size_line, &endian);
	return(1);
}