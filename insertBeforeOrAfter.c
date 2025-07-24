/*This program allows you to insert an element before or after another element*/
#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int val;
    struct linkedList *next;
} node;
int insert(node **start)
{
    int num, searchElement, choice;
    node *ptr = (node *)malloc(sizeof(node));
    printf("Inserting Element: ");
    scanf("%d", &num);
    if (num == -999)
    {
        return 1;
    }
    ptr->val = num;

    printf("Enter the element to be searched: ");
    scanf("%d", &searchElement);
    printf("Where should the element be inserted?\n1 for inserting before the search Element\n2 for inserting after the search element\nEnter: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 2)
    {
        printf("Invalid choice");
        return 0;
    }
    node *before = *start;
    if (choice == 1)
    {
    }
    if (before == NULL)
    {
        printf("The list is empty ! No element to search\n");
        return 0;
    }
    else if (before->next == NULL)
    {
        if (before->val == searchElement)
        {
            if (choice == 1)
            {
                ptr->next = before;
                *start = ptr;
            }
            else
            {
                before->next = ptr;
                ptr->next = NULL;
            }
        }
        else
        {
            printf("No such element\n");
        }
        return 0;
    }
    else if (before->val == searchElement)
    {
        if (choice == 1)
        {
            ptr->next = before;
            *start = ptr;
        }
        else
        {
            ptr->next = before->next;
            before->next = ptr;
        }
        return 0;
    }
    for (node *item = before->next; item != NULL; before = item, item = item->next)
    {
        // before insertion
        if (item->val == searchElement)
        {
            if (choice == 1)
            {
                ptr->next = item;
                before->next = ptr;
            }
            else
            {
                ptr->next = item->next;
                item->next = ptr;
            }
            return 0;
        }
    }
    printf("No such element\n");
}
void printList(node *start)
{
    printf("The array elements are\n");
    for (; start != NULL; start = start->next)
    {
        printf("%d ", start->val);
    }
    printf("\n");
}
int main()
{
    /* node* a = (node* )malloc(sizeof(node));
    node* b = (node* )malloc(sizeof(node));
    node* c = (node* )malloc(sizeof(node));
    node* d = (node* )malloc(sizeof(node));

    a->val=1;a->next=b;
    b->val=2;b->next=c;
    c->val=3;c->next=d;
    d->val=4;d->next=NULL; */

    node *head = (node *)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;
    printf("The initial value is assigned as 0\n");
    printList(head);
    while (!insert(&head))
    {
        printList(head);
    }

    return 0;
}