#include <stdio.h>

void pick(int n,int m,int picked[],int topick){ //n>최대숫자 m>list크기 topick>앞으로 골라야하는 숫자개수
    int smallest,lastindex=m-topick;

    if(topick==0){ //다고르면 조합출력
        for(int i=0;i<m;i++){
            printf("%d ",picked[i]);
        }
        printf("\n");
        return;
    }

    if(m==topick) smallest=0; //맨처음 고를때 0부터 고름
    else smallest=picked[lastindex-1]+1; //그다음 고를때 다음숫자부터 고름 lastindex에 들어있는숫자+1

    for(int i=smallest;i<n;i++){ 
        picked[lastindex]=i; //0부터 n까지 집어넣음
        pick(n,m,picked,topick-1); //골라야할개수 -1
    }
}

int main(){
    int picked[4];
    pick(7,4,picked,4);
    return 0; 
}
