#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string"

int main()
{
  char Processed_Ack[128] = "OK:123\n";
  int Sent_Count = 120;

  if(*Processed_Ack != '\0')
  {
    if(strstr(Processed_Ack,"OK:") != NULL)
    {
        int Ack_Count;
        char *OK_Number;

        OK_Number = strchr(Processed_Ack,':');

        Ack_Count = (int)(strtol(&Processed_Ack[strlen(Processed_Ack) - strlen(OK_Number) + 1], NULL, 10));

        // printf("strlen(Processed_Ack) : %zu\n",strlen(Processed_Ack) );
        // printf("strlen(OK_Ptr) : %zu\n",strlen(OK_Number) );

        // printf("strlen(Processed_Ack) - strlen(OK_Ptr) + 1 : %zu\n",strlen(Processed_Ack) - strlen(OK_Number) + 1 );

        if (Ack_Count - Sent_Count > 0)
        {
          printf("Difference : %d\n",(Ack_Count - Sent_Count));
        }

        
    }
  }

  return 0;
}