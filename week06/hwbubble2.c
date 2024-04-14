#include <stdio.h>
#include<stdlib.h>
#include<time.h>



struct Student
{
    int id; //?•™ë²?. 1ë²? ë¶??„° ë¶??—¬ ..
    int korean, english, math;
};

void bubbleSortDescendingByKorean(struct Student *A, int n){
    int j;

    for (int i = 0; i < n-1; i++) { // n-1 ë°˜ë³µ
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].korean < A[j+1].korean ) {
                swap(A,j);
            }
        } 
    }
}
void bubbleSortDescendingBymath(struct Student *A, int n){
    int j;

    for (int i = 0; i < n-1; i++) { // n-1 ë°˜ë³µ
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].math < A[j+1].math ) {
                swap(A,j);
            }
        } 
    }
}
void bubbleSortDescendingByeng(struct Student *A, int n){
    int j;
     
    for (int i = 0; i < n-1; i++) { // n-1 ë°˜ë³µ
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].english < A[j+1].english ) {
                swap(A,j);
            }
        } 
    }
}




void bubbleSortAscendingById(struct Student *A, int n){
    int j;

    for (int i = 0; i < n-1; i++) { // n-1 ë°˜ë³µ
        for ( j = 0; j < n-1-i; j++) {
            if( A[j].id > A[j+1].id ) {
                swap(A,j);
            }
        } 
    }
}

void swap(struct Student *A, int j){
    struct Student temp;
    temp=A[j];
    A[j]=A[j+1];
    A[j+1]=temp;
}

int main(){
     
	int n;
    int end=1;
    srand(time(NULL));

    printf("ÇÐ»ý ¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä:");
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
            printf("ÇÐ¹ø:%d ¿µ¾î:%d ¼öÇÐ:%d ±¹¾î:%d\n",s[i].id,s[i].english,s[i].math,s[i].korean);

        printf("Á¤·Ä ±âÁØ ¼±ÅÃ(1:±¹¾î, 2:¼öÇÐ, 3:¿µ¾î, 4:id(¿À¸§Â÷¼ø), 0:³¡³»±â):");
        scanf("%d",&end);
        if(end==0) break;
        else if(end==1)
            bubbleSortDescendingByKorean(s,n);
        else if(end==2)
            bubbleSortDescendingBymath(s,n);
        else if(end==3)
            bubbleSortDescendingByeng(s,n);
        else
         bubbleSortAscendingById(s,n);
    }
	free(s);
}