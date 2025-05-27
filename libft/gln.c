#include "libft.h"

char	*ft_stradd(char *str, char buff)
{
	int		i = 0;
	char	*ret;

	if (!str)
	{
		ret = (char *)malloc(2 * sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = buff;
		ret[1] = '\0';
		return (ret);
	}

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}


int	gnl(int fd, char **str)
{
	char			buff;
	int				ret;

	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff);
		if (buff == '\n')
			return (ret);
		else
			ret += 1;
		ret = read(fd, &buff, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}