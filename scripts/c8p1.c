// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

double f(double);   //関数f(x)のプロトタイプ宣言

int main()
{
  int k,n;
  double x,s,err;
  double a,b,h;

  a=0.0; // 積分の開始点
  b=1.0; // 積分の終了点
  n=10; // 分割数
  h=(b-a)/n; // h の値
  
  s=(f(a)+f(b))*h/2; // sの初期値を(f(a)+f(b))*h/2とする
  for( k=1; k < n; ++k){
    s = s + f(a+k*h)*h;//(your code) // k=1...n-1でsにf(a+kh)*hを加える
  }
  err = (double)1/(n*n);//(your code) // 誤差の定義
  
  printf("s=%f, n=%d, err=%f\n", s, n, err); // 結果出力
  
}


double f(double x)
{
  return(x*x); // 関数の定義
}

/* 出力
s=0.335000, n=10, err=0.010000
*/