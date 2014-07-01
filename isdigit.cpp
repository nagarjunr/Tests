#include <stdio.h>
//#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
  char str[500] = "Error:Line Number is not Last Line Number+1, Last Line: 29\n Resend: 30\n ok";
  int i = 0;
  int j = 0;
  char Errorline_No[10] = {0};
  char Final[10] = {0};
  int Break_ON = 0;
  signed int x = 0;

  for (i = strlen(str); i > 0; i--)
  {
    if (isdigit(str[i]))
    {
      Errorline_No[j] = str[i];
      j++;
      Break_ON = 1;
    }
    else
    {
      if (Break_ON == 1)
      {
        break;
      }
    }
  }
  //Errorline_No[j] = str[i];
  i = 0;
  j = 0;

  for (i = strlen(Errorline_No)-1 ; i >= 0 ; i--)
  {
    Final[j] = Errorline_No[i];
    j++;
  }
  int ci = 0;
  ci = atoi(Final);
  x = 5 - 10;
  int y = 10;
  int z = 0;
  z = y+x;
  printf("Line Number Parsed : %s\n",Errorline_No);
  printf("Line Number Reversed : %s\n",Final);
  printf("Integer : %d\n",ci);
  printf("Value of X is %d\n",x);
  printf("Value of Z is %d\n",z);
  return 0;
}