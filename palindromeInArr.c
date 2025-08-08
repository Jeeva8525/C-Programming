//14. check whether the digits in a row are palindrome ( This code is harcoded for 2 rows and 5 columns of numbers )
#include <stdio.h>
#define R 2
#define C 5 //length of a single number (single row)
void main()
{
    int arr[R][C],x,y,p;
    for(x=0;x<R;x++)
    {
        printf("Enter the elements for row-%d\n",x+1);
        for(y=0;y<C;y++)
        {
            scanf("%d",&arr[x][y]);
        }
    }
    printf("\n\n");



    for(x=0;x<R;x++)
    {
        p=0;
        for(y=0;y<C/2;y++)
        {
            if(arr[x][y]!=arr[x][C-y-1])
                p=1;
                break;
        }
        if(!p)
            printf("Row-%d is a Palindrome\n",x+1);
        else
            printf("Row-%d is not a Palindrome\n",x+1);
    }
}