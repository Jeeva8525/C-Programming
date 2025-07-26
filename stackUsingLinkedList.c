#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} stack;
stack *top = NULL;
void push(int val)
{
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void pop()
{
    if (top == NULL)
    {
        printf("The stack is already empty\n");
        return;
    }
    stack *temp = top;
    top = top->next;
    free(temp);
}
void displayStack()
{
    for (stack *mass = top; mass != NULL; mass = mass->next)
    {
        printf("%5d \n", mass->data);
    }
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
            push(val);
            displayStack();
            break;
        case 2:
            pop();
            // use fall through to print
        case 3:
            displayStack();
            break;
        case 4:
            printf("1 : add element to the queue\n2 : delete element from the queue\n3 : display the current elements in the queue\n4 : display this menu again\n5 : quit the operation\n");
            break;
        default:
            ch = 0;
        }
    } while (ch);
}