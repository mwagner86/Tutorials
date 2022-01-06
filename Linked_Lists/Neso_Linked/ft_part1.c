/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:52:21 by mwagner           #+#    #+#             */
/*   Updated: 2022/01/06 15:10:12 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void 			*content;
	struct s_list 	*next;
} 					t_list;

int main()
{
	t_list *head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	// head is now able to access t_list
	head->content = 45;
	head->next = NULL;

	printf("%d", head->content);
	return 0;
}
