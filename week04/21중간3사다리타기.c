#include <stdio.h>

int main(){
    int n,m;
    int start;
    scanf("%d %d",&n,&m);
    scanf("%d",&start);

    char a[101][101];
    int j=0;

    for(int i=0;i<m;i++){
        scanf("%s", a[i]);
    }
  
    for(int i=0;i<m;i++){
        if(start>0&&start<=(n-1)){
            if(a[i][start]=='1')
                start+=1;
     
            else if(a[i][start-1]=='1')
                    start-=1;
        }
        else if(start==0)
            if(a[i][start]=='1') start+=1;

        // printf("%d go\n",start);
    }
    
    printf("%d",start);

}
