#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,NONZERO=0;
    int Sparse[6][6]={ 15,0,0,22,0,-15,0,11,3,0,0,0,0,0,0,-6,0,0,0,0,0,0,0,0,91,0,0,0,0,0,0,0,28,0,0,0 };
    int Compress[9][3];
    int tmp = 1;
    for(i = 0 ; i < 6 ; ++i){
        for(j = 0 ; j < 6 ; ++j){
            printf("[%d]\t",Sparse[i][j]);
            if(Sparse[i][j] != 0) NONZERO++;
        }
        printf("\n");
    }
    Compress[0][0] = 6;
    Compress[0][1] = 6;
    Compress[0][2] = NONZERO;
    for(i = 0 ; i<6 ; ++i){
        for ( j= 0 ; j <6 ; ++j){
            if(Sparse[i][j] != 0){
                Compress[tmp][0] = i;
                Compress[tmp][1] = j;
                Compress[tmp][2] = Sparse[i][j];
                tmp++;
            }
        }
    }
    for(i = 0 ; i <= NONZERO ; ++i){
        for(j = 0 ; j < 3 ; ++j){
            printf("[%d]\t",Compress[i][j]);
        }
        printf("\n");
    }
}