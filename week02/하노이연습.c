#include <stdio.h>
#include <math.h>

void hanoi(int k,int a, int b, int c){ // from mid goal
    if(k==1)
        printf("%d %d\n", a,c);
    else{
        hanoi(k-1,a,c,b); //k-1개를 a에서 b로 보냄
        printf("%d %d\n",a,c); //a에서 c로 옮긴거 알림
        hanoi(k-1,b,a,c); //k-1개를 b에서 c로 보냄
    }
}

int main(){
    int k;
    scanf("%d",&k);
    printf("%d\n",(int)pow(2.0,(float)(k))-1); //하노이탑 총 이동횟수:2^k-1
    hanoi(k,1,2,3);
}