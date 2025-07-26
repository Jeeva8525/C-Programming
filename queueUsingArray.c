#include <stdio.h>
#define size 100
typedef struct queue
{
    int arr[size];
    int front;
    int rear;
} queue;
void init(queue *s)
{
    s->front = -1;
    s->rear = -1;
}
void enQueue(queue *s, int val)
{
    if(s->front == -1)
    {
        s->front=0;
    }
    if (s->rear == size - 1)
    {
        printf("queue overflow\n");
        return;
    }
    s->arr[++s->rear] = val;
}
void deQueue(queue *s)
{
    if (s->front == -1 || s->front > s->rear)
    {
        printf("queue underflow\n");
        return;
    }
    s->front++;
    if(s->front > s->rear)
    {
        s->front = s->rear = -1;
    }
}
void displayqueue(queue *s)
{
    if(s->front != -1)
    {
        for (int x = s->front; x <= s->rear; x++)
        {
            printf("%d ", s->arr[x]);
        }
    }
    printf("\n");
}
    int main()
    {
        queue s;
        init(&s);
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
            enQueue(&s, val);
            displayqueue(&s);
            break;
        case 2:
            deQueue(&s);
            // use fall through to print
        case 3:
            displayqueue(&s);
            break;
        case 4:
            printf("1 : add element to the queue\n2 : delete element from the queue\n3 : display the current elements in the queue\n4 : display this menu again\n5 : quit the operation\n");
            break;
        default:
            ch = 0;
        }
    } while (ch);
}