#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


struct Student
{
	int id; //�й�. 1�� ���� �ο� ..
	int korean, english, math;
};
int partition(struct Student* A, int p, int r) {
	int i, j, t;
	int pivot;
	struct Student B;
	pivot = A[r].korean;
	i = p - 1;

	for (j = p; j < r; j++) {
		if (A[j].korean > pivot) { //�̰ſ����� �����������������ٲ� >�� ��������
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
	//n �Է� ����
	//����ü �迭�� �������� �Ҵ�
	// �й� �ο�
	// random���� ���� ����
	// �л� ����(�й�, ������) ���
	
	quick_sort(s,0,n-1);
	//���� ���� �������� �������� ���� �� quick sort �Լ� ȣ��
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %d\n", s[i].id, s[i].korean, s[i].english, s[i].math);
	}
	free(s);
	// ���ĵ� �л� ����(�й�, ������) ���
	//�������� �Ҵ� ���� ����ü �迭 ��ȯ
	
}
