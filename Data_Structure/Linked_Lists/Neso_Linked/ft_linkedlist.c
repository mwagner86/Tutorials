#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void 			*content;
	struct s_list 	*next;
} 					t_list;

void count_of_nodes(t_list *lst);
int	ft_lstsize(t_list *lst);

int main(void)
{

	int x[3] = {45, 98, 36};

	t_list *lst = malloc(sizeof(t_list));
	lst->content = &x[0];
	lst->next = NULL;
	printf("%d\n", *(int *)lst->content);

	t_list *current = malloc(sizeof(t_list));
	current->content = &x[1];
	current->next = NULL;
	lst->next = current;
	printf("%d\n", *(int *)current->content);
	
	current = malloc(sizeof(t_list));
	current->content = &x[2];
	current->next = NULL;

	lst->next->next = current;
	printf("%d\n", *(int *)current->content);
	printf("%d\n", current->next);

	count_of_nodes(lst);
	ft_lstsize(lst);

	return 0;
}
