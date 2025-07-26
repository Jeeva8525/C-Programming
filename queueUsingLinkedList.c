#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} queue;
queue *front = NULL;
queue *rear = NULL;
void enQueue(int val)
{
    queue *newNode = (queue *)malloc(sizeof(queue));
    newNode->data = val;
    newNode->next = NULL;
    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void deQueue()
{
    if (front == NULL)
    {
        printf("The queue is already empty\n");
        return;
    }
    else if(front == rear)
    {
        free(rear);
        front = NULL;
        rear = NULL;
        return;
    }
    queue *temp = front;
    front = front->next;
    free(temp);
}
void displayQueue()
{
    for (queue *mass = front; mass != NULL; mass = mass->next)
    {
        printf("%d ", mass->data);
    }
    printf("\n");
}
int main()
{
    int ch;
    int val;
    printf("1 : add element to the queue\n2 : delete element from the queue\n3 : display the current elements in the queue\n4 : display this menu again\n5 : quit the operation\n");
    do
    {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be added: ");
            scanf("%d", &val);
            enQueue(val);
            displayQueue();
            break;
        case 2:
            deQueue();
            //use fall through to print
        case 3:
            displayQueue();
            break;
        case 4:
            printf("1 : add element to the queue\n2 : delete element from the queue\n3 : display the current elements in the queue\n4 : display this menu again\n5 : quit the operation\n");
            break;
        default:
            ch=0;
        }
    }while(ch);
}