/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char buffer[4][96]; 
  buffer[0][96]= "This is a sample string";
  // char * pch;
  // printf ("Looking for the 's' character in \"%s\"...\n",str);
  // pch=strchr(str,'s');
  // while (pch!=NULL)
  // {
  //   printf ("pch : %s\n",pch);
  //   printf ("String length of pch : %d\n",strlen(pch));
  //   printf ("String length of str : %d\n",strlen(str));
  //   printf ("s found at : %d\n",strlen(str)-strlen(pch)+1);
  //   printf ("s found at : %d\n",pch-str+1);
  //   pch=strchr(pch+1,'s');
    printf("Buffer : %s\n",buffer[0][96]); 
  // }
  return 0;
}