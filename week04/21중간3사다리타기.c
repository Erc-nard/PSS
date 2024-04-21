#include <stdio.h>

int main(){
    int n,m;
    int start;
    scanf("%d %d",&n,&m);
    scanf("%d",&start);

    char a[101][101];
    int j=0;

    for(int i=0;i<m;i++){
        scanf("%s", a[i]); //조심!!!!!!!! scanf 쓰자... 사다리 모양 받기
    }
  
    for(int i=0;i<m;i++){ //가로줄 한층씩함 숫자 커질수록 내려감
        if(start>0&&start<=(n-1)){ //1~맨끝줄일때
            if(a[i][start]=='1')
                start+=1; //내가있는곳이 1이면 오른쪽으로
     
            else if(a[i][start-1]=='1') //나 바로왼쪽이 1이면 왼쪽으로
                    start-=1;
                    //암것도 아니면 안움직이고 그냥 아래층감
        }
        else if(start==0) //0번째줄일때
            if(a[i][start]=='1') start+=1; //1이면 오른쪽으로
            //왼쪽은 못감

        // printf("%d go\n",start);
    }
    
    printf("%d",start);

}
