
include "../get_next_line/get_next_line.h"

int parse_args(int ac, char **av)
{
    if (ac != 2)
    {
        ft_printf("you most enter program name followed with a map\n");
        return (0);
    }
    else
    {
        if (!(strrchr(av[1], '.') == "ber"))
        {
            ft_printf("you must enter a valid map that ends with \".ber\"\n");
            return (0);
        }
        else
            return (1);
    }
    return (0);
}

int parse_map(int fd)
{
    int exit;
    int s_pos;
    int col;
    int 

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    
}