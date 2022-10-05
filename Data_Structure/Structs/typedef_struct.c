#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person_list
{
	char 	*name;
	int 	age;
} person;

int main(void)
{
	person var;

	/* testing code */
	var.name = malloc(4 * sizeof(char));
	strcpy(var.name, "Max");
	var.age = 27;
	printf("%s is %d years old.\n", var.name, var.age);

	// create a pointer to struct
	person *var_ptr = &var;

	// set some data, again
	(*var_ptr).age = 33;
	(*var_ptr).name = realloc((*var_ptr).name, 7 * sizeof(char));
	strcpy((*var_ptr).name, "Brian!");
	printf("%s is %d years old.\n", var.name, var.age);

	// set some data, again, but with better syntax
	var_ptr-> age = 34;
	var_ptr-> name = realloc(var_ptr->name, 8 * sizeof(char));
	strcpy(var_ptr->name, "Brian!!");
	printf("%s is %d years old.\n", var.name, var.age);
}
