/* strtol example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

int main ()
{
  char szNumbers[] = "N1 G1 X12 Y13 E12 F100*50";
  char * pEnd;
  long int li1, li2, li3, li4;
  li1 = strtol (szNumbers,&pEnd,10);
  li2 = strtol (pEnd,&pEnd,16);
  li3 = strtol (pEnd,&pEnd,2);
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  return 0;
}