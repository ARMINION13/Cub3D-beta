/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:42:37 by rgirondo          #+#    #+#             */
/*   Updated: 2020/07/02 18:49:46 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"

int				ft_atoi(const char *str);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_itoa(long long n, int p);
int				ft_numlen(long long a, int base, int p);
int				ft_putchar_fd(char c);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n);
char			*ft_itoa_v2(unsigned long n, int base, char asci, int p);

typedef struct	s_flags
{
	char	flag;
	int		width;
	int		precision;
	char	type;
}				t_flags;

int				ft_printf(const char *str, ...);
int				ft_flags(char *str, va_list args, int a, t_flags *flags);
int				ft_types(char c, t_flags *flags, va_list args);
int				ft_mvnbr(char *str);
int				ft_initialize(t_flags *flags);
int				ft_width(int a, char b);
int				ft_char_flags(t_flags *flags, va_list args);
int				ft_str_flags(t_flags *flags, va_list args);
int				ft_nbr_flags(t_flags *flags, va_list args);
int				ft_x_flags(t_flags *flags, va_list args, int base, char c);
int				ft_memadd_flags(t_flags *flags, va_list args);
int				ft_strlen2(const char *str, int i);
int				ft_null_str(char *str);
int				ft_100_flags(t_flags *flags);
int				take_precision(char *str, va_list args, t_flags *flags);
int				take_width(char *str, va_list args, t_flags *flags);
int				nbr_if_1(t_flags *flags, va_list args);
int				nbr_if_2(t_flags *flags, va_list args);
int				nbr_if_3(t_flags *flags, va_list args);
int				x_if_1(t_flags *flags, va_list args, int base, char c);
int				x_if_2(t_flags *flags, va_list args, int base, char c);
int				x_if_3(t_flags *flags, va_list args, int base, char c);
int				str_if_1(t_flags *flags, va_list args);
int				str_if_2(t_flags *flags, va_list args);
int				str_if_3(t_flags *flags, va_list args);
int				memadd_if_1(t_flags *flags, va_list args);
int				memadd_if_2(t_flags *flags, va_list args);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
