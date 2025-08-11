#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int coeff,power;
    struct poly *next;
} poly;
void insEnd(poly **start, int val, int power)
{

    poly *ptr = (poly *)malloc(sizeof(poly));
    ptr->coeff = val;
    ptr->power = power;
    if (*start == NULL)
    {
        *start = ptr;
        ptr->next = NULL;
        return;
    }

    poly *p = *start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
void sorter(poly *a)
{
    poly *t3=(poly*)malloc(sizeof(poly));
    for(poly *t1 = a;t1->next != NULL ;t1=t1->next)
    {
        for(poly *t2 = t1->next;t2 != NULL ;t2=t2->next)
        {
                if(t1->power < t2->power)
                {
                        t3->power = t1->power;
                        t1->power = t2->power;
                        t2->power = t3->power;

                        t3->coeff = t1->coeff;
                        t1->coeff = t2->coeff;
                        t2->coeff = t3->coeff;
                }
        }
    }
}

void display(poly**);
poly *add(poly *a, poly *b)
{
    poly *p=a, *q=b, *r=NULL;
    sorter(p);
    sorter(q);

    do
    {
        if(p==NULL)
        {
            insEnd(&r,q->coeff,q->power);
            q = q->next;
        }
        else if(q==NULL)
        {
            insEnd(&r,p->coeff,p->power);
            p = p->next;
        }
        else if (p->power == q->power)
        {
            insEnd(&r,p->coeff+q->coeff,p->power);
            p = p->next;
            q = q->next;
        }
        else if (p->power > q->power)
        {
            insEnd(&r,p->coeff,p->power);
            p = p->next;
        }
        else if (q->power > p->power)
        {
            insEnd(&r,q->coeff,q->power);
            q = q->next;
        }

    } while (p!=NULL||q!=NULL);
    return r;
}
void display(poly **start)
{
    if (*start == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    for (poly *p=*start ; p!=NULL ; p=p->next)
    {
        printf("%dx^%d ",p->coeff,p->power);
    }
}
void main()
{
    poly *p1 = NULL, *p2 = NULL , *r=NULL;
    int val, power;
    int ch=1;
    printf("1 : add element to first polynomial\n2 : add element to second polynomial\n3 : add and show the result\n");
    while(ch!=0)
    {
        printf("Enter choice : ");
        scanf("%d",&ch);

        if(ch == 1)
        {
            printf("Enter coeff and power of the element: ");
            scanf("%d %d",&val,&power);
            insEnd(&p1,val,power);
        }
        else if(ch == 2)
        {
            printf("Enter coeff and power of the element: ");
            scanf("%d %d",&val,&power);
            insEnd(&p2,val,power);
        }
        else if(ch == 3)
        {
            r = add(p1,p2);
            printf("The added poly is ");
            display(&r);
            printf("\n");
            ch = 0;
        }
        else
        {
            printf("------------- Exiting --------------");
        }
    }
}