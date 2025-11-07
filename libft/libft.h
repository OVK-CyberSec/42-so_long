/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:00:36 by mohifdi           #+#    #+#             */
/*   Updated: 2025/11/07 20:01:16 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_stradd(char *str, char buff);
int		gnl(int fd, char **str);
char	*ft_strncpy(char *str, int nb);
char	**ft_split(char *str, char sep);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//ft_printf
int		print_ptr(void *ptr);
int		printf_format(char specifer, va_list ap);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
int		print_char(int c);
int		print_string(char *str);
int		print_digit(long nbr, int base);
int		print_digit_upper(unsigned int nbr, unsigned int base);

#endif
