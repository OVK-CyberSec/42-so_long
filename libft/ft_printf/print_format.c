/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:35:41 by mohifdi           #+#    #+#             */
/*   Updated: 2025/09/04 17:39:54 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

int	print_char(int c);
int	print_string(char *str);
int	print_digit(long nbr, int base);
int	print_digit_upper(unsigned int nbr, unsigned int base);

int	printf_format(char specifer, va_list ap)
{
	int	count;

	count = 0;
	if (specifer == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifer == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifer == 'd' || specifer == 'i')
		count += print_digit(va_arg(ap, int), 10);
	else if (specifer == 'x')
		count += print_digit(va_arg(ap, unsigned int), 16);
	else if (specifer == 'X')
		count += print_digit_upper(va_arg(ap, unsigned int), 16);
	else if (specifer == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (specifer == 'u')
		count += print_digit(va_arg(ap, unsigned int), 10);
	else if (specifer == '%')
		count += print_char('%');
	return (count);
}
