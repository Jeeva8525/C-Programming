//creates a struct and get regno. name,daysch/host , height , phone no , gender
#include <stdio.h>
#include <ctype.h>
typedef struct student
{
        int reg;
        float ht;
        long ph;
        char gend,stay;
        char name[50];
} st;
void get(st a[],int n)
{
        for(int x=0;x<n;x++)
        {
                printf("Student-%d\n",x+1);
                printf("Enter the name: ");
                scanf("%s",a[x].name);
                printf("Male/Female(M/F): ");
                scanf(" %c",&a[x].gend);
                printf("Enter the reg num: ");
                scanf("%d",&a[x].reg);
                printf("Enter the height: ");
                scanf("%f",&a[x].ht);
                printf("Dayschollar/Hosteller(D/H): ");
                scanf(" %c",&a[x].stay);
                if(toupper(a[x].stay)=='H')
                {
                        printf("Enter the phone number: ");
                        scanf("%ld",&a[x].ph);
                }
                else
                        a[x].ph=0;
        }
}
long hostel(st a[],int n)
{
        int add;
        printf("The students in hostel are\n");
        for(int x=0;x<n;x++)
                if(toupper(a[x].stay)=='H')
                {
                        printf("%s\n",a[x].name);
                        add+=a[x].ph;
                }
        printf("\n\n");
        return add;
}
void sort(st a[],int n)
{
        st temp;
        for(int x=0;x<n-1;x++)
                for(int y=x+1;y<n;y++)
                {
                        if(a[x].reg>a[y].reg)
                        {
                                temp=a[x];
                                a[x]=a[y];
                                a[y]=temp;
                        }
                }
}
void printst(st a[],int n)
{
        for(int x=0;x<n;x++)
                printf("%s\t%d\t%c\t%c\t%.2f\t%ld\n",a[x].name,a[x].reg,a[x].stay,a[x].gend,a[x].ht,a[x].ph);
}

void main()
{
        st s[10];
        int n;
        printf("Enter the number of students: ");
        scanf("%d",&n);
        get(s,n);
        printf("\n\n");
        printf("The result of phone numbers are : %ld\n\n",hostel(s,n));
        sort(s,n);
        printf("Name\treg-no\tstay\tgender\theight\tph_no\n");
        printst(s,n);
}