// 学籍番号　B2190350
// 名前　　　大森裕介

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
    if( f(t)>0 /*(your code)*/) b=t;      // 新しいbの値としてtをとる
    else if( f(t)<0 /*(your code)*/) a=t; // 新しいaの値としてtをとる
    else break; // どちらでもない場合、f(t)=0なので繰り返し終了
    //(your code)     // 新しいerrの値を更新
    err=b-a;
    printf("err:%lf, %lf<c<%lf\n", err,a,b);// 結果出力
  }     
}


double f(double x){
  return(x*x*x-2.0); // 使用した関数f(x)の定義
}

/* 出力
err:5.000000, 0.000000<c<5.000000
err:2.500000, 0.000000<c<2.500000
err:1.250000, 1.250000<c<2.500000
err:0.625000, 1.250000<c<1.875000
err:0.312500, 1.250000<c<1.562500
err:0.156250, 1.250000<c<1.406250
err:0.078125, 1.250000<c<1.328125
err:0.039062, 1.250000<c<1.289062
err:0.019531, 1.250000<c<1.269531
err:0.009766, 1.259766<c<1.269531
err:0.004883, 1.259766<c<1.264648
err:0.002441, 1.259766<c<1.262207
err:0.001221, 1.259766<c<1.260986
err:0.000610, 1.259766<c<1.260376
err:0.000305, 1.259766<c<1.260071
err:0.000153, 1.259918<c<1.260071
err:0.000076, 1.259918<c<1.259995
*/