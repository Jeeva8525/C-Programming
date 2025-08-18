/* 
0       
1 0     
0 1 0   
1 0 1 0 
*/

#include <stdio.h>
void printNum(int n)
{
    int d=0;
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=x;y++)
        {
            printf("%d ",(x+y)%2);
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