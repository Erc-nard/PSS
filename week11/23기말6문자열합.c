#include <stdio.h>
#include <string.h> 

void pick(char*s1, char*s2,int* bucket,int bucketSize,int toPick,int *max){

    if(toPick==0){
        int st1=0,st2=0;
        for(int i=0;i<strlen(s1);i++){
            st1*=10;
            st1+=bucket[s1[i]-65]; //문자열1 숫자 s1[i]가 A면 첫번째에 저장된거 갖다씀 ..이런식
        }
        for(int i=0;i<strlen(s2);i++){
            st2*=10;
            st2+=bucket[s2[i]-65];
        }
        if(st1+st2>*max)
            *max=st1+st2; //최대값이면 max바꿈
    }

    for(int i=1;i<6;i++){ //a가 1일때 ... 2일때 .. 3일때 이런식으로 모든경우 다돌려봄
        int flag=0;
        for(int j=0;j<bucketSize-toPick;j++)
            if(bucket[j]==i) flag=1;
        if(flag==1) continue;
        bucket[bucketSize-toPick]=i;
        pick(s1,s2,bucket,bucketSize,toPick-1,max);
    }

}
int main(){
    char s1[8];
    char s2[8];
    int bucket[5];
    int max=0;

    scanf("%s",s1); //문자열1
    scanf("%s",s2); //문자열 2

    pick(s1,s2,bucket,5,5,&max); //5개니까 걍 재귀돌려도 ㄱㅊ

    printf("%d",max);
}





