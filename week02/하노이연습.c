#include <stdio.h>
#include <math.h>

void hanoi(int k,int a, int b, int c){ // from mid goal
    if(k==1)
        printf("%d %d\n", a,c);
    else{
        hanoi(k-1,a,c,b); //k-1���� a���� b�� ����
        printf("%d %d\n",a,c); //a���� c�� �ű�� �˸�
        hanoi(k-1,b,a,c); //k-1���� b���� c�� ����
    }
}

int main(){
    int k;
    scanf("%d",&k);
    printf("%d\n",(int)pow(2.0,(float)(k))-1); //�ϳ���ž �� �̵�Ƚ��:2^k-1
    hanoi(k,1,2,3);
}