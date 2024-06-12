#include <stdio.h>
#include <stdlib.h>

long long comb(long long**m, int n, int r)
{
	if(r>n||r<0) return 0;
	
	if(r==0||r==n) return 1;
	
	if(m[n-1][r-1]==0)
		m[n-1][r-1]=comb(m,n-1,r-1);
	if(m[n-1][r]==0)
		m[n-1][r]=comb(m,n-1,r);

	return m[n-1][r-1]+m[n-1][r];
	
}

int main() 
{
	int n,m,l;

	long long **me=(long long**)malloc(sizeof(long long*)*40);
	for(int i=0;i<40;i++)
		me[i]=(long long*)malloc(sizeof(long long)*40);

	for (int i = 0; i <40; i++) 
        for (int j = 0; j <40; j++)
			me[i][j]=0; //메모 초기화

	scanf("%d %d %d",&n,&m,&l); //N,M,L받음

    int even=n/2; //1부터 N까지 짝수개수
    int odd=n-even; //1부터 N까지 홀수개수 

    long long tot=0;
    
    for(int i=l;i<=n-l;i++){
        long long evenum=comb(me,even,i);
        long long oddnum=comb(me,odd,m-i);
        tot+=evenum*oddnum; 
    }
    printf("%lld",tot);

	for (int i =0; i < 40; i++) 
		free(me[i]); 
	free(me); 
}