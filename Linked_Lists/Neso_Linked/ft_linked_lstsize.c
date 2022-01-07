#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void 			*content;
	struct s_list 	*next;
} 					t_list;

void count_of_nodes(t_list *lst)
{

	int count = 0;
	if (lst == NULL)
		printf("Linked list is empty");
	t_list *ptr = NULL;
	ptr = lst;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	printf("Number of Nodes: %d\n", count);
}