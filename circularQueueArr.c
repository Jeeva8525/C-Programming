//Implementing circular queue using arrays
#include <stdio.h>
#define N 5 // size of the array
typedef struct circularQueue
{
    int data[N];
    int front, rear;
} CQ;
void initialise(CQ *q)
{
    q->front = q->rear = -1;
}
void enQueue(CQ *q, int val)
{
    if ((q->rear+1)%N != q->front)
    {
        q->rear = (q->rear+1)%N;
        q->data[(q->rear)% N] = val;
    }
    else
        printf("The queue is full\n");

    if (q->front == -1)
        q->front = 0;
}
void deQueue(CQ *q)
{
    if (q->front == -1 || q->front == q->rear)
    {
        q->front = q->rear = -1;
        return;
    }
    q->front++;
}
void display(CQ q)
{
    if (q.front == -1)
    {
        printf("-------------The queue is empty------------\n");
        return;
    }
    printf("The elements in the queue are\n");
    for (int x = q.front; x <= q.rear && x>=q.front;  )
    {
        printf("%d ", q.data[x]);
        
        if( (x = (x + 1) % N ) == q.front)
            break; 
    }
    printf("\n");
}
void main()
{
    int ch;
    int val;
    CQ queue;
    initialise(&queue);
    printf("1 : add an element to the queue\n2 : delete an element from the queue\n3 : display the current elements in the queue\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            ch = 0;
            break;
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            enQueue(&queue, val);
            break;
        case 2:
            deQueue(&queue);
            break;
        case 3:
            display(queue);
            break;
        default:
            printf("Invalid choice\n");
        }
        display(queue);
    } while (ch != 0);
}