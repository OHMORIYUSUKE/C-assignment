// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

double f(double);    //関数f(x)のプロトタイプ宣言
double df(double);   //関数f(x)の導関数のプロトタイプ宣言

double x=5.0,y=0.0; // 初期値x=5, y=0とする
double eps=1.0e-6;  // 精度eps=0.000001とする
double err=1.0;     // 誤差の初期値err=1.0とする

int main(){
  printf("x=            err=\n");  //xとerrのラベル表示
  while(err>eps){ // err>epsの間繰り返し
     y = x-f(x)/df(x);//(your codes) // yをx-f(x)/f'(x)に更新
     err = fabs(y-x);//(your codes)  // errを|y-x|に更新
     x=y;            // xをyに更新
     printf("%.10f, %.10f\n",x,err);  //xとerrを出力     
   }
}


//関数f(x)の定義
double f( double x )
{
  return(x*x*x-2.0);   
}

//関数f(x)の導関数f'(x)の定義
double df(double x )
{
  return(3.0*x*x);   
}

/* 出力
x=            err=        
3.3600000000, 1.6400000000
2.2990513983, 1.0609486017
1.6588288946, 0.6402225037
1.3481592314, 0.3106696633
1.2655703161, 0.0825889153
1.2599462296, 0.0056240865
1.2599210504, 0.0000251792
1.2599210499, 0.0000000005
*/