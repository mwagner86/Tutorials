/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librarytest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:16:34 by mwagner           #+#    #+#             */
/*   Updated: 2021/12/11 14:19:48 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mycode.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", reverse(argv[1]));
	}
}
