/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:56:21 by mwagner           #+#    #+#             */
/*   Updated: 2022/01/16 13:22:26 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int		max(int num_args, ...);
void	print(char *placeholders, ...);

int	main(void)
{
	print("ddfd", 4, 2, 10.5, 3);
	print("fffd", -4.5, 2.5, 10.5, 3);
	return (0);
}

int	max(int num_args, ...)
{
	va_list	args;

	va_start(args, num_args);
	va_end(args);
}

void	print(char *placeholders, ...)
{
	int		num_args;
	int		i;
	va_list	args;

	num_args = strlen(placeholders);
	va_start(args, placeholders);

	for (i = 0; i < num_args; i++)
	{
		if (placeholders[i] == 'd')
		{
			int x = va_arg(args, int);
			 printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
}
