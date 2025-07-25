//Tower of hanoi
#include <stdio.h>
#include <math.h>
void tower(int u,char s,char d,char t)
{
        if(u==1)
        {
                printf("move disc %d from %c to %c\n",u,s,d);
                return;
        }
        tower(u-1,s,t,d);
        printf("move disc %d from %c to %c\n",u,s,d);
        tower(u-1,t,d,s);
}
void main()
{
        int n;
        printf("Enter the number of discs: ");
        scanf("%d",&n);
        tower(n,'A','B','C');
        int steps = pow(2,n) - 1;
        printf("Total no of steps: %d",steps);
}