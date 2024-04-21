#include <stdio.h>

void a(int n){
    if(n!=0)
        {   
        a(n/10);//앞자리수부터 출력
        printf("%d ",n%10); //뒷자리출력
    }
}
int main(){
    int n;
    scanf("%d",&n);

    n=n*9;
    a(n);
}