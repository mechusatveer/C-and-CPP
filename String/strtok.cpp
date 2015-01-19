/* strtok example */
#include <stdio.h>
#include <string.h>
 
int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (str, " ,.-");
  }
  return 0;
}
