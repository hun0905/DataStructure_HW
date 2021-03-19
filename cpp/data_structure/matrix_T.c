#include<stdio.h>
#include<stdlib.h>

int main(){
    int M,N;
    int *A,*B,*C;
    printf("輸入矩陣的維度\n");
    scanf("%d %d",&M,&N);
    A =(int*)malloc(M*N*sizeof(int));
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            printf("a%d%d=",i,j);
            scanf("%d",&A[i*N+j]);
        }
    }
    B =(int*)malloc(M*N*sizeof(int));
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            B[i*N+j] = A[j*N+i];
            printf("%d ",B[i*N+j]);
        }
        printf("\n");
    }
}
