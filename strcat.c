#include <stdio.h>
#include <string.h>

int main ()
{
   char src[50], dest[50], src1[50],srcn[50], destn[50], src1n[50];

   strcpy(src,  "This is source\0ljljljlj");
   strcpy(dest, "This is destination");

   strcat(dest, src);
   strcpy(src1,  "This is source\0adasas");
   strcat(dest,src1);

   printf("Strcat string : |--------%s----------|\n\n\n", dest);

   strcpy(srcn,  "This is source\0ljljljlj");
   strcpy(destn, "This is destination");

   strncat(destn, srcn,strlen(srcn));
   strcpy(src1n,  "This is source\0adasas");
   strncat(destn,src1n,strlen(src1n));

   printf("Strncat string : |--------%s----------|\n\n\n", destn);
   
   return(0);
}