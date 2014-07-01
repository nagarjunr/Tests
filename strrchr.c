/* strrchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[1000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:456";
  char * Reverse_Read;
  Reverse_Read=strrchr(str,'\n');
  if (strlen(Reverse_Read) == 1)
  {
  	printf("No Uncompleted Ack\n");
  }
  else
  {
  	printf("Uncompleted Ack is : ---%s----\n",Reverse_Read+1);
  }
  return 0;
}