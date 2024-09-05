/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number[10];
    srand(time(NULL));
    for(int i=0; i<10; i++){
        number[i]=rand();
    }
    for(int i=0; i<10; i++){
        printf("number=%d\n", number[i]);
    }
    return 0;
}