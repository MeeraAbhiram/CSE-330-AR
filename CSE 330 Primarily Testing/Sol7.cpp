#include<iostream>
#include<climits>
#include<cstring>
#define maxN 1000001
using namespace std;

int prime[maxN];

void sieve()
{
memset(prime,-1,sizeof(prime));
for(int i=2;i<maxN;i++)
{
if(prime[i]==-1)
{
for(int j=i;j<maxN;j+=i)
if(prime[j]==-1)
prime[j]=i;
}
}

}
int main()
{
int t;
scanf("%d",&t);
sieve();
while(t--)
{
int n;
scanf("%d",&n);
printf("%d\n",n-prime[n]);
}
return 0;
}
