#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


struct Student
{
	int id; //학번. 1번 부터 부여 ..
	int korean, english, math;
};
int partition(struct Student* A, int p, int r) {
	int i, j, t;
	int pivot;
	struct Student B;
	pivot = A[r].korean;
	i = p - 1;

	for (j = p; j < r; j++) {
		if (A[j].korean > pivot) { //이거에따라 오름차순내림차순바뀜 >면 내림차순
			i++;
			//swap A[i] <-> A[j]
			B = A[i];
			A[i] = A[j];
			A[j] = B;
		}
	}

	i++;
	//swap A[i] <-> A[r]
	B = A[i];
	A[i] = A[r];
	A[r] = B;

	return i;
}

void quick_sort(int* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}
int main()
{
	int n;
	srand(time(NULL));

	scanf("%d", &n);
	struct Student* s = (struct Student*)malloc(sizeof(struct Student) * n);

	for (int i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
		printf("%d %d %d %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}
	//n 입력 받음
	//구조체 배열을 동적으로 할당
	// 학번 부여
	// random으로 성적 저장
	// 학생 정보(학번, 성적들) 출력
	
	quick_sort(s,0,n-1);
	//국어 성적 기준으로 내림차순 정렬 → quick sort 함수 호출
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}
	free(s);
	// 정렬된 학생 정보(학번, 성적들) 출력
	//동적으로 할당 받은 구조체 배열 반환
	
}
