//Prints the input string in a criss-cross pattern
//Preferably give inputs in a string of odd length
#include <stdio.h>
#include <string.h>
void crossPrint(char str[])
{
    int len = strlen(str);
    for (int x = 0; x < len; x++)
    {
        for (int y = 0; y < len; y++)
        {
            if (x == y || x==(len-y-1))
                printf("%c ", str[x]);
            else
                printf("  ");
        }
        printf("\n");
    }
}
int main()
{
    char str[100];
    printf("Enter the String : ");
    scanf("%[^\n]", str);
    crossPrint(str);
}