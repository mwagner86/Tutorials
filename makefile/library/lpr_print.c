// Tutorial function
// http://www.crasseux.com/books/ctutorial/Building-a-library.html 
// Function accepts one string containing some text to print, and then prints it on the default printer.

#include <stdio.h>

void lpr_print (char *the_text)
{
  FILE *printer;

  printer = popen ("lpr", "w");
  fprintf (printer, the_text);
  pclose (printer);
}
