//To find the factorial of the number using recursion
#include <stdio.h>
int fact(int n)
{
        if(n<=1)
                return 1;
        else
                return n*fact(n-1);
}
void main()
{
        int n;
        printf("Enter the number: ");
        scanf("%d",&n);
        printf("The factorial of %d is %d\n",n,fact(n));
}