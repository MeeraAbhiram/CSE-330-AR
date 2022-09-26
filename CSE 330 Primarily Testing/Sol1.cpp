#include <stdio.h>
#include <stdbool.h>
#define Max 1000001
bool p[Max]={};
void seive()
{
p[0]=p[1]=0;
for(int i=2;i*i<Max;i++)
if(!p[i])
for(int j=i*i;j<Max;j+=i)
p[j]=1;
}
int main()
{
int t,n;
scanf("%d",&t);
seive();
while(t--)
{
scanf("%d",&n);
if(!p[n])
printf("No\n");
else
printf("Yes\n");
}
return 0;
}
