#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void isSequence(int a[], int size) {
	int n = a[0];
	int b[10000]; //일단 넣어보고 a랑 비교
	int flag = 0;


	for (int j = 0; j < size; j++) {
		b[0] = a[j];
		for (int i = 0; i < size; i++) {
			if (b[i] % 2 == 0) b[i + 1] = b[i] / 2;
			else b[i + 1] = b[i] * 3 + 1;
		}
		if (right(a, b, size) == 1) {
			for (int i = 0; i < size; i++) {
				printf("%d ", b[i]);
			}
			break;
		}
	}

}

int right(int a[],int b[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i] == b[j]) {
				break;
			}
			if (j == size - 1) {
				return 0;
			}
		}
	}
	 return 1;

}

int main(void) {
	int N;
	int a[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &a[i]);

	isSequence(a, N);
}
