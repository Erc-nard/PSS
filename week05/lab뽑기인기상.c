
#include <stdio.h>

void pick(char* items, int itemsize, int* bucket, int bucketSize, int k)
{
	int smallest;

	if (k == 0) // trivial case
	{
		//적당한 일
		for (int j = 0; j < bucketSize; j++) {
			printf("%c", items[bucket[j]]);
		}
		printf("\n");
	

	}
	// k > 0
	int lastIndex = bucketSize - k - 1;
	if (bucketSize == k) smallest = 0;
	else smallest = bucket[lastIndex] + 1;

	for (int i = smallest; i < itemsize; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(items, 7, bucket, bucketSize, k - 1);
	}
}

int main() {
	int num;
	printf("인기상 몇명?:");
	scanf_s("%d", &num);
	char items[][10] = {"공유", "김수현", "송중기", "지성", "현빈"};
	int bucket[5]; //index저장하기
	pick(items, 5, bucket, num, num);

}
