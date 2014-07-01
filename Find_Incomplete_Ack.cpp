#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char Find_Incomplete_Ack(char *G_temp_Ack_Buffer)
{
  char Temp_Ack[5000] = {0};
  memset (Temp_Ack,0,5000);
  Temp_Ack[5000] = '\0';

  char Send_Ack[100] = {0};
  memset (Send_Ack,0,100);
  Send_Ack[100] = '\0';

  char *Reverse_Read_Ptr;
  int Reverse_Read_Ptr_len = 0;

  strcpy(Temp_Ack,G_temp_Ack_Buffer);
  Temp_Ack[strlen(Temp_Ack)] = '\0';

  Reverse_Read_Ptr = strrchr(Temp_Ack,'\n');

  if (strlen(Reverse_Read_Ptr) == 1)
  {
    //printf("\nNo Uncompleted Ack\n\n");
    memset (Send_Ack,0,100);
    Send_Ack[100] = '\0';
    //return Send_Ack[100];
  }
  else
  {
    //printf("Uncompleted Ack is : ---%s----\n",Reverse_Read_Ptr+1);
    strcpy(Send_Ack,(Reverse_Read_Ptr+1));
    Send_Ack[strlen(Send_Ack)] = '\0';
    //return Send_Ack[100];
  }
  return *Send_Ack;
}

int main()
{
  char Ack[] = "OK:123\nDONE:456\nERR:";

  Find_Incomplete_Ack(Ack);

  if (Result == '\0')
  {
    //Initialize G_Ack_Buffer
  }
  else
  {
    printf("Result : %s\n",Result);
    //printf("Uncompleted Ack is : ---%s----\n",Reverse_Read_Ptr+1);
    //Initialize G_Ack_Buffer
    //Copy this to G_Ack_Buffer;
  }
  return 0;
}