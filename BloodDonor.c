#include <stdio.h>
#include <string.h>
#define N 5
typedef struct donor
{
        int id,weight,status;
        char name[20],grp[3];
        char gen[7];
        struct dateofbirth
        {
                int d,y;
                char m[4];
                int monthno;
        }dat[3];//dob , date of last donation , today's date
}don;

int leap(int year)
{
    if((year%400)==0||((year%4)==0&&(year%100)!=0))
        return 1;
    return 0;
}

int refer2(don *d,int a,int b,int choice,int pos)
{
    int dt,mn,yr;
    int totaldays=0;

    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char namemon[12][20]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};

    for(int x=0;x<12;x++)
    {
            if(strcmp(namemon[x],d[pos].dat[a].m)==0)
            {
                    d[pos].dat[a].monthno=x+1;
            }
            if(strcmp(namemon[x],d[pos].dat[b].m)==0)
            {
                    d[pos].dat[b].monthno=x+1;
            }
    }

    if(leap(d[pos].dat[a].y))
        month[1]=29;
    else
        month[1]=28;

    for(dt=d[pos].dat[a].d,mn=d[pos].dat[a].monthno,yr=d[pos].dat[a].y;
                    dt!=(d[pos].dat[b].d)||mn!=d[pos].dat[b].monthno||yr!=d[pos].dat[b].y; )
    {
        totaldays++;
        dt++;
        if(dt>month[mn-1])
        {
            mn++;
            if(mn>12)
            {
                mn=1;
                yr++;
                if(leap(yr))
                    month[1]=29;
                else
                    month[1]=28;
            }
            dt=1;
        }
    }
    int temp=(mn<d[pos].dat[0].monthno)||(mn==d[pos].dat[0].monthno&&dt<d[pos].dat[0].d);
    if(choice==1)//age
        return yr-(d[pos].dat[0].y)-temp;
    else if(choice==2)//difference
        return totaldays;
    else if(choice==3)//next date
    {
        while(totaldays<90)
        {
            totaldays++;
            dt++;
            if(dt>month[mn-1])
            {
                mn++;
                if(mn>12)
                {
                    mn=1;
                    yr++;
                    if(leap(yr))
                        month[1]=29;
                    else
                        month[1]=28;
                }
                dt=1;
            }
        }
        printf("%s can donate after %d %s %d\n\n",d[pos].name,dt,namemon[mn-1],yr);
    }

}
void getdata(don *d,int z)
{
        static int identity=1001;
        d[z].id=identity++;
        printf("Donor - %d \n",z+1);
        printf("Name: ");
        scanf("%s",d[z].name);
        printf("Gender: ");
        scanf("%s",d[z].gen);
        printf("Blood group: ");
        scanf("%s",d[z].grp);
        printf("Weight: ");
        scanf("%d",&d[z].weight);
        printf("Enter Dob\tLast donation date\tdate for donation\n");
        for(int x=0;x<3;x+=1)
        {
                scanf("%d %s %d",&d[z].dat[x].d,d[z].dat[x].m,&d[z].dat[x].y);
        }

}
int check(don *d,int x)
{
    d[x].status=0;
    int age=refer2(d,0,2,1,x);
    int diff=refer2(d,1,2,2,x);
    if(age>17)
    {
        if(d[x].weight>50)
        {
            if(diff>90)
            {
                printf("\n%s is eligible\n",d[x].name);
                d[x].status=1;
            }
            else
                refer2(d,1,2,3,x);
        }
        else
            printf("\nWeight is low for person - %s\n",d[x].name);
    }
    else
        printf("\nAge is low for %s\n",d[x].name);
}

/*
void printreg(don *d,int n)
{
        for(int x=0;x<n;x++)
        {
                printf("Name:%s\nAge:%d\nid:%d\nblood grp:%s\nweight:%d\n\n\n",d[x].name,d[x].age,d[x].id,d[x].grp,d[x].weight);
        }
}
*/
void gend(don *d,int n)
{
        printf("The persons having specific grps are\n");
        for(int x=0;x<n;x++)
        {
                if(strcmp(d[x].gen,"male")==0 && strcmp(d[x].grp,"b+")==0)
                {
                        printf("%s is having b+\n\n",d[x].name);
                }
                if(strcmp(d[x].gen,"female")==0 && (strcmp(d[x].grp,"o+")==0 || strcmp(d[x].grp,"o-")==0))
                {
                        printf("%s is having o\n\n",d[x].name);
                }
        }
}


void main()
{
        don d[N];
        int n;
        int date,year;
        char blgrp[3],monthname[4];
        printf("Enter the number of donors: ");
        scanf("%d",&n);
        for(int z=0;z<n;z++)
            getdata(d,z);
        for(int x=0;x<n;x++)
            check(d,x);
        printf("Enter the blood group to be searcher : ");
        scanf("%s",blgrp);
        scanf("%d %s %d",&date,monthname,&year);
        for(int x=0;x<n;x++)
        {
            if(strcmp(d[x].grp,blgrp)==0 && d[x].status==1)
            {
                    printf("\n%s can donate\n",d[x].name);
            }
        }
        printf("\n\n");
        gend(d,n);


}