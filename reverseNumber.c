//To reverse a number using recursion
#include <stdio.h>
void rev(int n)
{
        if(n>0)
        {
                printf("%d",n%10);
                rev(n/10);
        }
}
void main()
{
        int num;
        printf("Enter the number: ");
        scanf("%d",&num);
        rev(num);
}