/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void inputRandomArray(int* array, int size){
    for(int i=0; i<size; i++){
        *(array+i)=rand()%100;
    }
}
void printArray(int* array, int size)
{
    for(int i=0; i<size; i++){
        printf("%3d\t", *(array+i));
        if((i+1)%10==0)printf("\n");
    }
}
int main()
{
    int number[SIZE];
    srand(time(NULL));
    inputRandomArray(number, SIZE);
    printArray(number, SIZE);
    return 0;
}