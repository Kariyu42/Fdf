# How does the MinilibX work ?

## Manual:

```shell
$ man /urs/share/man/man3/mlx.1
```

La commande ci-dessus est la doc sur comment fonctionne la mlx, mais aussi comment elle fonctionne.

Il y a aussi, d'autre man dans ce meme repo, qui sont:
- mlx_loop.1
- mlx_new_image.1
- mlx_new_window.1
- mlx_pixel_put.1.

> Important:💡<br>
Afin de pouvoir utiliser la minilibx, il nous faut les bons flags... :<br>
```shell
$ gcc -I /usr/local/include <nom_du_binaire> -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
```

# How to create an image in MLX?
```c++
#include <mlx.h>

int	main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 640, 360, "Tuto WINDOW");

	void	*image = mlx_new_image(mlx, 640, 360);
	mlx_loop(mlx);
}
```
## The functions:
- __void *mlx_init();__ = used to __initialize__ the MinilibX library and set up the graphical environment for your application. The function takes no arguments and returns a void pointer. This pointer is a __handle__ to the MinilibX graphics context, which is used by other functions in the library to interact with the graphics system.

- __void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);__ = <br>
used to create a __new window__ or graphical frame in the MinilibX graphics context, which can be used to display graphics and handle user input. To use this function, we need a handle to the graphics context which is returned by the __mlx_init()__ function.

- __void *mlx_new_image(void *mlx_ptr, int width, int height);__ = <br>
used to create a new image or bitmap in memory that can be used for drawing graphics or storing pixel data. After creating the new image, we can proceed with other graphical-related code that makes use of the image, such as drawing graphics, manipulating pixel data, and copying the image to a window for display. <br>___Overall___, the mlx_new_image function provides us with a convenient way to create and manipulate images in the Minilibx, which is essential for creating graphical applications.

- __void mlx_loop(void *mlx_ptr);__ = to enter the __graphics event loop__, which listens for user input and other events, and handles them by calling registered event handling functions. The function does not return any value. Instead, it enters an infinite loop that listens for events and calls registered event handling functions as necessary. While this function is running, itlistens for events such as mouse clicks, keyboard input, and window resizing. When an event occurs, it calls the registered event handling functions, which can perform actions such as redrawing the graphics, updating the window, or changing the program state.

# Window Created! Now What?
```c
int	pixel_bits;
int	line_bytes;
int	endian;
char	*buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
```

## mlx_get_data_addr(void *img_ptr, int *bits_per_picel, int *size_line, int *endian) function:
- it is used to get information about the memory layout of a pixel image or bitmap that is stored in memory. The function returns a char * to the start of the image or bitmap data in memory.

The function takes four arguments:<br>

- __img_ptr__: A handle to the image or bitmap that you want to get information about. This handle is returned by the mlx_new_image() function.
- __bits_per_pixel__: A pointer to an integer that will be filled with the number of bits per pixel int the image or bitmap.
- __size_line__: will be filled with the number of bytes per row in the image or bitmap.
- __endian__: filled with the endianness of the pixel data in the image.

## Example
```c++
#include <mlx.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int main(void)
{
	void *mlx_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (img.img == NULL)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (0);
}
```

In the example above we first initialize the MiniLibX library by calling mlx_init and obtaining a handle to the graphics context. We then create a new image by calling mlx_new_image and obtain information about the image data by calling mlx_get_data_addr. The function fills the bits_per_pixel, size_line, and endian variables with information about the image data layout, and returns a char pointer to the start of the image data.

- Once you have used the mlx_get_data_addr function to get a pointer to the image data, you can use this pointer to modify the pixel data of the image.

The image data is stored as a contiguous block of memory, with each pixel represented by a series of bytes according to the image's format. You can use pointer arithmetic to navigate through this block of memory and modify individual pixels by changing their color values.

For example, if you wanted to set the color of the pixel at position (x,y) in the image to red, you could use the following code:

```c++
char *img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

int pixel_index = (y * size_line) + (x * (bits_per_pixel / 8));

unsigned int color = mlx_get_color_value(mlx_ptr, 0xFF0000); // red color

*(unsigned int *)(img_data + pixel_index) = color;
```


