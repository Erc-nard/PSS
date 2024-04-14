#include <stdio.h>
#include<stdlib.h>
#include<time.h>



struct Student
{
    int id; //학번. 1번 부터 부여 ..
    int korean, english, math;
};

void bubbleSortDescendingByKorean(struct Student *A, int n){
    int j;
     struct Student temp;
    for (int i = 0; i < n-1; i++) { // n-1 반복
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].korean < A[j+1].korean ) {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        } 
    }
}


void bubbleSortAscendingById(struct Student *A, int n){
    int j;
     struct Student temp;
    for (int i = 0; i < n-1; i++) { // n-1 반복
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].id > A[j+1].id ) {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        } 
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

    bubbleSortDescendingByKorean(s,n);
    printf("\n");    
    for(int i=0;i<n;i++)
        printf("%d %d %d %d\n",s[i].id,s[i].korean,s[i].english,s[i].math);
    
    bubbleSortAscendingById(s,n);
    printf("\n");    
    for(int i=0;i<n;i++)
        printf("%d %d %d %d\n",s[i].id,s[i].korean,s[i].english,s[i].math);

	free(s);
}