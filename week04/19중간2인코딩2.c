#include <stdio.h>


int main(){
    char num[99999]; //���ڰ� �ʹ� Ŀ�� �׳� ������ ���ȵ� �׳� ���ڿ��� �޾ƾ���
    int i=0;
    int ten, hun;
    int total=0;

    while((num[i]=getchar())!='\n') {total+=num[i]-'0';i++;} //�ϳ��� �Է¹ް� �����鼭 total�� ����
   //�̰� �׳� scanf�� �ϴ°� �����ȳ�����, -'0'���� ���ڸ� ���ڷ� �ٲ�
    num[i+1] = '\0';

    ten=num[i-1]-'0';

    if(i>1)
        hun = (num[i-1]-'0')+((num[i-2]-'0')*10)+((num[i-3]-'0')*100);
    else hun=(num[i-1]-'0');
    

    if(ten%2==0) printf("1"); //2�ǹ��
    else printf("0");

    if(total%3==0) printf("1"); //3�ǹ��
    else printf("0");

    if(hun%4==0) printf("1"); //4�ǹ��
    else printf("0");

    if(ten%5==0) printf("1"); //5�ǹ��
    else printf("0");

}