#include <stdio.h>
int main(){
    int a,c=1,count=1;
    scanf("%d",&a);
    while(c%a!=0){
        c=c*10+1;
        count++;
    }
    printf("%d",count);
}