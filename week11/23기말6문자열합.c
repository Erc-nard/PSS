#include <stdio.h>
#include <string.h> 

void pick(char*s1, char*s2,int* bucket,int bucketSize,int toPick,int *max){

    if(toPick==0){
        int st1=0,st2=0;
        for(int i=0;i<strlen(s1);i++){
            st1*=10;
            st1+=bucket[s1[i]-65];
        }
        for(int i=0;i<strlen(s2);i++){
            st2*=10;
            st2+=bucket[s2[i]-65];
        }
        if(st1+st2>*max)
            *max=st1+st2;
    }

    for(int i=1;i<6;i++){
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

    scanf("%s",s1);
    scanf("%s",s2);

    pick(s1,s2,bucket,5,5,&max);

    printf("%d",max);
}





