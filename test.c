#include <stdio.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*buffer;

	int	bpp;
	int	line_bytes;
	int	endian;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	mlx_win = mlx_new_window(mlx, 1440, 800, "test.c test window");
	if (mlx_win == NULL)
		return (1);
	img = mlx_new_image(mlx, 2560, 1000);
	if (img == NULL)
		return (1);
	buffer = mlx_get_data_addr(img, &bpp, &line_bytes, &endian);
	// bits_per_pixel = 32
	// line_bytes = 7680
	// endian = 0
	int	i = 50;
	int	y = 50;
	while (i < 250)
	{
		mlx_pixel_put(mlx, mlx_win, i, y, 0xFFFFFF);
		i++;
		y++;
	}
	mlx_loop(mlx);
	return (0);
}

/*int	main(void)
{
	int	i = 0;
	int	table[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	length = sizeof(table) / sizeof(int);
	printf("length = %d\n", length);
	while (i < length)
	{
		printf("table[%d] = %d\n", i, table[i]);
		i++;
	}
	return (0);
}*/
