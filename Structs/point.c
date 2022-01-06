#include <stdlib.h>
#include <stdio.h>

typedef struct Point
{
	double x;
	double y;
} Point; 

// This is the same as above: typedef struct Point Point;

void Point_print(const Point* self);

int main()
{
	Point aPoint = { 4.0, 8.0 };
	Point_print(&aPoint);
}

void Point_print(const Point *self)
{
	printf("%f, %f\n", self->x, self->y);
}
