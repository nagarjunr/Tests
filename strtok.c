/* strchr example */
#include <stdio.h>
#include <string.h>

// int main ()
// {
//   char str[1000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:456\0";
//   char result[100] = {0};

//   char str1[1000] = {'0'};
//   memset(str1,0,1000);
//   str1[1000] = '\0';

//   char remaining[1000] = {'0'};
//   memset(remaining,0,1000);
//   remaining[1000] = '\0';

//   int str_len = 0;
//   int pch_len = 0;
//   int Newline_count = 0;

//   int x = 0;
//   int y = 0;

//   char * pch;
//   //printf ("Looking for the '\\n' character in \"%s\"...\n",str);
//   pch=strchr(str,'\n');
//   while (pch!=NULL)
//   {
//     printf ("\n\npch : %s\n\n",pch);
//     pch_len = strlen(pch);
//     str_len = strlen(str);

//     x = strlen(str) - strlen(pch) + 1; //New length of Complete Ack
//     //printf("X is : %d\n",x);

//     strncat(str1,&str[y],x-y);

//     y = x; //old length of Complete Ack

//     printf("Complete Ack : %s\n",str1);
//     //printf ("String length of pch : %d\n",strlen(pch));
//     //printf ("String length of str : %d\n\n",strlen(str));
//     //printf ("s found at : %d\n",strlen(str)-strlen(pch)+1);
//     //int x = strlen(str)-strlen(pch);
//     //printf("X is : %d\n",x);
//     //strncpy(result,str,x);
//     //printf ("String W/O pch : %s\n",result);
//     //printf ("s found at : %d\n\n",pch-str+1);


//     Newline_count = strcspn (pch,"\n");

//     printf("Remaining no of newlines : %d\n",Newline_count);

//     pch=strchr(pch+2,'\n');

//     // if(pch == NULL)
//     // {
//     //   strncat(remaining,&str[y],x-y);
//     //   printf("Remaining : %s\n",remaining);
//     // }

//     //str1[1000] = {'0'};
//     memset(str1,0,1000);
//     str1[1000] = '\0';
//   }

//   return 0;
// }

int main ()
{
  char str[1000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:456\0";
  char FIFO_Que[10][128] = {0};

  int i = 0;

  char * pch;
  printf ("Splitting string into tokens:\n",str);
  pch = strtok (str,"\n");
  //printf ("pch : ---%s---\n",pch);
  while (pch != NULL)
  {
    printf ("pch : ---%s---\n",pch);
    //printf("str : ---%s---\n\n",str );
    strcpy(FIFO_Que[i],pch);
    pch = strtok (NULL, "\n");
    i++;
  }

  for(i = 0; i<10;i++)
  {
    printf("Que Values : -----%s-------\n\n",FIFO_Que[i]);
  }
  return 0;
}