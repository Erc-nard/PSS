#include <stdio.h>
#include <string.h>

int main(){
    char num1[1000];
    char num2[1000]; //너무크면 문자열로 받아야함

    int i=0,j=0,count=0;
    int carry=0;

    scanf("%s",num1); //scanf로 받기!!!!!!!!
    scanf("%s",num2);

    i=strlen(num1);
    j=strlen(num2);

 
    --i;--j; // \n잇으니까 그건 제외

    while(i >=0 || j>=0){
        int r1=0 ,r2=0;
        if(i>=0) {r1=(num1[i]-'0'); i--;} //길이가 0이 아니면 맨뒤자리 r1에 저장
        if(j>=0){r2=(num2[j]-'0');j--;}

        if(r1+r2+carry>9){ //carry가 있따면...
            count+=1;//carry count
            carry=(r1+r2+carry)/10; //걍 1로둬도 됨
        }
        else{
            carry=0;
        }
				
    }
    
    printf("%d\n",count);
}