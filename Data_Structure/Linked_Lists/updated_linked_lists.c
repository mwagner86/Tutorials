#include <stdio.h>
#include <stdlib.h>

struct sPerson
{
	int age;
	struct sPerson *nextInLine;
};

// create a new Pointer to sPerson structure
struct sPerson *getNewPerson(const int age)
{
// Make a pointer to a new structure
struct sPerson *newPerson = NULL;
// allocate Memory
newPerson = malloc(sizeof(struct sPerson));
// Assign nextInLine to NULL (as in not pointing to anything)
newPerson->nextInLine = NULL;
// Assign the age value
newPerson->age = age;
// Print the memory address
printf("new person at %p\n", newPerson);
return (newPerson);
}

void printPerson(const struct sPerson *person, const char *comment)
{
	if (person == NULL)
	{
		printf("%s is NULL\n", comment);
	}

	else
	{
		printf("%s: age:%d adress:%p nextInLine:%p\n",
			comment,
			person->age,
			person,
			person->nextInLine);
	}
}

int main()
{
	printf("\n\n** START **\n\n");

	struct sPerson *first = NULL;
	struct sPerson *second = NULL;

	printPerson(first, "first");
	printPerson(second, "second");

	first = getNewPerson(125);
	second = getNewPerson(100);

	printPerson(first, "first");
	printPerson(second, "second");

	// make the link between the first and the second:
	// the first next-in-line pointer points to the same address that second is pointing to

	first->nextInLine = second;

	printPerson(first, "first");
	printPerson(first->nextInLine, "first->nextInLine");
	printPerson(second, "second");

	// free the memory with the free fuction.
	// when you don't need the memory anymore it should always be freed

	free(first);
	free(second);

	// any Pointers that are pointing to that memory should be set back to NULL,
	// otherwise the memory is freed but the pointers are still pointing to that particular address in the memory.
	// that can cause Problems.

	first = NULL;
	second = NULL;

	return 0;
}