/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
typedef struct point{
    int x;
    int y;
}POINT;
typedef struct{
    POINT center;
    double radius;
}CIRCLE;
typedef struct rect{
    POINT lb;
    POINT rt;
}RECT;
double dist(POINT p1, struct point p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y), 2));
}