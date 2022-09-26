#include<stdio.h>
#include<math.h>

int main()
{
int tc,n,i,a;
while(scanf("%d",&tc)==1){
for(i=1;i<=tc;i++){
scanf("%d",&n);
if(n%2==0 && n>=4){
printf("Deepa\n");
}
else
printf("Arjit\n");
}
}

return 0;
}
