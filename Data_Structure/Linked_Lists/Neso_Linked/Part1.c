#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int main()
{
 // memory needs to get allocated using malloc
	struct node *head = malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;

 // create and allocate memory for a 2nd pointer that points to the 2nd node of the list

	struct node *current = malloc(sizeof(struct node));
	current->data = 98;
	current->link = NULL;
	head->link = current; // updates the link part of the first node, curent contains the address of 2nd node
	return 0;
}