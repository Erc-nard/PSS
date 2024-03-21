#include <stdio.h>
int get_cycle_number(int n){
    printf("%d ",n);
    if(n==1) return 1;
    else{
        if(n%2==0) return get_cycle_number(n/2);
        else return get_cycle_number(n*3+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    get_cycle_number(n);
}