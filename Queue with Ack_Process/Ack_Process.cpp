/* strchr example */
#include <stdio.h>
#include <string.h>
#include "Queue.h"

int main ()
{
  char G_temp_Ack_Buffer[5000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:45\0";

  char Splitted_Ack[1000] = {'0'};
  memset(Splitted_Ack,0,1000);
  Splitted_Ack[1000] = '\0';

  int G_temp_Ack_length = 0;
  int Forward_Read_Ptr_len = 0;
  int Reverse_Read_Ptr_len = 0;

  int Splitted_Ack_Length = 0;
  int Splitted_Ack_Length_Old = 0;

  char *Forward_Read_Ptr;
  char *Reverse_Read_Ptr;

  Forward_Read_Ptr = strchr(G_temp_Ack_Buffer,'\n');
  while (Forward_Read_Ptr != NULL)
  {
    Forward_Read_Ptr_len = strlen(Forward_Read_Ptr);
    G_temp_Ack_length = strlen(G_temp_Ack_Buffer);

    Splitted_Ack_Length = (strlen(G_temp_Ack_Buffer) - strlen(Forward_Read_Ptr) + 1); //New length of Complete Ack
    //printf("Splitted_Ack_Length is : %d\n",Splitted_Ack_Length);

    memset(Splitted_Ack,0,1000);
    Splitted_Ack[1000] = '\0';

    strncat(Splitted_Ack,&G_temp_Ack_Buffer[Splitted_Ack_Length_Old],Splitted_Ack_Length-Splitted_Ack_Length_Old);
    Splitted_Ack_Length_Old = Splitted_Ack_Length; //old length of Complete Ack
    Splitted_Ack[strlen(Splitted_Ack)] = '\0';

    //printf("Complete Ack : -----%s------\n",Splitted_Ack);
    Enqueue(Splitted_Ack);

    Forward_Read_Ptr=strchr(Forward_Read_Ptr+2,'\n');
  }

  Reverse_Read_Ptr=strrchr(G_temp_Ack_Buffer,'\n');

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

  Display_Queue();
 
  return 0;
}