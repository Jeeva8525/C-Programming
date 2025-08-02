#include <stdio.h>
#include <stdlib.h>
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} CLL;
void insBeg(CLL **start)
{
    int val;
    printf("Enter the element: ");
    scanf("%d",&val);
    CLL *ptr = (CLL *)malloc(sizeof(CLL));
    ptr->data = val;

    if (*start == NULL)
    {
        *start = ptr;
        ptr->next = ptr;
        return;
    }

    CLL *p = *start;
    while(p->next!=*start)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = *start;
    *start = ptr;
    
}
void display(CLL *start)
{
    if (start == NULL)
    {
        return;
    }
    printf("The elements in the circular linked list are \n");
    printf("%d ",start->data);
    for (CLL *p = start->next; p!= start; p = p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}
void main()
{
    CLL *head = NULL;
    char ch;
    do
    {
        printf("Do you want to add an item(y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            insBeg(&head);
            display(head);
        }
    } while (ch == 'y' || ch == 'Y');
    display(head);

}