#include <stdio.h>
int luck(int num,int lucknum){
    int tot=0;
    while(num!=0){ // num%10!=0으로하면 1의자리숫자가 0인경우에 오류가남 102같은경우 중간에 중단됨
        if(num%10==lucknum) tot++;
        num=num/10;
    }
    return tot;
}

int main(){
    int n,k,a[1000];
    int sum=0;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=luck(a[i],k);
    }
    printf("%d",sum);
}
