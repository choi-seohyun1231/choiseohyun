/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
   int ch;
   char message[100];
   int i=0;
   while((ch=getchar())!='\n'){
       message[i++]=ch;
   }
   message[i]='\0';
   printf("%s", message);
   return 0;
}
