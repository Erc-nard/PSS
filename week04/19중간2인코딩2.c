#include <stdio.h>


int main(){
    char num[99999]; //숫자가 너무 커서 그냥 받으면 계산안됨 그냥 문자열로 받아야함
    int i=0;
    int ten, hun;
    int total=0;

    while((num[i]=getchar())!='\n') {total+=num[i]-'0';i++;} //하나씩 입력받고 받으면서 total에 저장
   //이거 그냥 scanf로 하는게 오류안날거임, -'0'으로 문자를 숫자로 바꿈
    num[i+1] = '\0';

    ten=num[i-1]-'0';

    if(i>1)
        hun = (num[i-1]-'0')+((num[i-2]-'0')*10)+((num[i-3]-'0')*100);
    else hun=(num[i-1]-'0');
    

    if(ten%2==0) printf("1"); //2의배수
    else printf("0");

    if(total%3==0) printf("1"); //3의배수
    else printf("0");

    if(hun%4==0) printf("1"); //4의배수
    else printf("0");

    if(ten%5==0) printf("1"); //5의배수
    else printf("0");

}