/* 
    1 
    2     3
    4     5     6
    7     8     9    10
*/

#include <stdio.h>
void printNum(int n)
{
    for(int x=1;x<=n;x++)
    {
        for(int y=0;y<x;y++)
        {
            printf("%5d ",(x*(x-1))/2+y+1);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printNum(n);
}