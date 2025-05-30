#include "libft.h"

char	*ft_strncpy(char *str, int nb)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (nb + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i] && i < nb)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
