#include <stdio.h>
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int ogStart=start; 
    start += 1;
    int temp;
    while (start <= end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }
    temp = arr[end];
    arr[end] = arr[ogStart];
    arr[ogStart] = temp;

    return end;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int loc = partition(arr, start, end);
        quickSort(arr, start, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}
void main()
{
    int arr[] = {4, 7, 13, 2, 6, 8, 94, 21};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);
    printf("The array elements are\n");
    for (int x = 0; x < size; x++)
    {
        printf("%d ", arr[x]);
    }
}