#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList
{
    int val;
    struct linkedList *next;
} node;
void delete(node **start, int pos)
{
    int currentPos = 0;

    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 0)
    {
        node* temp = *start;
        *start = temp->next;
        free(temp);
        return;
    }

    for (node *temp = *start; temp != NULL; temp = temp->next)
    {
        if (currentPos == pos - 1)
        {
            if (temp->next == NULL) {
                printf("Position is out of range\n");
                return;
            }
            node* temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
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
    node *a=(node*)malloc(sizeof(node));
    node *b=(node*)malloc(sizeof(node));
    node *c=(node*)malloc(sizeof(node));

    a->val = 1; a->next = b;
    b->val = 3; b->next = c;
    c->val = 2; c->next = NULL;

    node *head = a;
    printList(head);


    int pos, num;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    pos--;

    delete(&head, pos);

    printList(head);
}