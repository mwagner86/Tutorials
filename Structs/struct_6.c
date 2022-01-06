// What is a structure pointer?
// Like primitive types, we can have pointer to a structure. If we have a pointer to structure, members are accessed using arrow ( -> ) operator.


#include <stdio.h>
 
struct Point
{
   int x, y;
};
  
int main()
{
   struct Point p1 = {1, 2};
  
   // p2 is a pointer to structure p1
   struct Point *p2 = &p1;
  
   // Accessing structure members using structure pointer
   printf("%d %d", p2->x, p2->y);
   return 0;
}
// Output:
// 1 2