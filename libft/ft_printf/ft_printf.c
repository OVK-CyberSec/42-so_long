/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:31:43 by mohifdi           #+#    #+#             */
/*   Updated: 2025/09/04 17:45:22 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

int	printf_format(char specifer, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, str);
	count = 0;
	while ((*str))
	{
		if (*str == '%')
			count += printf_format(*(++str), ap);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
