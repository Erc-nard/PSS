#include <stdio.h>
int main(){
    int a,b;
    int sum=0;
    int carry=0;
    scanf("%d %d",&a,&b);
    while(a!=0 || b!=0){ //�̺κ�����
        if((a%10)+(b%10)+carry>=10){
            carry=((a%10)+(b%10)+carry)/10; //carry �Ű澲��
            sum++;
        }
        a=a/10;
        b=b/10;
    }
    printf("%d",sum);
}