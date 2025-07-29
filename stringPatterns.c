//Prints the strings in a pattern using a simple for loop
#include <stdio.h>
void main()
{
    char *str[4]={"String","Topics","Hello","World"};
    int num=4,len=6;
    //Pattern 1:
    for(int x=0;x<num;x++)
    {
        for(int y=0;y<len;y++)
        {
            printf("%c",*(*(str+x)+y));
        }
        printf("\n");
    }
    printf("\n\n");


    //Pattern 2:
    for(int x=0;x<num;x++)
    {
        printf("%s\n",(*(str+x))+1);
    }
    printf("\n\n");


    //Pattern 3:
    for(int x=0;x<num;x++)
    {
        printf("%c\n",**(str+x));
    }
    printf("\n\n");


    //Pattern 4:
    for(int x=0;x<num;x++)
    {
        for(int y=0;*(*(str+x)+y)!='\0';y++)
        {
            printf("%s\n",*(str+x)+y);
        }
        printf("\n");
    }
}