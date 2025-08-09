// Implementing circular queue using Linked Lists
#include <stdio.h>
#include <stdlib.h>
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} CLL;
void insMid(CLL **start)
{
    int val, pos;
    printf("Enter the element: ");
    scanf("%d", &val);
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    CLL *ptr = (CLL *)malloc(sizeof(CLL));
    ptr->data = val;
    if (*start == NULL)
    {
        if (pos == 1)
        {
            ptr->next = ptr;
            *start = ptr;
        }
        else
        {
            printf("Invalid position\n");
        }
        return;
    }
    CLL *p;
    if (pos == 1)
    {
        for (p = *start; p->next != *start; p = p->next)
            ;
        p->next = ptr;
        ptr->next = *start;
        *start = ptr;
        return;
    }
    int x = 1;
    for (p = *start; p != *start || x == 1; p = p->next)
    {
        if (x + 1 == pos)
        {
            ptr->next = p->next;
            p->next = ptr;
            return;
        }
        x++;
    }
    printf("Invalid position\n");
}
void delMid(CLL **start)
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1) // negative index
    {
        printf("---------Invalid position-------\n");
        return;
    }
    if (*start == NULL) // no element case
    {

        return;
    }
    if ((*start)->next == *start) // one element case
    {
        if (pos == 1)
        {
            free(*start);
            *start = NULL;
        }
        else
        {
            printf("Invalid index\n");
        }
        return;
    }
    if (pos == 1)
    {
        CLL *p;
        for (p = (*start)->next; p->next != *start; p = p->next)
            ;
        p->next = (*start)->next;
        free(*start);
        *start = p->next;
        return;
    }
    CLL *p;
    int x = 1;
    for (p = *start; p->next != *start || x == 1; p = p->next)
    {
        if (x + 1 == pos)
        {
            CLL *temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        x++;
    }
    printf("---------Invalid position-------\n");
}
void display(CLL *start)
{
    if (start == NULL)
    {
        return;
    }
    printf("The elements in the circular linked list are \n");
    printf("%d ", start->data);
    for (CLL *p = start->next; p != start; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}
void main()
{
    CLL *head = NULL;
    int ch;
    printf("1 : add an element at specific index\n2 : delete an element at specific index\n3 : display the current elements in the list\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            ch = 0;
            break;
        case 1:
            insMid(&head);
            break;
        case 2:
            delMid(&head);
            break;
        case 3:
            display(head);
            break;
        default:
            printf("Invalid choice\n");
        }
        display(head);
    } while (ch != 0);
    display(head);
}