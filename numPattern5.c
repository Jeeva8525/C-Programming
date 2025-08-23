/* 
4 4 4 4 4 4 4 
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4 
*/
#include <stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
void printNum(int n)
{
    for(int x=n;x>0;x--)
    {
        for(int y=n;y>0;y--)
        {
            printf("%d ",max(x,y));
        }
        for(int y=2;y<=n;y++)
        {
            printf("%d ",max(x,y));
        }
        printf("\n");
    }
    for(int x=2;x<=n;x++)
    {
        for(int y=n;y>0;y--)
        {
            printf("%d ",max(x,y));
        }
        for(int y=2;y<=n;y++)
        {
            printf("%d ",max(x,y));
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