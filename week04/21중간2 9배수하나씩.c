#include <stdio.h>

void a(int n){
    if(n!=0)
        {   
        a(n/10);//���ڸ������� ���
        printf("%d ",n%10); //���ڸ����
    }
}
int main(){
    int n;
    scanf("%d",&n);

    n=n*9;
    a(n);
}