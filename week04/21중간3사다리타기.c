#include <stdio.h>

int main(){
    int n,m;
    int start;
    scanf("%d %d",&n,&m);
    scanf("%d",&start);

    char a[101][101];
    int j=0;

    for(int i=0;i<m;i++){
        scanf("%s", a[i]); //����!!!!!!!! scanf ����... ��ٸ� ��� �ޱ�
    }
  
    for(int i=0;i<m;i++){ //������ �������� ���� Ŀ������ ������
        if(start>0&&start<=(n-1)){ //1~�ǳ����϶�
            if(a[i][start]=='1')
                start+=1; //�����ִ°��� 1�̸� ����������
     
            else if(a[i][start-1]=='1') //�� �ٷο����� 1�̸� ��������
                    start-=1;
                    //�ϰ͵� �ƴϸ� �ȿ����̰� �׳� �Ʒ�����
        }
        else if(start==0) //0��°���϶�
            if(a[i][start]=='1') start+=1; //1�̸� ����������
            //������ ����

        // printf("%d go\n",start);
    }
    
    printf("%d",start);

}
