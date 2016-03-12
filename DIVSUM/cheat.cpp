include<stdio.h>
#include<math.h>
int main(void)
{
   int cases;
   int num,sum[200001],limit;
   int i,j,max;
   
   
   scanf("%d",&cases);
   
   for(i=0;i<=cases;i++)
    sum[i]=1;
   
   
   for(i=0;i<cases;i++)
   {
      scanf("%d",&num);
      
      max=sqrt(num);
      limit=num/2;
      if(max*max==num) /* if number is square root */
      {
         for(j=2;j<=limit+1;j=j+1)
         {
            if(num%j==0)
             sum[i]=sum[i]+j;
         }
      
      }
      
      else   /* remaining numbers */
      {
         for(j=2;j<=max;j=j+1)
         {
            if(num%j==0)
             sum[i]=sum[i]+j+(num/j);
         }   
      }
      }

   printf("\n");
   
   for(i=0;i<cases;i++)
   {
      printf("%d\n",sum[i]);
   }

   return 0;

}