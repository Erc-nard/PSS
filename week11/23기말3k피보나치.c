#include <stdio.h>
#include <stdlib.h>

long long fib(long long n,long long*F,int k){
    if (n<=k) return 1;

    long long total =0;
    for(int i=1;i<=k;i++){
        if(F[n-i]==0)
            F[n-i]=fib(n-i,F,k);
        total+=F[n-i];
    }
    return total;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    long long* F=(long long*)malloc(sizeof(long long)*n);
    for(int i=0;i<n;i++)
        F[i]=0;

    printf("%lld",fib(n,F,k));

    free(F);
}