// 学籍番号　B2190350
// 名前　　　大森裕介

#include <stdio.h>   // 標準入出力のプロトタイプ宣言
#include <stdlib.h>  // 標準ライブラリのプロトタイプ宣言
#include <math.h>    // 数学関数のプロトタイプ宣言

//Complex型の定義
typedef struct{
  double re;
  double im;
} Complex;

Complex f(Complex);   //関数f(x)のプロトタイプ宣言
Complex df(Complex);  //導関数f'(x)のプロトタイプ宣言
Complex cadd(Complex, Complex); //加算のプロトタイプ宣言
Complex csub(Complex, Complex); //減算のプロトタイプ宣言
Complex cmul(Complex, Complex); //乗算のプロトタイプ宣言
Complex cdiv(Complex, Complex); //除算のプロトタイプ宣言

int main()
{
  Complex z,w,u;
  double eps=0.001;
  double err=1.0;

  z.re=1.0;  // Re(z)=1.0
  z.im=5.17; // Im(z)=5.17

  printf("z=                     err=\n");  //zとerrのラベル表示
  while(err>eps){       // err>epsの間繰り返し
    w=cdiv(f(z),df(z)); // w=f(z)/f'(z)
    w = csub(z,w);//(your code)        // wをz-w=z-f(z)/f'(z)で更新
    u=csub(w,z);        // u=w-z (u=z_{n+1}-z_n)
    err = sqrt(u.re*u.re+u.im*u.im);//(your code)  // err=|z_{n+1}-z_n|
    printf("%lf + %lf i  %f\n", w.re, w.im, err); // 出力
    z=w;                // zをw=z-f(z)/f'(z)で更新
  }
}


Complex f(Complex z)
{
  Complex w,u;

  u.re=1.0; //Re(u)=1.0
  u.im=0;   //Re(u)=0
  
  w=cmul(z,z); //w=z*z
  w = cmul(w,z);//(your code) //wをw*z=z*z*zで更新
  w = csub(w,u);//(your code) //wをw-u=z*z*z-1で更新

  return(w); //w=z*z*z-1を返す

}

Complex df(Complex z)
{

  Complex w,u;

  u.re=3.0;  //Re(u)=3.0
  u.im=0;    //Im(u)=0
  
  w=cmul(z,z); //w=z*z
  w = cmul(u,w);//(your code)) //wをu*w=3*z*zで更新

  return(w);  //w=3*z*zを返す

}


Complex cadd(Complex z1, Complex z2)
{
  Complex z;
  z.re=z1.re+z2.re;
  z.im=z1.im+z2.im;
  return(z);
}

Complex csub(Complex z1, Complex z2)
{
  Complex z;
  z.re=z1.re-z2.re;
  z.im=z1.im-z2.im;
  return(z);
}

Complex cmul(Complex z1, Complex z2)
{
  Complex z;
  z.re=z1.re*z2.re-z1.im*z2.im;
  z.im=z1.re*z2.im+z1.im*z2.re;
  return(z);
}

Complex cdiv(Complex x, Complex y)
{
  Complex z;
  if((y.re==0)&&(y.im==0)){
    z.re=0;
    z.im=0;
    return z;         
  }
  else{
    z.re = (x.re*y.re +x.im*y.im)/(y.re*y.re+y.im*y.im);  
    z.im = (-x.re*y.im +x.im*y.re)/(y.re*y.re+y.im*y.im); 
    return z;                                             
  }
}

/* 出力
z=                     err=
0.655513 + 3.442184 i  1.761823
0.411760 + 2.284811 i  1.182762
0.216554 + 1.501618 i  0.807154
0.005453 + 0.960161 i  0.581154
-0.357899 + 0.636000 i  0.486933
-0.563419 + 0.958988 i  0.382830
-0.506779 + 0.874692 i  0.101557
-0.500086 + 0.866108 i  0.010885
-0.500000 + 0.866025 i  0.000119
*/