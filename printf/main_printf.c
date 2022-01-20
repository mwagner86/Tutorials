/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:15:36 by mwagner           #+#    #+#             */
/*   Updated: 2022/01/13 14:20:09 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	ch;

	for (ch = 75; ch <= 100; ch++)
	{
		printf("ASCII value = %d, Character = %c\n", ch, ch);
	}
	return (0);
}
