/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:12:02 by rlandolt          #+#    #+#             */
/*   Updated: 2023/04/27 16:12:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int i)
{
	int count;

	count = 0;
	while (i > 0)
	{
		count++;
		i /= 16;
	}
	return (count);
}

static int	ft_puthex(unsigned int i, const char c)
{
	int count;

	count = 0;
	if (i >= 16)
	{
		ft_puthex(i / 16, c);
		ft_puthex(i % 16, c);
	}
	else
	{
		if (i <= 9)
			count += ft_printchar(i + '0');
		else
		{
			if (c == 'x')
				count += ft_printchar((i - 10 + 'a'));
			else if (c == 'X')
				count += ft_printchar((i - 10) + 'A');
		}
	}
	return (count);
}

int ft_printhex(unsigned int i, const char c)
{
	if (i == 0)
		return(ft_printchar('0'));
	else
		ft_puthex(i, c);
	return (ft_hexlen(i));
}
