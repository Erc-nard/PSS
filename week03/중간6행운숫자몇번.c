#include <stdio.h>
int luck(int num,int lucknum){
    int tot=0;
    while(num!=0){ // num%10!=0�����ϸ� 1���ڸ����ڰ� 0�ΰ�쿡 �������� 102������� �߰��� �ߴܵ�
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
