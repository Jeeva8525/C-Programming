/* 
    * * * * 
    *     *
    *     *
    * * * *
*/
#include <stdio.h>
void printStar(int n)
{
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            if(x==0 || x==n-1 || y==0 || y==n-1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
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