# How does the mlx work ?

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


