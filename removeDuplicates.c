//To make every duplicates of an number array replaced by its successor
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements\n");
    for(int x=0;x<n;x++)
        scanf("%d",&arr[x]);

    printf("\n\n");

    for(int x=0;x<n-1;x++)
    {
        for(int y=x+1;y<n;y++)
        {
            if(arr[x]==arr[y])
            {
                arr[y]=y!=n-1?arr[y+1]:arr[y];
            }
        }
    }

    for(int x=0;x<n;x++)
    {
        printf("%d\n",arr[x]);

    }

}