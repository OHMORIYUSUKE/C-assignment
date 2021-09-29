// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3

double A[N][N]={{1,2,3},{4,5,6},{7,8,9}};
double C[N][N]={{0,1,0},{1,0,0},{0,0,1}};
double X[N][N];

int main(){
  int i,j,k;
  
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      X[i][j]=0;    //Xを初期化
    }
  }

  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      for(k=0;k<N;++k){
        X[i][j] = X[i][j] + C[i][k]*A[k][j];//(your code)  //C, Aの積をXに格納
      }
    }  
  }

  printf("A=\n");   
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
       printf("%f ",A[i][j]);//(your code)  //Aのi行の各成分を出力
    }
    printf("\n");
  }

  printf("C=\n");   
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      printf("%f ",C[i][j]);//(your code) //Cのi行の各成分を出力
    }
    printf("\n");
  }
  
  printf("C*A=\n");   
  for(i=0;i<N;++i){
    for(j=0;j<N;++j){
      printf("%f ",X[i][j]);//(your code)  //Xのi行の各成分を出力
    }
    printf("\n");
  }
 
}

/* 出力

A=
1.000000 2.000000 3.000000
4.000000 5.000000 6.000000
7.000000 8.000000 9.000000
C=
0.000000 1.000000 0.000000
1.000000 0.000000 0.000000
0.000000 0.000000 1.000000
C*A=
4.000000 5.000000 6.000000
1.000000 2.000000 3.000000
7.000000 8.000000 9.000000