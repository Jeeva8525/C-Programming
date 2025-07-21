#include <stdio.h>
void binarySearch(int arr[],int n,int val){
    int start=0,end=9;
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(val==arr[mid]){
            printf("Index is %d\n",mid);
            printf("Position is %d",mid+1);
            return;
        }
        else if(val<arr[mid]){
            end=mid-1;
            continue;
        }
        else{
            start=mid+1;
            continue;
        }
    }
    printf("No such element is found");
}
void main(){
    int arr[]={3,4,6,8,9,11,29,32,52,91};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("The array elements are\n");
    for(int x=0;x<size;x++)
        printf("%d ",arr[x]);
    printf("\n");
    int val;
    printf("Enter the value to search: ");
    scanf("%d",&val);

    binarySearch(arr,size,val);
    
    
}