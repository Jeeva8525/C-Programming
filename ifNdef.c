//ifndef
#include <stdio.h>
#define N 20
#ifndef N
#define A "N is Not deined"
#else
#define A "Defined"
#endif
void main()
{
        printf("%s\n\n",A);
}