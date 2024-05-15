#include <stdio.h>
void pick(int n,int* bucket,int bucketSize,int toPick,int L,int*total){
	
	if(toPick==0){
		int flag=0;
        for(int i=0;i<bucketSize;i++)
            if(bucket[i]%2==0) flag+=1;
        if(flag>=L) {
            /*for(int i=0;i<bucketSize;i++)
                printf("%d ",bucket[i]);
            printf("\n");*/
            *total+=1;
            }
            return;
		}

        
		for(int i=bucketSize-toPick+1;i<=n;i++){
            int flag=0;
			for(int j=0;j<bucketSize-toPick;j++){
				if(bucket[j]==i) flag=1;
				}
			if(flag==1) continue;
			if(bucketSize!=toPick&&bucket[bucketSize-toPick-1]>i)continue;
			bucket[bucketSize-toPick]=i;
			pick(n,bucket,bucketSize,toPick-1,L,total);
			}  
	}
int main()
{
	int n,m,l;
	int bucket[30];
	scanf("%d %d %d",&n,&m,&l);

    int tot=0;
	
	pick(n,bucket,m,m,l,&tot);
    printf("%d",tot);
	
}