#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_global
{
	double	position_X;
	double	position_Y;
	double	pi;
	double  one_rad;
	double	dir;
	double	ray_dir;
	void	*mlx_int;
	void	*screen;
	void 	*image;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_w;
	int	key_esc;
	int	fov;
	char	**map;
	char	*img_data;
}		v_global;

void	*canvas(char *img_data, int R, int G, int B, int i, int j);
void	*wall(char *img_data, int R, int G, int B, int i, int j);
void	draw_wall(double nbr_ray, double dist, v_global *vars);
int	deal_key_press(int key, v_global *vars);
int	deal_key_release(int key, v_global *vars);
int	deal_keys(int key, v_global *vars);
char	**ft_cut_map(char *map);
char	*ft_strldup(const char *s, int i);
int	drawray_3D(v_global *vars);
int	calc_dist(double ray_x, double ray_y, v_global *vars);
int	draw_vertical(v_global *vars, int x, int dist);
int	create_img(v_global *vars);
int	draw_pixel(char *img_addr, int r, int g, int b);
//int	deal_key_release(int key, void *param);