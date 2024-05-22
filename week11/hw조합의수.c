#include<stdio.h>
#include<stdlib.h>

long long comb(long long**m,long long n, long long r)
{
	
	if(r==0||r==n) return 1;
	
	if(m[n-1][r-1]==0)
		m[n-1][r-1]=comb(m,n-1,r-1);
	if(m[n-1][r]==0)
		m[n-1][r]=comb(m,n-1,r);
	//printf("comb(%d,%d)\n",n,r);
	return m[n-1][r-1]+m[n-1][r];
	
}
int main(void)
{
	int C;
	int n,r;
	scanf("%d %d",&n,&r);
	long long **m=(long long**)malloc(sizeof(long long)*n);
	
	for(int i=0;i<n;i++)
			m[i]=(long long*)malloc(sizeof(long long)*n);
	
	C = comb(m,n,r); // 4C2
	
	printf("%lld",C); 
	return 0;
}
