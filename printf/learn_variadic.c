/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_variadic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:03:31 by mwagner           #+#    #+#             */
/*   Updated: 2022/01/15 17:26:38 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int max(int num_args, ...);

int	main(void)
{
	printf("%d %f %d\n", 5, 10.5, 3);
	int max_num = max(8, 999, 12, 14, 16, 25, 3, 123, 99);
	printf("max_num: %d\n", max_num);
	
	return (0);
}

int max(int num_args, ...)
{
	va_list args;

	va_start(args, num_args);

	int max = 0;
	for (int i = 0; i < num_args; i++)
	{
		int x = va_arg(args, int);
		if (i == 0) max = x;
		else if (x > max) max = x;
	}
	
	va_end(args);

	return (max);
}
