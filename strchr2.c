/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[1000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:45\0";
  char result[100] = {0};

  int Ack_Q_Size = 10;
  int ind;

  char Ack_Processing_Q[10][1000] = {0};
  // for (ind = 0; ind < Ack_Q_Size; ind++)
  // {
  //   memset(Ack_Processing_Q[ind],0,1000);
  //   Ack_Processing_Q[ind][1000] = '\0';
  // }

  int Ack_Processing_Index = 0;

  char str1[1000] = {'0'};
  memset(str1,0,1000);
  str1[1000] = '\0';

  int str_len = 0;
  int Forward_Read_Ptr_len = 0;
  int Reverse_Read_Ptr_len = 0;

  int x = 0;
  int y = 0;

  char *Forward_Read_Ptr;
  char *Reverse_Read_Ptr;

  Forward_Read_Ptr=strchr(str,'\n');
  while (Forward_Read_Ptr!=NULL)
  {
    Forward_Read_Ptr_len = strlen(Forward_Read_Ptr);
    str_len = strlen(str);

    x = strlen(str) - strlen(Forward_Read_Ptr) + 1; //New length of Complete Ack
    //printf("X is : %d\n",x);

    memset(str1,0,1000);
    str1[1000] = '\0';

    strncat(str1,&str[y],x-y);
    y = x; //old length of Complete Ack
    str1[strlen(str1)] = '\0';

    //printf("Complete Ack : -----%s------\n",str1);
    strcpy(Ack_Processing_Q[Ack_Processing_Index],str1);
    Ack_Processing_Index += 1;

    // if (Ack_Processing_Index > Ack_Q_Size)
    // {
    //   Ack_Processing_Index = 0;
    // }

    Forward_Read_Ptr=strchr(Forward_Read_Ptr+2,'\n');
  }

  Reverse_Read_Ptr=strrchr(str,'\n');

  if (strlen(Reverse_Read_Ptr) == 1)
  {
    printf("\nNo Uncompleted Ack\n\n");
    //Initialize G_Ack_Buffer
  }
  else
  {
    printf("Uncompleted Ack is : ---%s----\n",Reverse_Read_Ptr+1);
    //Initialize G_Ack_Buffer
    //Copy this to G_Ack_Buffer;
  }

  for (ind = 0; ind < Ack_Q_Size; ind++)
  {
    printf("Value in Q : ---%s---\n",Ack_Processing_Q[ind]);
  }
 
  return 0;
}