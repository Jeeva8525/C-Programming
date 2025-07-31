#include <stdio.h>
void main()
{
    int n;
    float fly;
    char down;
proceed:
    printf("1 for float to int \n2 for float to char\n3 for char to int\n4 for char to float\nEnter: ");
    scanf("%d",&n);
    switch(n)

    {
    case 0:
        return ;
    case 1:
        printf("Enter the float value: ");
        scanf("%f",&fly);
        printf("The converted integer is %d\n",(int)fly);
        break;
    case 2:
        printf("Enter the float value: ");
        scanf("%f",&fly);
        printf("The converted character is %c\n",(char)fly);
        break;
    case 3:
        printf("Enter the character: ");
        scanf(" %c",&down);
        printf("The converted character is %d\n",(int)down);
        break;
    case 4:
        printf("Enter the character: ");
        scanf(" %c",&down);
        printf("The converted character is %f\n",(float)down);
        break;
    default:
        break;

    }
    goto proceed;
}