/* strchr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char G_temp_Ack_Buffer[5000] = "OK:123\nDONE:123\nERR:LNM:RS:890\nOK:456\nDONE:456\n";
  int After_Newline_length = 0;
  int G_temp_Ack_length = 0;
  char *After_Newline;
  // memset(After_Newline,0,1000);
  // After_Newline[1000] = '\0';

  char G_Ack_Buffer[10000] = {'0'};
  memset(G_Ack_Buffer,0,10000);
  G_Ack_Buffer[10000] = '\0';
 
  G_temp_Ack_length = strlen(G_temp_Ack_Buffer);
  G_temp_Ack_Buffer[G_temp_Ack_length] = '\0';

  After_Newline = strchr(G_temp_Ack_Buffer, '\n');
  printf("After_Newline : --------%s----------\n",After_Newline);
  After_Newline_length = strlen(After_Newline);
  After_Newline[After_Newline_length] = '\0';
  printf("After_Newline_length : %d\n", After_Newline_length);

  if (After_Newline_length >= 1) //It means we have nothing after new line
  {
    if(After_Newline_length == 1)
    {
      strncat(G_Ack_Buffer,G_temp_Ack_Buffer,strlen(G_temp_Ack_Buffer));
    } 

    if(After_Newline_length > 1) //We have something after newline
    { 
      char Till_Newline[1000] = {0};
      memset(Till_Newline,0,1000);
      Till_Newline[1000] = '\0';

      strncat(Till_Newline,G_temp_Ack_Buffer,(G_temp_Ack_length - After_Newline_length-1));
      strncat(G_Ack_Buffer,Till_Newline,strlen(Till_Newline)); 
    }

    printf("G_Ack_Buffer : ------%s------\n",G_Ack_Buffer);
    
    //
    //
    //Do normal operation
    //
    //

    //G_Ack_Buffer[10000] = {'0'};
    memset(G_Ack_Buffer,0,10000);
    G_Ack_Buffer[10000] = '\0';


    if(After_Newline_length > 1) //We have something after newline
    {
      strncat(G_Ack_Buffer,After_Newline+1,After_Newline_length-1);
      printf("Next G_Ack_Buffer : ------%s------\n",G_Ack_Buffer); 
    }

    //G_temp_Ack_Buffer[5000] = {0};
    memset(G_temp_Ack_Buffer,0,5000);
    G_temp_Ack_Buffer[5000] = '\0';
    
    After_Newline = NULL;

    //printf("After free : //////%s-----\n",After_Newline);
  }
  else
  {
    strncat(G_Ack_Buffer,G_temp_Ack_Buffer,strlen(G_temp_Ack_Buffer));
    //G_temp_Ack_Buffer[5000] = {0};
    memset(G_temp_Ack_Buffer,0,5000);
    G_temp_Ack_Buffer[5000] = '\0';
  }

  return 0;
}