/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char result[100] = {0};

  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=strchr(str,'s');
  while (pch!=NULL)
  {
    printf ("pch : %s\n\n",pch);
    printf ("String length of pch : %d\n",strlen(pch));
    printf ("String length of str : %d\n\n",strlen(str));
    printf ("s found at : %d\n",strlen(str)-strlen(pch)+1);
    int x = strlen(str)-strlen(pch);
    printf("X is : %d\n",x);
    strncpy(result,str,x);
    printf ("String W/O pch : %s\n",result);
    printf ("s found at : %d\n\n",pch-str+1);
    pch=strchr(pch+1,'s');
  }
  return 0;
}