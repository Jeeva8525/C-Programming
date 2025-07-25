//find a substring in a string
#include <stdio.h>
void main()
{
        int l1,r=0,p,x,y,z=0;
        char str[50],pat[50];
        printf("Enter the string: ");
        scanf("%s",str);
        printf("Enter the substring: ");
        scanf("%s",pat);
        for(l1=0;pat[l1]!='\0';l1++);
        for(x=0;str[x+(l1-1)]!='\0';x++)
        {
                p=0;
                for(y=0;y<l1;y++)
                {
                        if(pat[y]!=str[x+y])
                        {
                                p=1;
                                break;
                        }
                }
                r+=p==0?1:0;
        }
        if(r>0)
        {
                printf("\npattern is present %d times\n",r);
        }
        else
        {
                printf("\nThe pattern is not found in the given string");
        }

}