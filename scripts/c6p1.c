// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

typedef struct{  //
  double re;     //
  double im;     //
} Complex;       //

Complex cadd(Complex, Complex); // 複素数の和を返す関数のプロトタイプ宣言
Complex csub(Complex, Complex); // 複素数の差を返す関数のプロトタイプ宣言
Complex cmul(Complex, Complex); // 複素数の積を返す関数のプロトタイプ宣言
Complex cdiv(Complex, Complex); // 複素数の商を返す関数のプロトタイプ宣言

int main(){
  Complex z1={1.0, 2.0};// 複素数型の変数z1=1+2iを定義
  Complex z2,z3,z4,z5,z6;  // 複素数型の変数を定義
  z2.re = 3.0; // z2の実部z.reを3.0で初期化
  z2.im = 4.0; // z2の虚部z.reを4.0で初期化

  z3 = cadd(z1, z2); //(your code)  //z3=z1+z2
  z4 = csub(z1, z2); //(your code)  //z4=z1-z2
  z5 = cmul(z1, z2); //(your code)  //z5=z1*z2
  z6 = cdiv(z1, z2); //(your code)  //z6=z1/z2

  //結果出力
  printf("z1= %lf + %lf i\n", z1.re, z1.im);
  printf("z2= %lf + %lf i\n", z2.re, z2.im);
  printf("z1+z2= %lf + %lf i\n", z3.re, z3.im);
  printf("z1-z2= %lf + %lf i\n", z4.re, z4.im);
  printf("z1*z2= %lf + %lf i\n", z5.re, z5.im);
  printf("z1/z2= %lf + %lf i\n", z6.re, z6.im);
      
}


Complex cadd(Complex x, Complex y)
{

  Complex z;
  z.re = x.re + y.re; // zの実部はRe(x)+Re(y)
  z.im = x.im + y.im; // zの虚部はIm(x)+Im(y)
  return z;           // z=x+yを返す
  
}


Complex csub(Complex x, Complex y)
{
  
  Complex z;
  z.re = x.re - y.re; // zの実部はRe(x)-Re(y)
  z.im = x.im - y.im; // zの虚部はIm(x)-Im(y)
  return z;           // z=x-yを返す

}


Complex cmul(Complex x, Complex y)
{

  Complex z;
  z.re = x.re * y.re - x.im * y.im; //(your code)   // xyの実部
  z.im = x.re * y.im + x.im * y.re; //(your code)   // xyの虚部
  return z;         // z=xyを返す

}


Complex cdiv(Complex x, Complex y)
{
  
  Complex z;
  if((y.re==0)&&(y.im==0)){
    z.re=0;
    z.im=0;
    return z;      //y＝0で0を返す
  }
  else{
    z.re = (x.re * y.re + x.im * y.im)/(y.re * y.re + y.im * y.im); //(your code)   // x/yの実部
    z.im = (-x.re * y.im + x.im * y.re)/(y.re * y.re + y.im * y.im); //(your code)   // x/yの虚部
    return z;       // z=x/yを返す                                       
  }

}

/* 出力
z1= 1.000000 + 2.000000 i
z2= 3.000000 + 4.000000 i
z1+z2= 4.000000 + 6.000000 i
z1-z2= -2.000000 + -2.000000 i
z1*z2= -5.000000 + 10.000000 i
z1/z2= 0.440000 + 0.080000 i
*/