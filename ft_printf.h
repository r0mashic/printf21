/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balysane <balysane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:09:15 by balysane          #+#    #+#             */
/*   Updated: 2022/01/13 17:33:18 by balysane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>    //va_* functions
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar_fd(char c);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s);
int	ft_puthex(unsigned long number, int is_pointer);
int	ft_un_putnbr_fd(unsigned int n, int fd);
int	ft_puthex_up(unsigned long number, int is_pointer);
int	ft_printf(const char *format, ...);

#endif
