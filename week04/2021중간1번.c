#include <stdio.h>
int main(){
    char num1[1000];
    char num2[1000];

    int i=0,j=0,count=0;
    int carry=0;

    while((num1[i]=getchar())!='\n') {i++;} num1[i]='\0';
    while((num2[j]=getchar())!='\n') {j++;} num2[j]='\0';

 
    --i;--j;
    while(i >=0 || j>=0){
        int r1=0 ,r2=0;
        if(i>=0) {r1=(num1[i]-'0'); i--;}
        if(j>=0){r2=(num2[j]-'0');j--;}

        if(r1+r2+carry>9){ //carry
            count+=1;
            carry=(r1+r2+carry)/10;
        }
        else{
            carry=0;
        }
				
    }
    
    printf("%d\n",count);
}