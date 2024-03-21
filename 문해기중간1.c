#include <stdio.h>
int ArithmeticSequence(int a[],int n){
    if(n<2) return 1; //숫자하나만있어도 수열
    int d=a[1]-a[0];
    for(int i=0;i<n-1;i++){
        if((a[i+1]-a[i])!=d) 
            return 0;
    }
    return 1;
}

int main(){
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",ArithmeticSequence(a,n));
    return 0;
}