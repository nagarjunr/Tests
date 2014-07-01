#include <stdio.h>
//#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char str[500] = "ERR:LNM:RS:11\n";
  int i = 0;
  int j = 0;
  int k = 0;
  int n = 0;
  char Errorline_No[10] = {0};
  char tempstr[20] = {0};
  tempstr[20] = '\0';
  char resendstr[4] = "RS:";


  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == 'R')
    { 
      printf("Value of str[i] : %c\n",str[i]);
      n = i;
      while(j < 3)
      { 
        tempstr[j] = str[n];
        printf("Value of tempstr[j] : %c\n",tempstr[j]);
        j++; 
        n++;
      }
      if (strcmp(tempstr,resendstr) == 0)
      {
        printf("Here\n");
        while (isdigit(str[n]))
        {
          Errorline_No[k] = str[n];
          k++;
          n++;
        }
        Errorline_No[k] = '\0';
        break;
      }
      else
      {
        j = 0;
        n = 0;
      }
    }
    else
    {
      continue;
    }
  }

  int ci = 0;
  ci = atoi(Errorline_No);

  printf("Line Number Parsed : %s\n",Errorline_No);
  printf("Integer : %d\n",ci);

  return 0;
}