#include <stdio.h>

int counting(int n,int c){ //n:몇번째 c:3x1=3이니까 3부터 시작
    int lis[10000];
    int reverse[10000];

    int a=c; //다음함수로 넘겨줄때 +3
    int remain; //나머지
    int count=0;

while(n-count>0){
    int i=0;
    int c=a; //이거 안하면 무한루프 돌음
    while(c!=0){
        remain=c%10;
        c=c/10; //c의 자리수가 2이상인 경우 1의 자리부터 하나하나 나눠서 리스트에 넣음
        lis[i++]=remain;
        count++; //c 자리수 세기
    }
    for(int j=0;j<i;j++){
        reverse[j]=lis[i-1-j]; //높은 자리수 앞으로 오게 reverse함
    }
    if(n-count<=0) return reverse[n-1]; //원하는 번째 수 찾으면 return
    else{n=n-count; count=0; a+=3;} //재귀로하면 시간 너무 오래걸림
    //못찾았으면 n에서 이번 루프에서 c의 자리수개수만큼 빼고 count 초기화
    //a에 3더해서 다음 3의배수에서 찾음
}
        
    
    
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d",counting(n,3));
    
}