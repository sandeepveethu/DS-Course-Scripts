#include <stdio.h>

void calculate_change(int,int*);

void main()
{
    int n ;
    int change[] = {100,25,10,5,1} ; //dollar,quarters,dimes,nickels,pennies
    printf("enter the amount you want to change : ");
    scanf("%d",&n);
    calculate_change(n,change);    
}


void calculate_change(int n , int * c)
{
    int i,sum=0,count[5];
    for(i=0;i<5;i++) //type of coins or notes available are 5
    {
        count[i]=0;
        while(sum+c[i]<=n)
        {
            sum += c[i];
            count[i]++;
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",count[i]);
    }

}
