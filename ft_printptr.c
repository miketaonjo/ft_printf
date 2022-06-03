/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:53:13 by mcloarec          #+#    #+#             */
/*   Updated: 2022/04/27 15:15:39 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len++;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_basehexa(unsigned long long ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr > 15)
	{
		ft_putnbr_basehexa(ptr / 16);
		ft_putnbr_basehexa(ptr % 16);
	}
	else
		ft_printchar(base[ptr]);
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len = ft_printstr("(nil)");
	else
	{
		len = ft_printstr("0x");
		ft_putnbr_basehexa(ptr);
		len = len + ft_lenptr(ptr);
	}
	return (len);
}
