/* strstr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char a;
  char str[] ="ERR:NCS:RS:100";
  char * pch;
  pch = strstr(str, "RS:");
  if (pch != NULL)
  {
    printf("RS: is found\n");
  }
  //pch = strstr (str,"simple");
  a = strstr(str,"simple");
  printf("a : %p\n",&a);
  printf("pch value : %c\n",*pch); //printing value
  printf("pch address : %p\n",pch); //printing address
  strncpy (pch,"sample",6);
  puts (str);
  return 0;
}