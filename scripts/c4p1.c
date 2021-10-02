#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

double f(double);    // 作成する関数をプロトタイプ宣言

int main(){

  double eps=0.0001;    // 誤差eps
  double a=0.0, b=10.0; // 閉区間 [a,b]
  double err=b-a;       //
  double t=0;           //a,bの中点t


  while(err>eps){     // err>epsの場合、繰り返し
    t=(b+a)/2;        // a,bの中点の値を変数tに代入
    if( t>0 /*(your code)*/) b=t;      // 新しいbの値としてtをとる
    else if( t<0 /*(your code)*/) a=t; // 新しいaの値としてtをとる
    else break; // どちらでもない場合、f(t)=0なので繰り返し終了
    //(your code)     // 新しいerrの値を更新
    err=t;
    printf("err:%lf, %lf<c<%lf\n", err,a,b);// 結果出力
  }     
}


double f(double x){
  return(x*x*x-2.0); // 使用した関数f(x)の定義
}

