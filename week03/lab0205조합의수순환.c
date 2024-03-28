#include <stdio.h>
int comb(int n, int r){
    if(r==0 || r==n) return 1;
    else{
        return n*comb(n-1,r-1)/r;
    }
}

int main(){
    int c10_5;
    c10_5=comb(10,5);
    printf("%d ",c10_5);
    return 0;
}
