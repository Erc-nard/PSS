#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *A, int p, int r) {
    int i, j;
    int pivot;
    int t;

    i = p - 1;
    j = p;
    
    //t = <- random int from (p,r)
    //swap A[t] <--> A[r]
    pivot = A[r];

    for(j=p; j<r; j++) {
        if(A[j] < pivot) {
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

void quick_sort(int *A, int p, int r,int num) { //if(num-q<0):왼쪽 else 오른쪽
    if(p<r&&num>0) {
        int q = partition(A, p, r);
        if(num-q<=0)
        	quick_sort(A, p, q-1,num);
        else
        	quick_sort(A, q+1, r,num-q);
    }
    else printf("%d",A[num]);  
}

int main(){
        int all[10];
          int num;
        srand(time(NULL));
        
        printf("Enter the number of numbers:10\n");
        printf("몇 번째로 작은 수:");
        scanf("%d",&num);
        
        for(int i=0;i<10;i++){
            all[i]=rand()%101;
            printf("%d ",all[i]);
        }
            printf("\n");
            
            quick_sort(all,0,9,num);
           // printf("%d",all[num-1]);
            
}
