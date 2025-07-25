//to find the fibonacci series using recursion
#include <stdio.h>
int fib(int u)
{
        if(u<=1)
                return u;
        else
                return fib(u-1)+fib(u-2);
}
void main()
{
        int n;
        printf("Enter the number: ");
        scanf("%d",&n);
        for(int x=0;x<n;x++)
                printf("%d\t",fib(x));
}