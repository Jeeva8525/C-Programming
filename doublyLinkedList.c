#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *next;
    struct doublyLinkedList *prev;
} DLL;
DLL *head = NULL;
void insertBeg(DLL **start)
{
    int val;
    printf("Enter the element: ");
    scanf("%d", &val);
    DLL *ptr = (DLL *)malloc(sizeof(DLL));
    ptr->data = val;

    ptr->prev = NULL;
    if (*start == NULL)
    {
        *start = ptr;
        ptr->next = NULL;
        return;
    }
    (*start)->prev = ptr;
    ptr->next = *start;
    *start = ptr;
}

void insertEnd(DLL **start)
{
    int val;
    printf("Enter the element: ");
    scanf("%d", &val);
    DLL *ptr = (DLL *)malloc(sizeof(DLL));
    ptr->data = val;
    ptr->next = NULL;

    if (*start == NULL)
    {
        *start = ptr;
        ptr->prev = NULL;
        return;
    }

    DLL *p = *start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
}
void insertMid(DLL **start)
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
    DLL *ptr = (DLL *)malloc(sizeof(DLL));
    ptr->data = val;
    if (*start == NULL)
    {
        if (pos == 1)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            *start = ptr;
        }
        else
        {
            printf("Invalid position\n");
        }
        return;
    }
    if (pos == 1)
    {
        (*start)->prev = ptr;
        ptr->next = *start;
        *start = ptr;
        ptr->prev = NULL;
        return;
    }
    int x = 1;
    DLL *p;
    for (p = *start; p != NULL; p = p->next)
    {
        if (x + 1 == pos)
        {
            ptr->next = p->next;
            ptr->prev = p;
            if (ptr->next != NULL)
                ptr->next->prev = ptr;
            p->next = ptr;
            return;
        }
        x++;
    }
    printf("Invalid position\n");
}
void deleteBeg(DLL **start)
{
    if (*start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    DLL *p = *start;
    *start = (*start)->next;
    if (((*start) != NULL))
        (*start)->prev = NULL;
    free(p);
}
void deleteEnd(DLL **start)
{
    if (*start == NULL)
    {
        return;
    }
    DLL *p = *start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    if (p->prev != NULL)
        p->prev->next = NULL;
    else
        *start = NULL;
    free(p);
}
void deleteMid(DLL **start)
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
    if ((*start)->next == NULL) // one element case
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
        DLL *p = *start;
        *start = (*start)->next;
        (*start)->prev = NULL;
        free(p);
        return;
    }
    DLL *p;
    int x = 1;
    for (p = *start; p != NULL; p = p->next)
    {
        if (x == pos)
        {
            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;
            free(p);
            return;
        }
        x++;
    }
    printf("---------Invalid position-------\n");
}
void display(DLL *start)
{
    if (start == NULL)
    {
        printf("The list is empty to print\n");
        return;
    }
    DLL *p;
    printf("The elements in the doubly linked list are \n");
    for (p = start; p->next != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("%d ", p->data);
    printf("----- ");
    for (; p != NULL; p = p->prev)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}
int main()
{
    int ch;
    printf("1 : insert element at the begining\n2 : insert element at the end\n3 : insert using position\n4 : del element at the begining\n5 : del element at the end\n6 : del using position\n ");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 1)
            insertBeg(&head);
        else if (ch == 2)
            insertEnd(&head);
        else if (ch == 3)
            insertMid(&head);
        else if (ch == 4)
            deleteBeg(&head);
        else if (ch == 5)
            deleteEnd(&head);
        else if (ch == 6)
            deleteMid(&head);
        display(head);
    } while (ch != 0);
}