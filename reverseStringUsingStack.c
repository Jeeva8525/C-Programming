#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
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
    char elt;
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
/* int isEmpty()
{
    return top==NULL;
} */
void displayStack()
{
    printf("The stack elements are\n");
    for (stack *p = top; p != NULL; p = p->next)
    {
        printf("%c \n", p->data);
    }
}
char* reverseString(char temp[],int x,char result[])
{
    if(x<strlen(temp))
    {
        push(temp[x]);          
        reverseString(temp,x+1,result);
    }
    else if(x<(2*strlen(temp)))
    {
        result[x-strlen(temp)]=pop();
        reverseString(temp,x+1,result);
    }
    else
    {
        return result;
    }
}
int main()
{
    char word[size];
    char result[size]="";
    printf("Enter the string: ");
    scanf("%s", word);
    strcpy(result,reverseString(word,0,result));
    printf("The reversed string is %s\n",result);
    if(strcmp(word,result)==0)
    {
        printf("The string is a palindrome\n");
    }
    else
    {
        printf("The string is not a palindrome\n");
    }
}