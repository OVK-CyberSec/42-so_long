#include "so_long.h"
	
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\nThis program takes 1 argument .ber\n");
		return (1);
	}

	data.count = 0;
	data.mlx_ptr = mlx_init();
	set_content(&(data.content));

	data.map = map_core(argv, &data); // argv est correct ici
	if (!data.map)
		end(&data);

	check_path_valid(&data); // flood fill

	set_img(&data);
	core_render(&data);

	return (0);
}
