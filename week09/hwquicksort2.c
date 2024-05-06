#include <stdio.h>
#include<stdlib.h>
#include<time.h>



struct Student
{
    int id; //?????. 1?? ????? ????? ..
    int korean, english, math;
};

int partition(struct Student* A, int p, int r,int subject) {
	int i, j, t;
	int pivot;
	struct Student B;
    i = p - 1;
    if(subject==1){ //korean
        pivot = A[r].korean;
        

        for (j = p; j < r; j++) {
            if (A[j].korean > pivot) {
                i++;
                //swap A[i] <-> A[r]
                swap(A,i,j);
            }
        }
    }
    else if(subject==2){ //math
            pivot = A[r].math;
        

        for (j = p; j < r; j++) {
            if (A[j].math > pivot) {
                i++;
                //swap A[i] <-> A[r]
                swap(A,i,j);
            }
        }
    }

    else if(subject==3){ //eng
        pivot = A[r].english;
	

        for (j = p; j < r; j++) {
            if (A[j].english > pivot) {
                i++;
                //swap A[i] <-> A[r]
                swap(A,i,j);
            }
        }
    }
    else if(subject==4){ //id
        pivot = A[r].id;
	

        for (j = p; j < r; j++) {
            if (A[j].id < pivot) {
                i++;
                //swap A[i] <-> A[r]
                swap(A,i,j);
            }
        }
    }
    i++;
    swap(A,i,r);
    return i;
}

void quick_sort(int* A, int p, int r,int subject) {
	if (p < r) {
		int q = partition(A, p, r,subject);
		quick_sort(A, p, q - 1,subject);
		quick_sort(A, q + 1, r,subject);
	}
}



void swap(struct Student *A,int i,int j){
    struct Student temp;
        temp = A[i];
		A[i] = A[j];
		A[j] = temp;
}

int main(){
    
	int n;
    int end=1;
    srand(time(NULL));

    printf("학생 수를 입력하세요:");
	scanf("%d", &n);
    struct Student *s=(struct Student *)malloc(sizeof(struct Student)*n);

    for(int i=0;i<n;i++){
        s[i].id=i+1;
        s[i].korean=rand()%101;
        s[i].english=rand()%101;
        s[i].math=rand()%101;
    }
    
    while(end!=0){
        for(int i=0;i<n;i++)
            printf("학번:%d 영어:%d 수학:%d 국어:%d\n",s[i].id,s[i].english,s[i].math,s[i].korean);

        printf("\n정렬 기준 선택(1:국어 2:수학, 3:영어, 4:id(오름차순), 0:끝내기):");
        scanf("%d",&end);
        if(end==0) break;
        else if(end==1)
            quick_sort(s,0,n-1,1);
        else if(end==2)
            quick_sort(s,0,n-1,2);
        else if(end==3)
            quick_sort(s,0,n-1,3);
        else
            quick_sort(s,0,n-1,4);
    }
	free(s);
}