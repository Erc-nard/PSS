#include <stdio.h>
#include <stdlib.h>

long long fib(long long n,long long*F){ //long long
    if (n==1||n==2||n==3) return 1;
    if(F[n-1]==0)
        F[n-1]=fib(n-1,F);
    if(F[n-2]==0)
        F[n-2]=fib(n-2,F);
    if(F[n-3]==0)
        F[n-3]=fib(n-3,F);
    return (F[n-1]+F[n-2]+F[n-3]);
}

int main(){
    int n;
    scanf("%d",&n);
    long long* F=(long long*)malloc(sizeof(long long)*n);
    for(int i=0;i<n;i++)
        F[i]=0;

    printf("%lld",fib(n,F));

    free(F);
}