//Implementation of insertional Sort in Doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *prev;
    struct linkedList *next;
} list;

void insertSorted(list **start, int val)
{
    list *ptr = (list*)malloc(sizeof(list));
    ptr->data = val;
    ptr->prev = ptr->next = NULL;

    if (NULL == *start) 
    {
        *start = ptr;
        return;
    }

    list *p = *start;
    if (val <= p->data)
    {
        ptr->next = p;
        p->prev = ptr;
        *start = ptr;
        return;
    }

    while (p->next != NULL && val > p->next->data)
    {
        p = p->next;
    }

    ptr->next = p->next;
    if (p->next != NULL)
        p->next->prev = ptr;

    p->next = ptr;
    ptr->prev = p;
}

void display(list **start)
{
    if (NULL == *start)
    {
        printf("The list is empty\n");
        return;
    }
    printf("The elements of the linked list are\n");
    for (list *p = *start; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

int main()
{
    list *head = NULL;
    int ch = 1, val;

    printf("1 : add an element\n2 : display\n0 : exit\n");
    while (ch != 0)
    {
        printf("enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exited\n");
            break;
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            insertSorted(&head, val);
            break;
        case 2:
            display(&head);
            break;
        default:
            printf("Invalid choice -------\n");
        }
    }
    return 0;
}
