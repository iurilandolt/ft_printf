/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:39:37 by rlandolt          #+#    #+#             */
/*   Updated: 2023/04/27 15:51:58 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long i)
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

static int	ft_putptr(unsigned long i)
{
	int count;
	if (i >= 16)
	{
		ft_putptr(i / 16);
		ft_putptr(i % 16);
	}
	else
	{
		if (i <= 9)
			count += ft_printchar(i + '0');
		else
			count += ft_printchar((i - 10 + 'a'));
	}
	return (count);
}

int	ft_printptr(unsigned long i)
{
	if (i == 0)
		return (ft_printstr("(nil)"));
	else
		ft_putptr(i);
	return (ft_ptrlen(i));
}
