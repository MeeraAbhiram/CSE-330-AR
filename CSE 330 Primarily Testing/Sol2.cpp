#include <stdio.h>

int main(){
int T;
scanf("%d", &T);
while (T--)
{
long long X;
scanf ("%lld",&X);
int bisa = 0;
if (X == 1)
{
printf ("YES\n");
bisa = 1;
}
X++;
if (X%2 == 0 && !bisa)
{
printf ("YES\n");
bisa = 1;
}
for (long long f = 3;f*f<=X && !bisa; f+=2)
{
if (X%f == 0)
{
printf ("YES\n");
bisa = 1;
break;
}
}
if (bisa == 0)
printf ("NO\n");

}
}
