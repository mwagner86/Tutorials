/*What is designated Initialization?
Designated Initialization allows structure members to be initialized in any order. This feature has been added in C99 standard.
*/


#include <stdio.h>
  
struct Point
{
   int x, y, z;
};
  
int main()
{
   // Examples of initialization using designated initialization
   struct Point p1 = {.y = 0, .z = 1, .x = 2};
   struct Point p2 = {.x = 20};
  
   printf ("x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z);
   printf ("x = %d", p2.x);
   return 0;
}
/* 
Output:
x = 2, y = 0, z = 1
x = 20
This feature is not available in C++ and works only in C.
*/
