// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

#define PI 3.1415926535 // 円周率

long double f(long double);   //関数f(x)のプロトタイプ宣言

int main()
{

  int k; 
  int n=1; // 初期分割n=1

  long double eps=1.0e-7; // 精度
  long double err=1.0; // 誤差 err>eps

  long double a=0.0; // 積分開始点
  long double b=PI;// 積分終了点
  long double h=(b-a)/n; 
  long double se0=(f(a)+f(b))*h/6; 
  long double so0=4*f((a+b)/2)*h/6; 
  long double s,se,so; 

  printf("#n s  err\n"); // 出力タイトル
  printf("%d %.10Lf %.10Lf\n",n,se0+so0,err); // 1回目の出力

  for(n=2; eps<err; n*=2){//(your codes) //n=2からeps<errとなるま で n を二倍してループ
    h=h/2; //hの初期値
    se=se0/2+so0/4; //seの初期値
    so=0.0; //soの初期値
    for( k=0; k < n; ++k ){ //k=0からn-1までループ
      so+=4*f(a+(2*k+1)*h/2);//(your codes) //soの和の部分を計算
    }
    so*=h/6; //soにh/6をかける
    err=fabsl(so+se-so0-se0); // errの計算
    printf("%d %.10Lf %.10Lf\n",n,so+se,err); //2回目以降の出力
    se0=se; //se0にseを格納
    so0=so; //so0にsoを格納
    
  }

}

long double f(long double x)
{
  //  return(x*x); // f(x)の定義
  return(sin(x)); // f(x)の定義
}

/* 出力
#n s  err
1 2.0943951024 1.0000000000
2 2.0045597550 0.0898353474
4 2.0002691699 0.0042905850
8 2.0000165910 0.0002525789
16 2.0000010334 0.0000155577
32 2.0000000645 0.0000009688
64 2.0000000040 0.0000000605
*/