// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2

double u[N]={1,2}; // u[0]=1; u[1]=2;
double v[N]={3,4}; // v[0]=3; v[1]=4;

int main(){
  int i;
  double p=0;
    
  for(i=0;i<N;++i){     
    p = p + u[i] * v[i]; //uとvの内積を変数pに格納
  }
  printf("u*v=\n%f\n",p);
}

/* 出力

u*v=
11.000000
