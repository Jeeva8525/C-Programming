//To concatenate 2 strings
#include <stdio.h>
void main()
{
    int x,l;
    char str1[50],str2[50];
    printf("Enter the two strings\n");
    scanf("%s",str1);
    scanf("%s",str2);
    for(l=0;str1[l]!='\0';l++);
    str1[l]=' ';
    l++;
    for(x=0;str2[x]!='\0';x++)
    {
        str1[l+x]=str2[x];
    }
    str1[l+x]='\0';
    printf("New string is %s",str1);
}