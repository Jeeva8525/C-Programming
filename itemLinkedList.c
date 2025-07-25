/* 2) Create a data structure to store a list of items, where each
item has the following information:
Item name
Item ID
Quantity
Unit price
Total cost
Write a C program to store the any given number of Items and
perform the following operations on it.
a) Compute the total cost and display it
b) Sort the Items based on the total cost. */
#include <stdio.h>
#include <stdlib.h>
typedef struct itemList
{
    char itemName[50];
    int itemId;
    int quantity;
    int unitPrice;
    int totalCost;
    struct itemList *next;
} items;
void push_back(items **start)
{
    items *ptr = (items *)malloc(sizeof(items));
    printf("Enter Item name: ");
    scanf("%s", ptr->itemName);
    printf("Enter Item Id: ");
    scanf("%d", &ptr->itemId); 
    printf("Enter quantity: ");
    scanf("%d", &ptr->quantity);
    printf("Enter price of a single item: ");
    scanf("%d", &ptr->unitPrice);
    ptr->totalCost = (ptr->quantity) * (ptr->unitPrice);
    ptr->next = NULL;
    if (*start == NULL)
    {
        *start = ptr;
        return;
    }
    items *mass;
    for (mass = (*start); mass->next != NULL; mass = mass->next);
    mass->next = ptr;
}
void display(items *start)
{
    if (start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    for (items *mass = start; mass != NULL; mass = mass->next)
    {
        printf("Item name : %s\n", mass->itemName);
        printf("Item Id : %d\n", mass->itemId);
        printf("Quantity : %d\n", mass->quantity);
        printf("Price : %d\n", mass->unitPrice);
        printf("Total cost : %d\n\n", mass->totalCost);
    }
}
void sort(items **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        return;
    }
    items *a, *b;
    items** ptr;
    int swapped;
    do
    {
        ptr = start;
        swapped=0;
        while((*ptr)->next!=NULL)
        {
            a = *ptr;
            b = a->next;

            if(a->totalCost>b->totalCost)
            {
                a->next=b->next;
                b->next=a;
                *ptr = b;
                swapped=1;
            }
            ptr = &((*ptr)->next);
        }
    }while(swapped);
}
int main()
{
    items *head = NULL;
    char ch;
    do
    {
        printf("Do you want to add an item(y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
            push_back(&head);
    } while (ch == 'y' || ch == 'Y');
    display(head);
    sort(&head);
    printf("After sorting\n");
    display(head);
    return 0;
}