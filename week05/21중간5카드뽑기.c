#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemsize, int* bucket, int bucketSize, int k,int *count)
{

	if (k == 0) // trivial case
	{
		int remain=0;
		int flag2=0;
		for(int i=0;i<itemsize;i++){
			flag2=0;
			for(int j=0;j<bucketSize;j++){
				if(bucket[j]==i){
					flag2=1;
					break;
				}
			}
			if(flag2==0) {remain=items[i];break;}
		}
		//printf("remain: %d. ",remain);

		int total=0;
		for (int j = 0; j < bucketSize; j++) {
			//printf("%d ", items[bucket[j]]);
			total=total*10+items[bucket[j]];
		}
		//printf("%d\n",total);
		if((total%remain)==0)(*count)++;
		//printf("\n");


	} 
	// k > 0
	int lastIndex = bucketSize - k - 1;

	for (int i = 0; i < itemsize; i++)
	{	int flag=0;
		for(int j=0;j<=lastIndex;j++)
			if(bucket[j]==i) flag=1; //중복 거르기
		if(flag==1) continue;
		bucket[lastIndex + 1] = i;
		pick(items, itemsize, bucket, bucketSize, k - 1,count);
	}
}

int main() {
	int num;
	int count=0;
	scanf("%d", &num);
	int* items = (int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d",&items[i]);
    }
	int* bucket = (int*)malloc(sizeof(int)*num);
	pick(items, num, bucket, num-1, num-1,&count);
	printf("%d",count);

	free(items);
	free(bucket);

}
