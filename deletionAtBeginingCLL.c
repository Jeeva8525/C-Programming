#include <stdio.h>
#include <stdlib.h>
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} CLL;
void delBeg(CLL **start)
{
    if (*start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    if((*start)->next==*start)
    {
        free(*start);
        *start=NULL;
        return;
    }

    CLL *p = *start;
    while(p->next!=*start)
    {
        p = p->next;
    }
    p->next = (*start)->next;
    free(*start);
    *start = p->next;
}
void display(CLL *start)
{
    if (start == NULL)
    {
        printf("-------------There are no elements in the circular list------------\n");
        return;
    }
    printf("The elements in the circular linked list are \n");
    printf("%d ",start->data);
    if(start->next!=NULL)
    {
        for (CLL *p = start->next; p!= start && p!=NULL; p = p->next)
        {
            printf("%d ",p->data);
        }
    }
    printf("\n");
}
void main()
{
    CLL *head =  (CLL*)malloc(sizeof(CLL));
    CLL *temp;
    head->data = 1;
    temp = head;
    char ch;

    for(int x=2;x<5;x++)
    {
        CLL *ptr = (CLL*)malloc(sizeof(CLL));
        temp->next=ptr;
        ptr->data=x;
        ptr->next=head;
        temp=ptr;
    }
    display(head);
    do
    {
        printf("Do you want to delete an item(y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            delBeg(&head);
            display(head);
        }
    } while (ch == 'y' || ch == 'Y');
    display(head);

}