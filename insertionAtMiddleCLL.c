#include <stdio.h>
#include <stdlib.h>
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} CLL;
void insMid(CLL **start)
{
    int val,pos;
    printf("Enter the element: ");
    scanf("%d", &val);
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos<1)
    {
        printf("Invalid position\n");
        return;
    }
    CLL *ptr = (CLL *)malloc(sizeof(CLL));
    ptr->data = val;
    if (*start == NULL)
    {
        if(pos==1)
        {
            ptr->next = ptr;
            *start = ptr;
        }
        else{
            printf("Invalid position\n");
        }
        return;
    }
    CLL *p;
    if (pos == 1)
    {
        for (p = *start; p->next != *start; p = p->next);
        p->next = ptr;
        ptr->next = *start;
        *start = ptr;
        return;
    }
    int x=1;
    for (p = *start; p != *start || x==1 ; p = p->next)
    {
        if(x+1==pos)
        {
            ptr->next=p->next;
            p->next = ptr;
            return;
        }
        x++;
    }
    printf("Invalid position\n");
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
            insMid(&head);
            display(head);
        }
    } while (ch == 'y' || ch == 'Y');
    display(head);

}