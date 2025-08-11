//Gets input for two linked lists (even and odd) and arranges them such a way that every odd number is preceeded by a even number
#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
        int data;
        struct linkedList *next;
}list;
void insertEnd(list **start,int val)
{
        list *ptr =(list*) malloc(sizeof(list));
        ptr->data = val;
        ptr->next = NULL;
        if(*start == NULL)
        {
                *start = ptr;
                return;
        }
        list *p;
        for(p = *start ; p->next != NULL ; p=p->next);
        p->next = ptr;
}
void display(list **start)
{
        if(*start == NULL)
        {
                printf("The list is empty\n");
                return;
        }
        printf("The elements in the linked list are\n");
        for(list *p=*start ; p!=NULL ; p=p->next)
        {
                printf("%d ",p->data);
        }
        printf("\n");
}
list *addFrom(list *even,list *odd)
{
        int x=0;
        list *head=NULL;
        while(even!=NULL || odd!=NULL)
        {
                if(x%2)
                {
                        insertEnd(&head,even->data);
                        even=even->next;
                }
                else
                {
                        insertEnd(&head,odd->data);
                        odd=odd->next;
                }
                x++;
        }
        return head;
}
int main()
{
        list *oddHead=NULL;
        list *evenHead=NULL;

        int N=10;
        printf("Enter the number of elements: ");
        scanf("%d",&N);
        int val;
        printf("Enter elements for even linked list\n");
        for(int x=0;x<N;x++)
        {
                printf("Enter element-%d: ",x+1);
                scanf("%d",&val);
                insertEnd(&evenHead,val);
        }
        printf("Enter elements for odd linked list\n");
        for(int x=0;x<N;x++)
        {
                printf("Enter element-%d: ",x+1);
                scanf("%d",&val);
                insertEnd(&oddHead,val);
        }
        display(&oddHead);
        display(&evenHead);

        list *head=NULL;
        head = addFrom(oddHead,evenHead);
        display(&head);
}