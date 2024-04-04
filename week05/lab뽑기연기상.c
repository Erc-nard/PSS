#include <stdio.h>

void pick(char items[][10], int itemsize, int* bucket, int bucketSize, int k)
{
	int smallest;

	if (k == 0) // trivial case
	{
		for (int j = 0; j < bucketSize; j++) {
			printf("%7s ", items[bucket[j]]);
		}
		printf("\n");
	

	} 
	// k > 0
	int lastIndex = bucketSize - k - 1;

	for (int i = 0; i < itemsize; i++)
	{	int flag=0;
		for(int j=0;j<=lastIndex;j++)
			if(bucket[j]==i) flag=1;
		if(flag==1) continue;
		bucket[lastIndex + 1] = i;
		pick(items, 5, bucket, bucketSize, k - 1);
	}
}

int main() {
	int num;
	printf("ÀÔ·Â:");
	scanf("%d", &num);
	char items[][10] = {"°øÀ¯", "±è¼öÇö", "¼ÛÁß±â", "Áö¼º", "Çöºó"};
	int bucket[5]; //index????ž¥?•˜ê¸?
	pick(items, 5, bucket, num, num);

}
