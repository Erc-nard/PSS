#include <stdio.h>
#include <math.h>

void hanoi(int k,int a, int b, int c){
    if(k==1)
        printf("%d %d\n", a,c);
    else{
        hanoi(k-1,a,c,b);
        printf("%d %d\n",a,c);
        hanoi(k-1,b,a,c);
    }
}

int main(){
    int k;
    scanf("%d",&k);
    printf("%d\n",(int)pow(2.0,(float)(k))-1); 
    hanoi(k,1,2,3);
}