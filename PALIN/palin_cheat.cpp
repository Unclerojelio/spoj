#include<stdio.h>
char num[1000005];
int len;
void nextpalin()
{
   int i,j,k;
   for(i=0,j=len-1;i<=j;++i,--j)
   {
      if(num[i]<num[j])
      {
         for(k=j-1;num[k]=='9';num[k]='0',--k);
         ++num[k];
      }
      num[j]=num[i];
   }
}
int main()
{
   char ch;
   int i,j,test,flag;
   for(scanf("%d%*c",&test);test--;)
   {
      for(len=-1,flag=1;(ch=getchar())!='\n'&&ch!=EOF;num[++len]=ch)
         if(ch!='9')
            flag=0;
      num[++len]='\0';
      if(flag)
      {
         for(putchar('1'),i=len-1;i--;putchar('0'));
         printf("1\n");
      }
      else
      {
         for(i=len-1;num[i]=='9';num[i]='0',--i);
         ++num[i];
         nextpalin();
         nextpalin();
         printf("%s\n",num);
      }
   }
   return 0;
}