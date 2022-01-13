/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balysane <balysane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:06:09 by balysane          #+#    #+#             */
/*   Updated: 2022/01/13 17:43:28 by balysane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_cheker(va_list *args, const char *format,
int *i, int *counter)
{
	if (format[*i + 1] == 'c' )
		*counter += ft_putchar_fd(va_arg(*args, int));
	else if (format[*i + 1] == 's')
		*counter += ft_putstr_fd(va_arg(*args, char *));
	else if (format[*i + 1] == 'p')
		*counter += ft_puthex((unsigned long)va_arg(*args, void *), 1);
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		*counter += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format[*i + 1] == 'u')
		*counter += ft_un_putnbr_fd(va_arg(*args, unsigned int), 1);
	else if (format[*i + 1] == 'x')
		*counter += ft_puthex(va_arg(*args, unsigned int), 0);
	else if (format[*i + 1] == 'X')
		*counter += ft_puthex_up(va_arg(*args, unsigned int), 0);
	else if (format[*i + 1] == '%')
		*counter += ft_putchar_fd('%');
	*i += 2;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_printf_cheker(&args, format, &i, &counter);
			if (!format[i])
				break ;
		}
		else
			counter += ft_putchar_fd(format[i++]);
	}
	va_end(args);
	return (counter);
}
