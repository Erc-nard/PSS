#include <stdio.h>
int get_cycle_number(int n){
    int tot=0;
    printf("%d ",n);
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else n=n*3+1;
        tot++;
        printf("%d ",n);
    }
    return tot;
}
int main(){
    int n;
    scanf("%d",&n);
    get_cycle_number(n);
}
