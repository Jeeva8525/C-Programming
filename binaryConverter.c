// Converts a number to its binary format
#include <stdio.h>
void main()
{
        int n;
        printf("Enter the number: ");
        scanf("%d",&n);
        int rev=0;
        for(int x=n;x>0;x/=2)
        {
                rev=rev*10+x%2;
        }
        int rev1=0;
        for(int x=rev;x>0;x/=10)
        {
                rev1=rev1*10+x%10;
        }
        printf("The binary equivalent is %07d",rev1);
}