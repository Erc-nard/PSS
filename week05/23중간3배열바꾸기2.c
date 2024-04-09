#include <stdio.h>
#include <stdlib.h>
void sequence_check(int * seq,int sequencesize,int *check){
	int total=0,d,chec=0;
	if(sequencesize<2)*check=seq[0];
	else{
		
	d=seq[1]-seq[0];
	//printf("%d ",d);
	for(int i=0;i<sequencesize-1;i++){
		if((seq[i+1]-seq[i])!=d) chec=1;
		total+=seq[i];
	}
	total+=seq[sequencesize-1];
	//printf("%d\n",total);
	if(chec==0)*check=total;
	}

}
void pick(int *sequence, int sequencesize, int* bucket, int bucketSize, int k)
{
	int smallest;


	if (k == 0) // trivial case
	{
		
		 
	} 
	// k > 0
	int lastIndex = bucketSize - k - 1;
    if(bucketSize==k) smallest=0;
    else smallest=bucket[lastIndex]+1;

	for (int i = smallest; i < sequencesize; i++)
	{	int flag=0;
		for(int j=0;j<=lastIndex;j++)
			if(bucket[j]==i) flag=1;
		if(flag==1) continue;
		bucket[lastIndex + 1] = i;
		pick(sequence, sequencesize, bucket, bucketSize, k - 1);
	}
}

int main() {
	int a,b;
    scanf("%d",&b);
	scanf("%d", &a);
    int* items=(int*)malloc(sizeof(int)*b);
    for(int i=0;i<b;i++){
        scanf("%d",&items[i]);
    }
    
    int* sequence=(int*)malloc(sizeof(int)*b);
    for(int i=0;i<b;i++){
        scanf("%d",&sequence[i]);
    }
	
	insertion_sort(items,b);
    insertion_sort(sequence,b);

	/*for(int i=0;i<a;i++){
        printf("%d ",items[i]);
    }*/
	int check=-1;
    int* bucket=(int*)malloc(sizeof(int)*b);

	pick(sequence, b, bucket, a,a);
	printf("%d",check);

	free(items);
	free(sequence);
	free(bucket);
    
}
