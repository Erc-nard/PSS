#include <stdio.h>

int main(){
    int n,m;
    int start;
    scanf("%d %d",&n,&m);
    scanf("%d",&start);

    getchar();

    int a[100][100];
    int j=0;

    for(int i=0;i<m;i++){
        j=0;
        while((a[i][j]=getchar())!='\n') {j++;}
        a[i][j]='\0';
    }
  
    for(int i=0;i<m;i++){
        if(start>0&&start<(n-1)){
            if(a[i][start]=='1')
                start+=1;
     
            else if(a[i][start-1]=='1')
                    start-=1;
            continue;
        }
        if(start==0){
            if(a[i][start]=='1') start+=1; continue;}
        if(start==(n-1)){
            if(a[i][start-1]=='1')start-=1;
        }
        //printf("%d go\n",start);
    }
    
    printf("%d",start);

}
