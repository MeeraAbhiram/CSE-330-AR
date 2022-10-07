#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
int a[1000],b[1000],c[1000],g[1000],t[1000];
char s[1001];

void make(int x,int *a) {
	a[0]=0;
	while (x) {
		a[++a[0]]=x%10;
		x/=10;
	}
}

void mul(int *a,int *b) {  // a*=b
int i,j;
	if (a[0]*b[0]==0) {
		a[0]=0;
		return;
	}
	c[0]=a[0]+b[0]-1;
	for (i=1;i<=c[0];++i)
		c[i]=0;
	c[c[0]+1]=0;
	for (i=1;i<=a[0];++i)
		for (j=1;j<=b[0];++j)
			c[i+j-1]+=a[i]*b[j];
	for (i=1;i<=c[0];++i) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if (c[c[0]+1])
		++c[0];
	for (i=0;i<=c[0];++i)
		a[i]=c[i];
}

void dec(int *a,int *b) {  //a-=b a>=b
int i;
	for (i=1;i<=a[0];++i) {
			a[i]-=(i>b[0])?0:b[i];
			if (a[i]<0) {
				a[i]+=10;
				--a[i+1];
			}
	}
	while (a[0] && !a[a[0]])
		--a[0];
}


void divp(int *b,int p) {
int ca,i;
ll temp;

	while (b[0]) {
		ca=0;
		for (i=b[0];i>0;--i) {
			temp=((ll) ca*(ll) 10)+b[i];
			ca=temp%p;
			b[i]=temp/p;
		}
		while (b[0] && (b[b[0]]==0)) {
			--b[0];
		}
		make(ca+1,t);
		mul(g,t);

	}
}

void print(int *a) {
int i;
	if (a[0]==0) {
		printf("0\n");
		return;
	}
	for (i=a[0];i>0;--i)
		printf("%d",a[i]);
	printf("\n");
}

int main() {
int i,z,p;
	for (scanf("%d",&z);z;--z) {
		g[0]=g[1]=1;
		scanf("%s%d",s,&p);
		b[0]=a[0]=strlen(s);
		for (i=1;i<=a[0];++i)
			b[i]=a[i]=s[a[0]-i]-'0';
		divp(b,p);
		++a[1];
		a[a[0]+1]=0;
		for (i=1;i<=a[0];++i) {
			if (a[i]>=10) {
				a[i]-=10;
				++a[i+1];
			}
			else {
				break;
			}
		}
		if (a[a[0]+1]) {
			++a[0];
		}
		dec(a,g);
		print(a);
	}
	return 0;
}


