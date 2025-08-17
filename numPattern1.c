/* 
1 
2 2
3 3 3
4 4 4 4
*/
#include <stdio.h>
void printNum(int n)
{
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=x;y++)
        {
            printf("%d ",x);
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