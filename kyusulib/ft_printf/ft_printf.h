/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:55:36 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/09 11:20:06 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_switcher(va_list arg, char c);

int	ft_writer_c(va_list arg);
int	ft_writer_s(va_list arg);
int	ft_writer_udi(va_list arg, int is_un);
int	ft_writer_x(va_list arg, int is_upper);
int	ft_writer_p(va_list arg);

//int	ft_strlen(char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putposinbr(unsigned int un);
int	ft_puthex(unsigned long long val, int is_upper);

#endif
