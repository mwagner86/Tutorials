// C program to show Arrow operator
// used in structure

#include <stdio.h>
#include <stdlib.h>

// Creating the structure
typedef struct student {
	char name[80];
	int age;
	float percentage;
}student;

// Creating the structure object
student *emp = NULL;

// Driver code
int main()
{
	// Assigning memory to struct variable emp
	emp = (student*)
		malloc(sizeof(student));
	
	// Assigning value to age variable
	// of emp using arrow operator
	emp->age = 18;


	// Printing the assigned value to the variable
	printf("%d \n", emp->age);

	return 0;
}
