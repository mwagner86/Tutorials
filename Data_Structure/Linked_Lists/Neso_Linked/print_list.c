#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};


void print_data(struct node *head)
{
	if (head == NULL)
	printf ("Linked List is empty");
	
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
}
