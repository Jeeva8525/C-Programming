#include <stdio.h>
typedef struct listNode
{
    int val;
    struct listNode *next;
} list;
void sorter(list *head){
    int swapper;
    for (list *temp = head; temp != NULL; temp = temp->next)
    {
        for (list *temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp->val > temp2->val)
            {
                swapper = temp->val;
                temp->val = temp2->val;
                temp2->val = swapper;
            }
        }
    }

}
int main()
{
    list a, b, c;
    a.val = 1;
    a.next = &b;
    
    b.val = 3;
    b.next = &c;

    c.val = 2;
    c.next = NULL;

    list *head = &a;

    sorter(head);

    list *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
}