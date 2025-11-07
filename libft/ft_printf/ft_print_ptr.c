/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:33:27 by mohifdi           #+#    #+#             */
/*   Updated: 2025/09/04 17:44:14 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> 

int	print_ptr(void *ptr)
{
	uintptr_t	addr;
	int			count;
	char		hex[16];
	char		*digits;
	int			i;

	digits = "0123456789abcdef";
	addr = (uintptr_t)ptr;
	i = 0;
	count = 0;
	count += write(1, "0x", 2);
	if (addr == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	while (addr)
	{
		hex[i++] = digits[addr % 16];
		addr /= 16;
	}
	while (i--)
		count += write(1, &hex[i], 1);
	return (count);
}
