#include <stdio.h>
int main(){
    int a,b;
    int sum=0;
    int carry=0;
    scanf("%d %d",&a,&b);
    while(a!=0 || b!=0){ //이부분조심
        if((a%10)+(b%10)+carry>=10){
            carry=((a%10)+(b%10)+carry)/10; //carry 신경쓰기
            sum++;
        }
        a=a/10;
        b=b/10;
    }
    printf("%d",sum);
}