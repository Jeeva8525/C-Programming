//Converts an infix expression into a postfix expression (works for only inputs with single digits)
//Sample input : (7+3)*4/5
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack
{
    char data;
    struct stack *next;
} stack;
stack *top = NULL;
void push(char val)
{
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
char pop()
{
    char data;
    if (top == NULL)
    {
        printf("The stack is already empty\n");
        return ' ';
    }
    data = top->data;
    stack *temp = top;
    top = top->next;
    free(temp);
    return data;
}
char peek()
{
    if (top != NULL)
        return top->data;
    return ' '; // to show there is no element in the stack
}
int isEmpty()
{
    return top == NULL;
}
void displayStack()
{
    for (stack *p = top; p != NULL; p = p->next)
    {
        printf("%5d \n", p->data);
    }
}

void convertToPostfix(char *str)
{
    int y = 0;
    char exp[2*50];
    // printf("%d is the lenght\n",strlen(str));
    for (int x = 0; x < strlen(str); x++)
    {
        //printf("Func came\n");
        if(str[x]==' ')
        continue;
        if (str[x] == '(')
        {
            push('(');
        }
        else if (str[x] == '+' || str[x] == '-')
        {
            if (isEmpty() || peek() == '(')
            {
                push(str[x]);
                continue;
            }
            while (peek() != ' ' && peek() != '(')
            {
                exp[y++] = pop();
                exp[y++] = ' ';
            }
            push(str[x]);
        }
        else if (str[x] == '*' || str[x] == '/')
        {
            if (isEmpty() || peek() == '(')
            {
                push(str[x]);
                continue;
            }
            while (peek() == '*' || peek() == '/')
            {
                exp[y++] = pop();
                exp[y++] = ' ';
            }
            push(str[x]);
        }
        else if(str[x] == '^')
        {
            if (isEmpty() || peek() == '(')
            {
                push(str[x]);
                continue;
            }
            while (peek() == '^')
            {
                exp[y++] = pop();
                exp[y++] = ' ';
            }
            push(str[x]);
        }
        else if (str[x] == ')')
        {
            while (peek() != '(')
            {
                exp[y++] = pop();
                exp[y++] = ' ';
            }
            pop(); // to remove the ( paranthesis in the stack
        }
        else
        {
            exp[y++] = str[x];
            exp[y++] = ' ';
        }
    }
    while(top!=NULL)
    {
        exp[y++]=pop();
        exp[y++] = ' ';
    }
    exp[y]='\0';
    printf("The expression is %s\n",exp);
}
void main()
{
    char str[50] = "(A + B) * (C - (D / E ^ F) * G)"; 
    printf("Enter the expression: ");
    scanf("%[^\n]",str);
    convertToPostfix(str);
   
}