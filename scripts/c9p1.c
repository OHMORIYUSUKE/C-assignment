// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

double f(double);   //関数f(x)のプロトタイプ宣言

int main()
{
  int k,n;
  long double x,s,s0,err,eps;
  long double a,b,h;
  
  a=0.0; // 積分開始点
  b=1.0; // 積分終了点
  eps=1.0e-7; // 精度
  err=1 ;     // 誤差 err>eps
  n=1;   // 初期分割n=1
  h=(b-a)/n;  // 初期h=b-a
  s0=(f(a)+f(b))*h/2; // sの初期値s0

  printf("#n s  err\n"); // 出力タイトル
  printf("%d %.10Lf %.10Lf\n", n, s, err); // 1回目の出力

  while(err>eps){ // 誤差err がeps よりも大きい間ループ
    ++n;        // n を1 増やす
    h=(b-a)/n;  // h を再計算
    s=(f(a)+f(b))*h/2; // まずs=(f(a)+f(b))*h/2 とする
    for( k=1; k < n; ++k){ // 与えられたn までループ
      s+=f(a+k*h)*h; // 与えられたn までs を計算
    }
    err=fabsl(s-s0); // s0 とs との差の絶対値をerr とする
    printf("%d %.10Lf %.10Lf\n", n, s, err); // 結果を小数点以下10 桁まで出力
    s0=s; // 次のs0 の値は現在のs の値
  }

}

double f(double x)
{
  return(x*x); // f(x)の定義
}
