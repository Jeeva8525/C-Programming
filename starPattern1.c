/*
      * 
    * * *
  * * * * *
* * * * * * *
  * * * * *
    * * *
      * 
*/
#include <stdio.h>
void printStar(int n)
{
    for(int x=1;x<=n;x++)
    {
        for(int y=0;y<n-x;y++)
        {
            printf("  ");
        }
        for(int y=0;y<2*x-1;y++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(int x=n-1;x>0;x--)
    {
        for(int y=0;y<n-x;y++)
        {
            printf("  ");
        }
        for(int y=0;y<2*x-1;y++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printStar(n);
}