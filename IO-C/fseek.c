#include<stdio.h>

int main()
{
    FILE *fp;
    char c[1024];
    fp = fopen("test.txt", "r");  // "Kernighan and Ritchie" 
    c[0] = getc(fp);              // c[0] = K
    fseek(fp, 0, SEEK_END);       // file position moved to the end
    fseek(fp, -7L, SEEK_CUR);     // 7th from the end, with is 'R' of "Ritchie"
    fgets(c, 6, fp);              // read 6-1 characters from 'R'
    puts(c);                      // "Ritch"
    return 0;
}
