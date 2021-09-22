// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 2

double u[N];
double v[N]={1,2};
double A[N][N]={{3,4},{4,5}};

int main(){
  int i,j;
  double p=0;

  //まずu=Av を求める
   for(i=0;i<N;++i){
    u[i]=0;
    for(j=0;j<N;++j){
      u[i]=u[i] + A[i][j]*v[j]; //u[i] にA[i][j]v[j] を加える
    }
  }

  //次に内積u*v を求める
  p=0;
  for(i=0;i<N;++i){
    p=p + u[i]*v[i]; //p にu[i]v[i] を加える
  } 
  
  printf("v*Av=\n%f\n",p);
  
}

/* 出力

v*Av=
39.000000