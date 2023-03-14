/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:09:43 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/14 01:28:55 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(void)
{
	int i = 42;
	int *ptr = &i;

	ft_printf("Hello World\n");
	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "I'm a 42 student");
	ft_printf("%p\n", i);
	ft_printf("%d\n", 42);
	ft_printf("%i\n", 21);
	ft_printf("%u\n", 4294967295);
	ft_printf("%x\n", 42);
	ft_printf("%X\n", 42);
	ft_printf("%%\n");
	return (0);
}
