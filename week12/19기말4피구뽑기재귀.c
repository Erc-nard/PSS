#include <stdio.h>
#include <stdlib.h>

int pick(int* student, int size, int* bucket, int bucketSize, int k,int tot)
{
	int smallest,result,last;
	int min=tot+1; 
	if (k == 0) // trivial case
	{
        int now=0;
        for(int i=0;i<bucketSize;i++){
            now+=student[bucket[i]];
        }
		int all=tot-(now*2); //능력치차이 return 

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
		if(min>result) //최소값보다 작으면 최소값 바꾸기
			min=result; //min값 int i때마다 바뀌거나 안바뀌거나 ...
	}

	return min; //최소값 리턴
}

int main() {
	int num,min;
	int tot = 0;
	scanf("%d", &num);
	int* Student = (int*)malloc(sizeof(int) * num);
    int* bucket = (int*)malloc(sizeof(int) * (num/2)); //절반으로 둘 차이구할수잇음 (전체-(고른팀능력치합*2))하면됨
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &Student[i]);
		tot += Student[i];
	}

	min= pick(Student, num, bucket, num/2, (num/2),tot);
	printf("%d",min);

    free(Student);
    free(bucket);
}
