/*

int getchar();  //ECHO when carriage return buffered input
int putchar(int ch);//Print a char at current cursor location

int getch()  //Immedate return once key pressed no buffered line input  + No ECHO
int getche(); //With ECHO
char* gets(char* ptr); return once carriage return mean enter pressed enter replaced by \0
void puts(char* ptr)
int scanf() //insert a string to string var as soon as whitespace encountered

char arr[80];

scanf("%s",arr);
This is test string

then only This hold by arr
to read all

char arr1[80];
char arr2[80];
char arr3[80];

scanf("%s%s%s",arr1,arr2,arr3);
*/

#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
    //Line buffered input
    //Wait for carriage return ENTER
    //char ch1 = getchar();//Satveer Singh
    //putchar(ch1);//S
    //No Line buffered input
    //Return Immedately
    //No ECHO
    //char ch = getch();
    //putchar(ch);

    //No Line buffered input
    //Return Immedately
    //ECHO
    //char ch2 = getche();
    //putchar(ch);

    //char arr[20];
    //gets(arr);//Keep reading in line buffer till ENTER not pressed
    //puts(arr);
    //scanf("%20s",arr);

    int x;
    char a[10];
    char b[10];

    //123Satveer Singh also ok
    //123 Satveer Singh also ok

    puts("Enter name:-\n");
    scanf("%d%s%s",&x,a,b);
    //scanset
    scanf("%d%[a-z]%s",&x,a,b);
    scanf("%d%[abcd]%s",&x,a,b);
    printf("%d %s %s",x,a,b);



    return 0;
}
