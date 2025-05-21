#include "includes/so_long.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		set_content(&(data.content));
		data.map = map_core(argv, &data);
		if (data.map != NULL)
		{
			set_img(&data);
			core_render(&data);
		}
		else
			end(&data);
	}
	return (1);
}