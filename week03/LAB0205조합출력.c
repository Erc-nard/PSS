#include <stdio.h>

void pick(int n,int m,int picked[],int topick){ //n>�ִ���� m>listũ�� topick>������ �����ϴ� ���ڰ���
    int smallest,lastindex=m-topick;

    if(topick==0){ //�ٰ��� �������
        for(int i=0;i<m;i++){
            printf("%d ",picked[i]);
        }
        printf("\n");
        return;
    }

    if(m==topick) smallest=0; //��ó�� ���� 0���� ��
    else smallest=picked[lastindex-1]+1; //�״��� ���� �������ں��� �� lastindex�� ����ִ¼���+1

    for(int i=smallest;i<n;i++){ 
        picked[lastindex]=i; //0���� n���� �������
        pick(n,m,picked,topick-1); //�����Ұ��� -1
    }
}

int main(){
    int picked[4];
    pick(7,4,picked,4);
    return 0; 
}
