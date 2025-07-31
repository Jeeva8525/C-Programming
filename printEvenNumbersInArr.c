//to print all even number of an array
#include <stdio.h>
void printeven(int x[],int y)
{
        printf("The even nos. are\t");
        for(int z=0;z<y;z++)
        {
                if(x[z]%2==0)
                        printf("%d\t",x[z]);
        }
}


void main()
{
        int n;
        printf("Enter the number of elements: ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the elements\n");
        for(int x=0;x<n;x++)
                scanf("%d",&arr[x]);

        printeven(arr,n);
}