/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balysane <balysane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:07:44 by balysane          #+#    #+#             */
/*   Updated: 2022/01/13 17:43:54 by balysane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(int *n, int fd)
{
	if (*n == -2147483648)
	{
		ft_putstr_fd("-2147483648");
		return (1);
	}
	else
	{
		*n *= -1;
		write(fd, "-", 1);
		return (0);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	char	output;
	int		counter;

	counter = 0;
	if (n < 0)
	{
		if (check(&n, fd) == 1)
			return (11);
		else
			counter++;
	}
	if (n < 10 && n >= 0)
	{
		output = n + 48;
		write(fd, &output, 1);
		counter++;
		return (counter);
	}
	else
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	return (counter);
}

int	ft_un_putnbr_fd(unsigned int n, int fd)
{
	char	output;
	int		counter;

	counter = 0;
	if (n < 10)
	{
		output = n + 48;
		write(fd, &output, 1);
		counter++;
		return (counter);
	}
	else
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	return (counter);
}

int	ft_putstr_fd(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr_fd("(null)"));
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i]);
	return (i);
}

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}
