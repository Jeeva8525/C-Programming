#include <stdio.h>
#include <stdlib.h>
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} CLL;
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
        for (p = (*start)->next; p->next != *start; p = p->next);
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
        printf("-------------There are no elements in the circular list----------\n");
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
    CLL *head = (CLL *)malloc(sizeof(CLL));
    CLL *temp;
    head->data = 1;
    temp = head;
    char ch;

    for (int x = 2; x < 5; x++)
    {
        CLL *ptr = (CLL *)malloc(sizeof(CLL));
        temp->next = ptr;
        ptr->data = x;
        ptr->next = head;
        temp = ptr;
    }
    display(head);
    do
    {
        printf("Do you want to delete an item(y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            delMid(&head);
            display(head);
        }
    } while (ch == 'y' || ch == 'Y');
    display(head);
}