#include <stdio.h>

int counting(int n,int c){ //n:���° c:3x1=3�̴ϱ� 3���� ����
    int lis[10000];
    int reverse[10000];

    int a=c; //�����Լ��� �Ѱ��ٶ� +3
    int remain; //������
    int count=0;

while(n-count>0){
    int i=0;
    int c=a; //�̰� ���ϸ� ���ѷ��� ����
    while(c!=0){
        remain=c%10;
        c=c/10; //c�� �ڸ����� 2�̻��� ��� 1�� �ڸ����� �ϳ��ϳ� ������ ����Ʈ�� ����
        lis[i++]=remain;
        count++; //c �ڸ��� ����
    }
    for(int j=0;j<i;j++){
        reverse[j]=lis[i-1-j]; //���� �ڸ��� ������ ���� reverse��
    }
    if(n-count<=0) return reverse[n-1]; //���ϴ� ��° �� ã���� return
    else{n=n-count; count=0; a+=3;} //��ͷ��ϸ� �ð� �ʹ� �����ɸ�
    //��ã������ n���� �̹� �������� c�� �ڸ���������ŭ ���� count �ʱ�ȭ
    //a�� 3���ؼ� ���� 3�ǹ������ ã��
}
        
    
    
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d",counting(n,3));
    
}