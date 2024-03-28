#include <stdio.h>

int counting(int n,int c){
    int lis[10000];
    int reverse[10000];

    int a=c; //다음함수로 넘겨줄때 +3
    int remain;
    int count=0;

while(n-count>0){
    int i=0;
    int c=a; //이거 안하면 무한루프 돌음
    while(c!=0){
        remain=c%10;
        c=c/10;
        lis[i++]=remain;
        count++;
    }
    for(int j=0;j<i;j++){
        reverse[j]=lis[i-1-j];
    }
    if(n-count<=0) return reverse[n-1]; //원하는 수 찾으면 끝
    else{n=n-count; count=0; a+=3;} //재귀로하면 시간 너무 오래걸림
}
        
    
    
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d",counting(n,3));
    
}