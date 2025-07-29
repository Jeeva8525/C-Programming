//get name,id,runs,wickets,type and do operations
#include <stdio.h>
#define N 11
typedef struct players
{
        char type,name[20];
        int id,run,wick;
}pl;
int num=0;
void read(pl *a,int n)
{

        for(int x=0;x<n;x++)
        {
                printf("\tName , Id , runs , wickets , type\nEnter: ");
                scanf("%s %d %d %d %c",a[x].name,&a[x].id,&a[x].run,&a[x].wick,&a[x].type);
                if(a[x].type=='a')
                        num++;
        }

}
void print(pl *a,int n)
{
        for(int x=0;x<n;x++)
        {
                printf("Player - %d\n",x+1);
                printf("Name: %s\nId: %d\nruns: %d\nwickets: %d\ntype: %c\n\n",(a+x)->name,(a+x)->id,(a+x)->run,(a+x)->wick,(a+x)->type);
        }
}
int best(pl *a,int n,int m)
{
        int max=0;
        if(m==1)
        {

                for(int x=0;x<n;x++)
                {
                        if(a[x].type=='a')

                        {
                                if((a[max].wick*0.6+a[max].run*0.4)<(a[x].wick*0.6+a[x].run*0.4))
                                        max=x;
                        }

                }
        }
        else if(m==2)
        {
                for(int x=0;x<n;x++)

                {
                        if(a[x].type=='b')
                        {

                                if(a[max].run<a[x].run)
                                {

                                        max=x;
                                }

                        }
                }

        }
        else
        {
                for(int x=0;x<n;x++)
                {
                        if(a[x].type=='c')
                        {

                                if(a[max].wick<a[x].wick)
                                {
                                        max=x;
                                }
                        }
                }
        }
        return max;
}
void main()
{
        pl p[N];
        int n;
        printf("Enter the number of players: ");
        scanf("%d",&n);
        read(p,n);

        print(p,n);
        printf("The best all rounder is %s\n",p[best(p,n,1)].name);
        printf("The best batsman is %s\n",p[best(p,n,2)].name);
        printf("The best bowler is %s\n",p[best(p,n,3)].name);
        printf("The number of all rounders are %d\n",num);
}