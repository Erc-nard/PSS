#include <stdio.h>
#include <string.h>

int main(){
    char num1[1000];
    char num2[1000]; //�ʹ�ũ�� ���ڿ��� �޾ƾ���

    int i=0,j=0,count=0;
    int carry=0;

    scanf("%s",num1); //scanf�� �ޱ�!!!!!!!!
    scanf("%s",num2);

    i=strlen(num1);
    j=strlen(num2);

 
    --i;--j; // \n�����ϱ� �װ� ����

    while(i >=0 || j>=0){
        int r1=0 ,r2=0;
        if(i>=0) {r1=(num1[i]-'0'); i--;} //���̰� 0�� �ƴϸ� �ǵ��ڸ� r1�� ����
        if(j>=0){r2=(num2[j]-'0');j--;}

        if(r1+r2+carry>9){ //carry�� �ֵ���...
            count+=1;//carry count
            carry=(r1+r2+carry)/10; //�� 1�εֵ� ��
        }
        else{
            carry=0;
        }
				
    }
    
    printf("%d\n",count);
}