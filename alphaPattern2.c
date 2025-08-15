/* 
    A
  A B A
A B C B A
*/
#include <stdio.h>
void printAlpha(int n)
{
    for(int x=1;x<=n;x++)
    {
        for(int y=0;y<n-x;y++)
        {
            printf("  ");
        }
        for(int y=0;y<x;y++)
        {
            printf("%c ",y+65);
        }
        for(int y=x-1;y>0;y--)
        {
            printf("%c ",y+65-1);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printAlpha(n);
}