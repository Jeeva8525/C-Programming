#include <stdio.h>
#define size 100
typedef struct stack
{
    int arr[size];
    int top;
} stack;
void init(stack *s)
{
    s->top = -1;
}
void push(stack *s, int val)
{
    if (s->top == size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    s->top--;
}
void displayStack(stack *s)
{
    for (int x = s->top; x >= 0; x--)
    {
        printf("%d ", s->arr[x]);
    }
    printf("\n");
}
int main()
{
    stack s;
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
            push(&s, val);
            displayStack(&s);
            break;
        case 2:
            pop(&s);
            // use fall through to print
        case 3:
            displayStack(&s);
            break;
        case 4:
            printf("1 : add element to the queue\n2 : delete element from the queue\n3 : display the current elements in the queue\n4 : display this menu again\n5 : quit the operation\n");
            break;
        default:
            ch = 0;
        }
    } while (ch);
}