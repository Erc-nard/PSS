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
	printf("입력:");
	scanf("%d", &num);
	char items[][10] = {"공유", "김수현", "송중기", "지성", "현빈"};
	//문자열받을때 2차원배열로 받아야함 그리고 크기는 길이의 2배정도
	int bucket[5]; //index????옣?븯湲?
	pick(items, 5, bucket, num, num);

}
