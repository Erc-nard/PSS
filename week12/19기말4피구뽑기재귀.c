#include <stdio.h>
#include <stdlib.h>
void pick(int* student, int size, int* bucket, int bucketSize, int k,int tot,int*min)
{
	int smallest;

	if (k == 0) // trivial case
	{
        int now=0;
        for(int i=0;i<bucketSize;i++){
            now+=student[bucket[i]];
            //printf("%d ",student[bucket[i]]);
        }
        //printf("%d\n",now);
        if(tot-now*2>0){
            if(*min>tot-now*2) *min=tot-now*2;
        }
        else
            if(*min>now*2-tot) *min=now*2-tot;
	} 
	// k > 0
	for (int i = 0; i < size; i++)
	{	int flag=0;
		for(int j=0;j<=bucketSize-k;j++)
			if(bucket[j]==i) flag=1;
		if(flag==1) continue;
		bucket[bucketSize-k] = i;
		pick(student, size, bucket, bucketSize, k - 1,tot,min);
	}
}

int main() {
	int num,min=100000;
	int tot = 0;
	scanf("%d", &num);
	int* Student = (int*)malloc(sizeof(int) * num);
    int* bucket = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &Student[i]);
		tot += Student[i];
	}
	pick(Student, num, bucket, num/2, num/2,tot,&min);
    printf("%d",min);
    free(Student);
    free(bucket);
}
