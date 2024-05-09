#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int* A, int p, int r) {
    int i, j;
    int pivot;
    int t;

    i = p - 1;
    j = p;

    //t = <- random int from (p,r)
    //swap A[t] <--> A[r]
    pivot = A[r];

    for (j = p; j < r; j++) {
        if (A[j] < pivot) {
            i++;
            //swap A[i] <--> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    //swap A[i] <--> A[r] 
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}

void quick_sort(int* A, int p, int r, int num) {//if(num-q<0):????? else ???른쪽
    /*for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");*/

    if (p < r ) {
        int q = partition(A, p, r);
        //printf("뀨:%d\n", q);

        if (num - q < 0){
            //printf("왼쪽 %d %d %d\n",num,p,q-1);
            quick_sort(A, p, q - 1, num);}
        else {//printf("오른쪽 %d %d %d\n",num,q+1,r);
            quick_sort(A, q + 1, r, num - p - q - 1);
        }
        
    }

}

int main() {
    int num;
    int randomnum;
    srand(time(NULL));

    printf("Enter the number of numbers:");
    scanf("%d", &randomnum);
    printf("몇 번째로 작은 수:");
    scanf("%d", &num);

    //int test[10]={65, 64, 78, 6, 48, 43, 19, 87, 80, 6};
    int* a = (int*)malloc(sizeof(int) * randomnum);
    for (int i = 0; i < randomnum; i++) {
        a[i] = rand() % 101;
        printf("%d ", a[i]);
    }
    printf("\n");

    quick_sort(a, 0, randomnum - 1, num - 1);
    printf("%d번째 작은 수는 %d", num, a[num-1]);
    // printf("%d",a[num-1]);
    
    free(a);
}
