// A structure for Book with bitfields for status and condition
#include <stdio.h>
#include <string.h>
#define N 10
struct Book
 {
    unsigned int id: 11;
    unsigned char name[20];
    unsigned int status: 2;
    unsigned int cond: 3;
};

void print(struct Book *b,int x)
{
    printf("Book ID: %u\n", b[x].id);
    printf("Book Name: %s\n", b[x].name);
    printf("Status:%u \n",b[x].status);
    printf("Condition: %u \n",b[x].cond);

}


int main()
 {
    struct Book b[N];
    int n;
    printf("Enter number of books : ");
    scanf("%d", &n);
    int st,cond,id;
    for (int i=0;i<n;i++)
    {
        printf("\nEnter information for book %d:\n", i+1);
        printf("Enter Book id: ");
        scanf("%u",&id);
        b[i].id=id;
        printf("Enter Book Name: ");
        scanf("%s",b[i].name);
        printf("Enter Status: ");
        scanf("%u",&st);
        b[i].status=st;
        printf("Enter Condition: ");
        scanf("%u",&cond);
        b[i].cond=cond;

    }

    printf("\nBook Information:\n");
    for (int i = 0; i < n; i++)
    {
       print(b,i);

    }

}