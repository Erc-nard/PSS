#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int*A, int n){
    int j,temp;

    for (int i = 0; i < n-1; i++) { 
        for ( j = 0; j < n-1-i; j++) {
            if( A[j] < A[j+1] ) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
            }
        } 
    }
}

int main(void)
{

	int num,min=100000;
	int tot = 0;
	scanf("%d", &num);
	int* Student = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &Student[i]);
		tot += Student[i];
	}
	bubbleSort(Student, num);

    int group1=0,group2=0;
    group1+=Student[0];
    int one=1,two=0;
    int i=1;
    while(i<num){
        if(two>=num/2) break;
        if(one>=num/2) break;
        if(group1>group2){
            group2+=Student[i++];
            two++;
        }
        else if(group1<=group2&&one<num/2){
            group1+=Student[i++];
            one++;
        }
    }

    while(two<num/2){
        group2+=Student[i++];
        two++;
    }
    while(one<num/2){
        group1+=Student[i++];
        one++;
    }
    if(group1>group2)
        printf("%d",group1-group2);
    else
        printf("%d",group2-group1);
	free(Student);

    //시간초과남...
}
