/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:53:26 by mwagner           #+#    #+#             */
/*   Updated: 2022/01/15 17:01:00 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int printf (const char *format, ...)
{
	va_list args;
	int done;

	va_start (args, format);
	done = vfprintf (stdout, format, args);
	va_end (args);

	return done;
}

int main()
{
	printf("Something we don't want to say.\n");
	printf("Max says, \"Hello World\"\n");

	return (0);
}