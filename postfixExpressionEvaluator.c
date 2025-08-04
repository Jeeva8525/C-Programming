//Give the input with spaces between every single data item like 2 16 + 3 4 * -
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
int pop()
{
    int elt;
    if (top == NULL)
    {
        printf("The stack is already empty\n");
        return 0;
    }
    elt = top->data;
    stack *temp = top;
    top = top->next;
    free(temp);
    return elt;
}
void displayStack()
{
    printf("The stack elements are\n");
    for (stack *p = top; p != NULL; p = p->next)
    {
        printf("%5d \n", p->data);
    }
}
int calculateExp(char exp[])
{
    int a, b, temp;
    char op;
    for (int x = 0; x < strlen(exp); x++)
    {
        if (isdigit(exp[x]))
        {
            temp = 0;
            while(exp[x]!=' ')
            {
                temp = temp * 10 + (exp[x]-'0'); 
                x++;
            }
            push(temp);
        }
        else if(exp[x]==' ')
        {
            continue;
        }
        else
        {
            b = pop();
            a = pop();
            op = exp[x];
            switch (op)
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '^':
                push(a ^ b);
                break;
            case '/':
                if (b != 0)
                {
                    push(a / b);
                    break;
                }
                else
                {
                    printf("Division Error: division by 0 occured\n");
                    return 0;
                }
            }
        }
    }
    return pop();
}
int main()
{
    char expression[100];
    printf("Enter the expression: ");
    scanf("%[^\n]", expression);
    printf("The evaluated answer is %d", calculateExp(expression));
}