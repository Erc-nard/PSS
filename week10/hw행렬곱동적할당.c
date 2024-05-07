#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **a, int r, int c) {
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++ ){
			printf("%4d ",a[i][j]);
		}
		printf("\n");
	}
}

void matrixmul(int **a, int **c, int **x, int ar, int ac,int cc) {
	
	for(int i=0;i<ar;i++){
		for(int j=0;j<cc;j++){
			x[i][j]=0;
			for(int h=0;h<ac;h++){
				x[i][j]+=(a[i][h]*c[h][j]);
				}
			}
		}
	printMatrix(x,ar,cc);

}

void tranposedA(int **a,int ar,int ac){
	for(int j=0;j<ac;j++){
		for(int i=0;i<ar;i++){
			printf("%4d",a[i][j]);
			}
		printf("\n");
	}
}

int main(void)
{
	int **a, **c;
	int **x; // A * c
	int aRow, aCol;
	int cRow,cCol;
	int i, j;
	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	printf("Eneter 행렬 C의 행과 열의 개수(C의 행은 %d이어야):",aCol);
	scanf("%d %d",&cRow,&cCol);
	
	a = (int**)malloc(sizeof(int*) * aRow); // r행 동적 할당
	for( i = 0; i < aRow; i++) 
		a[i] = (int*)malloc(sizeof(int) * aCol);//각 행마다 c열 할당
	c = (int**)malloc(sizeof(int*) * cRow); // r행 동적 할당
	for( i = 0; i < cRow; i++) 
		c[i] = (int*)malloc(sizeof(int) * cCol);//각 행마다 c열 할당
	x = (int**)malloc(sizeof(int*) * aRow); // r행 동적 할당
	for( i = 0; i < aRow; i++) 
		x[i] = (int*)malloc(sizeof(int) * cCol);//각 행마다 c열 할당
				
	printf("%d x %d 행렬 A 입력:\n",aRow,aCol);
	for(i = 0; i < aRow; i++)
		for( j = 0; j < aCol; j++ )
			scanf("%d",&a[i][j]);
		
	printf("%d x %d 행렬 C 입력:\n",cRow,cCol);
	for(i = 0; i < cRow; i++)
		for( j = 0; j < cCol; j++ )
			scanf("%d",&c[i][j]);		
	
	printf("행렬곱:\n");
	matrixmul(a,c,x,aRow,aCol,cCol);
	printf("전치행렬:\n");
	tranposedA(a,aRow,aCol);

	for(i = 0; i < aRow; i++)
		free(a[i]); //각 열을 반환
	free(a); // 행을 반환
	for(i = 0; i < cRow; i++)
		free(c[i]); //각 열을 반환
	free(c); // 행을 반환
	for(i=0;i<aRow;i++)
		free(x[i]);
	free(x);
}
