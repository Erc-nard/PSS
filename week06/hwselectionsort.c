#include <stdio.h>
#include<stdlib.h>
#include<time.h>



struct Student
{
    int id; //학번. 1번 부터 부여 ..
    int korean, english, math;
};

void selectionSort(struct Student *A, int n) {
	int i, j, k, max,max_idx;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
	    max = A[0].korean; max_idx=0;
        for ( j = 1; j < n-i; j++) {
            if(max > A[j].korean ) {
                max = A[j].korean;
                max_idx = j;
            }
        }
        temp=A[n-1-i];
        A[n-1-i]=A[max_idx];
        A[max_idx]=temp;
    }
}


int main(){
     
	int n;
    srand(time(NULL));

	scanf("%d", &n);
    struct Student *s=(struct Student *)malloc(sizeof(struct Student)*n);

    for(int i=0;i<n;i++){
        s[i].id=i+1;
        s[i].korean=rand()%101;
        s[i].english=rand()%101;
        s[i].math=rand()%101;
        printf("%d %d %d %d\n",s[i].id,s[i].korean,s[i].english,s[i].math);
    }

    selectionSort(s,n);
    printf("\n");    
    for(int i=0;i<n;i++)
        printf("%d %d %d %d\n",s[i].id,s[i].korean,s[i].english,s[i].math);

	free(s);
}