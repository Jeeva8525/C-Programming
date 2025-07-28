//Guess the number
#include <stdio.h>
void guess(int a)
{

        int g;
        printf("Enter the guess : ");
        scanf("%d",&g);
        if(g==a)
                printf("You won\n");
        else if(g==-1)
                return;
        else
        {
                printf("Guess again\n");
                guess(a);
        }
}
void main()
{
        int n;
proceed:
        printf("Enter the maximum range(from 50 to 100): ");
        scanf("%d",&n);
        if(n>100 || n<50)
        {
                printf("Enter a number from 50 to 100");
                goto proceed;
        }
        //n-=1;
        printf("your aim is to find the correct number which is in between(0 to %d)\n",n);
        printf("Enter -1 to exit the game\n");
        n+=n%2?-26:-23;
        guess(n);
}