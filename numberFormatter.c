//to print odd and even numbers using formatted texts
#include <stdio.h>
int evenodd(int n)
{
        if(n%2==0)
                printf("%20d\n",n);
        else
                printf("%10d\n",n);
}

void main()
{
        int n;
        printf("Enter the number: ");
        scanf("%d",&n);
        printf("\tOdd  \tEven\n");
        for(int x=1;x<=n;x++)
        {
                evenodd(x);
        }
}