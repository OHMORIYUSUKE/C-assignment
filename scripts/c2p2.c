// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 2

double A[N][N]={{1,2},{3,4}};
double B[N][N]={{5,6},{7,8}};
double C[N][N];

int main(){
  int i,j,k;

  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      C[i][j]=0;    //Cを初期化
    }
  }

  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      for(k=0;k<N;++k){
        C[i][j] = C[i][j] + A[i][k]*B[k][j];  //A, Bの積をCに格納
      }
    }  
  }
    
  printf("A*B=\n");   
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      printf("%f ",C[i][j]); //Cのi行の各成分を出力
    }
    printf("\n");
  }
 
}

/* 出力

A*B=
19.000000 22.000000
43.000000 50.000000