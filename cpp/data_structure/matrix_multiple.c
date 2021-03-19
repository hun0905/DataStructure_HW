#include<stdio.h>
#include<stdlib.h>
void matrix_multiple();
int main(){
    int M,N,O,P;
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
    printf("輸入矩陣的維度\n");
    scanf("%d %d",&O,&P);
    B =(int*)malloc(O*P*sizeof(int));
    for(int i = 0 ; i < O ; ++i){
        for(int j = 0 ; j < P ; ++j){
            printf("a%d%d=",i,j);
            scanf("%d",&B[i*P+j]);
        }
    }
    C =(int*)malloc(M*P*sizeof(int));
    matrix_multiple(A,B,C,M,N,O,P);
}
void matrix_multiple(int *a , int *b ,int *c , int M , int N , int O , int P){
    if(N != O){
        printf("error");
        return ;
    }
    int tmp;
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < P ; ++j){
            tmp = 0;
            for(int k = 0 ; k < N ; ++k){
                tmp += a[k+i*N] * b[k*O+j];
            }
            c[i*P+j] = tmp;
            printf("%d ",c[i*P+j]);
        }
        printf("\n");
    }
}