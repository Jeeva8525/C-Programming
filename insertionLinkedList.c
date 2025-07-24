#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int val;
    struct linkedList *next;
} node;
void insert(node **start, int pos, int value)
{
    int currentPos = 0;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->val = value;

    if (pos == 0)
    {
        ptr->next = *start;
        *start = ptr;
        return;
    }

    for (node *temp = *start; temp != NULL; temp = temp->next)
    {
        if (currentPos > pos - 1)
        {
            printf("Position is out of range\n");
            return;
        }
        if (currentPos == pos - 1)
        {
            // node* t;
            ptr->next = temp->next;
            temp->next = ptr;
            return;
        }
        currentPos++;
    }
    printf("Position is out of range\n");
}
void printList(node* head)
{
    node *temp = head;
    printf("The elements in the linkedList are\n");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    node a, b, c;
    a.val = 1;
    a.next = &b;

    b.val = 3;
    b.next = &c;

    c.val = 2;
    c.next = NULL;

    node *head = &a;
    printList(head);


    int pos, num;
    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);
    pos--;

    printf("Enter the value : ");
    scanf("%d", &num);

    insert(&head, pos, num);

    printList(head);
}