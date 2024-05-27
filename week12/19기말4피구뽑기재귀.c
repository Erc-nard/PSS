#include <stdio.h>
#include <stdlib.h>

int pick(int* student, int size, int* bucket, int bucketSize, int k,int tot)
{
	int smallest,result,last;
	int min=tot+1;
	//printf("bucketsize:%d k:%d\n",bucketSize,k);
	if (k == 0) // trivial case
	{
        int now=0;
        for(int i=0;i<bucketSize;i++){
            now+=student[bucket[i]];
            //printf("%d ",student[bucket[i]]);
        }
        //printf("%d\n",now);
		int all=tot-(now*2);

		if(all<0 ) return (-all);
		else return all;
    
	} 
	last=bucketSize-k-1;
	if(last==-1) smallest=0;
	else smallest=bucket[last]+1;
	// k > 0
	for (int i = smallest; i < size; i++)
	{
		bucket[last+1] = i;
		result =pick(student, size, bucket, bucketSize, k - 1,tot);
		if(min>result)
			min=result;
	}

	return min;
}

int main() {
	int num,min;
	int tot = 0;
	scanf("%d", &num);
	int* Student = (int*)malloc(sizeof(int) * num);
    int* bucket = (int*)malloc(sizeof(int) * (num/2));
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &Student[i]);
		tot += Student[i];
	}

	min= pick(Student, num, bucket, num/2, (num/2),tot);
	printf("%d",min);

    free(Student);
    free(bucket);
}
