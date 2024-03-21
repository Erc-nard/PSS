#include <stdio.h>
int main(){
    int a,b;
    int sum=0;
    scanf("%d %d",&a,&b);
    while(a%10!=0 && b%10!=0){
        if((a%10)+(b%10)>=10)
            sum++;
        a=a/10;
        b=b/10;
    }
    printf("%d",sum);
}