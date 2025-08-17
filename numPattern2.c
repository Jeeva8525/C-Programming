/* 
1 2 3 4 
1 2 3
1 2
1
*/
#include <stdio.h>
void printNum(int n)
{
    for(int x=n;x>0;x--)
    {
        for(int y=1;y<=x;y++)
        {
            printf("%d ",y);
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